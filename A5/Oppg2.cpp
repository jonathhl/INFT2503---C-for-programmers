#include <iostream>
#include <memory>
#include <string>
#include <vector>

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

    };

    ChessBoard() {
        // Initialize the squares stored in 8 columns and 8 rows:
        squares.resize(8);
        for (auto &square_column : squares)
            square_column.resize(8);
    }

    /// 8x8 squares occupied by 1 or 0 chess pieces
    vector<vector<unique_ptr<Piece>>> squares;

    void print() {
        for (size_t i = squares.size() - 1; i + 1 > 0; i--) {
            cout << "  " << i + 1 << " ";
            for (size_t j = 0; j < squares.at(i).size(); j++) {
                if (!squares.at(j).at(i)) {
                    cout << "  - ";
                } else {
                    auto &piece = squares.at(j).at(i);
                    cout << " " << piece->print() << " ";
                }
            }
            cout << endl;
        }
        cout << "      A   B   C   D   E   F   G   H\n" << endl;
    }

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
                cout << piece_from->type() << " is moving from " << from << " to " << to << endl;
                auto &piece_to = squares[to_x][to_y];
                if (piece_to) {
                    if (piece_from->color != piece_to->color) {
                        cout << piece_to->type() << " is being removed from " << to << endl;
                        if (auto king = dynamic_cast<King *>(piece_to.get()))
                            cout << king->color_string() << " lost the game" << endl;
                    } else {
                        // piece in the from square has the same color as the piece in the to square
                        cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
                        return false;
                    }
                }
                piece_to = move(piece_from);
                return true;
            } else {
                cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
                return false;
            }
        } else {
            cout << "no piece at " << from << endl;
            return false;
        }
    }
};

int main() {
    ChessBoard board;

    board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
    board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
    board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

    board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
    board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
    board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

    cout << "Invalid moves:" << endl;
    board.move_piece("e3", "e2");
    board.move_piece("e1", "e3");
    board.move_piece("b1", "b2");
    cout << endl;

    cout << "A simulated game:" << endl;
    board.print();
    board.move_piece("e1", "e2");
    board.print();
    board.move_piece("g8", "h6");
    board.print();
    board.move_piece("b1", "c3");
    board.print();
    board.move_piece("h6", "g8");
    board.print();
    board.move_piece("c3", "d5");
    board.print();
    board.move_piece("g8", "h6");
    board.print();
    board.move_piece("d5", "f6");
    board.print();
    board.move_piece("h6", "g8");
    board.print();
    board.move_piece("f6", "e8");
    board.print();

    return 0;
}