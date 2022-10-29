#include <iostream>
#include <iomanip>

using namespace std;

template <typename Type>
bool equal(Type a, Type b) {
    cout << "Generic func" << endl;
}

bool equal(double a, double b) {
    cout << setprecision(6) << "Specialized function: " << "a: " << a << ", b: " << b << endl;
    return abs(a-b) < 0.00001;
}

int main() {
    double a1 = 0.123456;
    double b1 = 0.123457; // Should not be so different from a1, and make function return 1
    double b0 = 0.345678; // Should be too different from a1, and make function return 0

    cout << "Function should return 1: " << equal(a1, b1) << endl;
    cout << "Function should return 0: " << equal(a1, b0) << endl;
    cout << "Function should return 1: " << equal(a1, b1) << endl;
    cout << "Function should return 0: " << equal(a1, b0) << endl;

    cout << "String attempt: " << equal("Hello", "Hello") << endl;
    cout << "Char attempt: " << equal('=', '=') << endl;
    return 0;
}
