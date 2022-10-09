#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class ChessBoard {
public:
    enum class Color { WHITE,
        BLACK };

    class Piece {
    public:
        explicit Piece(Color color) : color(color) {}
        virtual ~Piece() = default;

        Color color;
        std::string color_string() const {
            if (color == Color::WHITE)
                return "white";
            else
                return "black";
        }

        virtual std::string print() const = 0;

        /// Return color and type of the chess piece
        virtual std::string type() const = 0;

        /// Returns true if the given chess piece move is valid
        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;

        virtual string text_desc() const = 0;
    };

    class King : public Piece {
    public:
        explicit King(Color color_): Piece(color_) {};
        std::string type() const override {
            std::string color_string = (color == Color::WHITE) ? "white" : "black";
            return color_string + " king";
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override{
            int abs_x = abs(from_x - to_x);
            int abs_y = abs(from_y - to_y);
            if(abs_x == 1 || abs_y == 1) return true;
            return false;
        }

        virtual std::string print() const override {
            std::string color(1, this->color_string()[0]);
            return color +"K";
        }
        string text_desc() const
        {
            return (color == Color::WHITE) ? "K" : "K";
        };
    };

    class Knight : public Piece {
    public:
        explicit Knight(Color color_): Piece(color_) {};
        std::string type() const override {
            std::string color_string = (color == Color::WHITE) ? "white" : "black";
            return color_string + " knight";
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override{
            int abs_x = abs(from_x - to_x);
            int abs_y = abs(from_y - to_y);
            if(abs_x == 1 && abs_y == 2) return true;
            if(abs_x == 2 && abs_y == 1) return true;
            return false;
        }

        virtual std::string print() const override {
            std::string color(1, this->color_string()[0]);
            return color +"N";
        }
        string text_desc() const
        {
            return (color == Color::WHITE) ? "N" : "N";
        };
    };

    ChessBoard() {
        // Initialize the squares stored in 8 columns and 8 rows:
        squares.resize(8);
        for (auto &square_column : squares)
            square_column.resize(8);
    }

    function<void(const ChessBoard &chessboard)> after_movement;
    function<void(const Piece &piece, const string &from, const string &to)> on_movement;
    function<void(const Piece &piece, const string &square)> on_removed;
    function<void(Color color)> on_lost;
    function<void(const Piece &piece, const string &from, const string &to)> on_move_invalid;
    function<void(const string &square)> on_move_missing;


    /// 8x8 squares occupied by 1 or 0 chess pieces
    vector<vector<unique_ptr<Piece>>> squares;

    /// Move a chess piece if it is a valid move.
    /// Does not test for check or checkmate.
    bool move_piece(const std::string &from, const std::string &to) {
        int from_x = from[0] - 'a';
        int from_y = stoi(string() + from[1]) - 1;
        int to_x = to[0] - 'a';
        int to_y = stoi(string() + to[1]) - 1;

        auto &piece_from = squares[from_x][from_y];
        if (piece_from) {
            if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
                if(on_movement) {
                    on_movement(*piece_from, from, to);
                }
                auto &piece_to = squares[to_x][to_y];
                if (piece_to) {
                    if(piece_from->color != piece_to->color) {
                        if(on_removed) {
                            on_removed(*piece_to, to);
                        }
                        if(auto king = dynamic_cast<King *>(piece_to.get())) {
                            if(on_lost) {
                                on_lost(king->color);
                            }
                        }
                    }
                    else {
                        if(on_move_invalid) {
                            on_move_invalid(*piece_from, from, to);
                        }
                        return false;
                    }
                }
                piece_to = move(piece_from);
                if(after_movement) {
                    after_movement(*this);
                }
                return true;
            } else {
                on_move_invalid(*piece_from, from, to);
                return false;
            }
        } else {
            if(on_move_missing) {
                on_move_missing(from);
            }
            return false;
        }
    }

    friend ostream &operator<<(ostream &os, const ChessBoard &chess_board)
    {
        for (int row = 7; row >= 0; row--)
        {
            os << to_string(row + 1) << " ";
            for (int col = 0; col < 8; col++)
            {
                auto &piece = chess_board.squares[col][row];
                os << (piece ? piece->text_desc() + " " : "- ");
            }
            os << "\n";
        }
        os << "  a b c d e f g h";
        return os;
    }
};

class ChessBoardPrint {
public:
    ChessBoardPrint(ChessBoard &chessBoard) {
        chessBoard.on_movement = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
            cout << piece.type() << " is moving from " << from << " to " << to << endl;
        };
        chessBoard.on_removed = [](const ChessBoard::Piece &piece, const string &square) {
            cout << piece.type() << " is being removed from " << square << endl;
        };
        chessBoard.on_move_invalid = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
            cout << "Can not move " << piece.type() << " from " << from << " to " << to << ": MOVE INVALID" << endl;
        };
        chessBoard.on_move_missing = [](const string &square) {
            cout << "No piece at " << square << " to move: MOVE MISSING" << endl;
        };
        chessBoard.after_movement = [](const ChessBoard &chessBoard) {
            cout << chessBoard << endl;
        };
        chessBoard.on_lost = [](const ChessBoard::Color color) {
            if(color == ChessBoard::Color::BLACK) {
                cout << "White ";
            } else cout << "Black ";
            cout << "has won the game." << endl;
        };
    }
};

int main() {
    ChessBoard board;
    ChessBoardPrint print(board);

    board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
    board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
    board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

    board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
    board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
    board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

    board.move_piece("e1", "e2");
    board.move_piece("g8", "h6");
    board.move_piece("b1", "c3");
    board.move_piece("h6", "g8");
    board.move_piece("c3", "d5");
    board.move_piece("g8", "h6");
    board.move_piece("d5", "f6");
    board.move_piece("h6", "g8");
    board.move_piece("f6", "e8");
    cout << "-------------------------------------------------" << endl;

    cout << "Invalid moves:" << endl;
    board.move_piece("e3", "e2");
    board.move_piece("e1", "e3");
    board.move_piece("b1", "b2");

    return 0;
}