#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &broek) {
    cout << text << broek.numerator << " / " << broek.denominator << endl;
}

int main() {
    Fraction a(10, 20);
    Fraction b(3, 4);
    Fraction c;
    c.set(5);
    Fraction d = a / b;

    print("a = ", a);
    print("b = ", b);
    print("c = ", c);
    print("d = ", d);

    b += a;
    ++c;
    d *= d;

    print("b = ", b);
    print("c = ", c);
    print("d = ", d);

    c = a + b - d * a;
    c = -c;

    print("c = ", c);

    if (a + b != c + d)
        cout << "a + b != c + d" << endl;
    else
        cout << " a + b == c + d" << endl;
    while (b > a)
        b -= a;
    print("b = ", b);

    Fraction fraction1(3, 4);
    print("Fraction 1 = ", fraction1);
    print("Fraction 1 - 5 = ", fraction1 - 5);
    print("5 - Fraction 1 = ", 5 - fraction1);
}

/*
 * Oppgave b:
 *
 * 1. 5 - 3 = Operator-(int, int);
 * 2. 2 - fraction1 = operator-(int, &fraction);
 * 3. (2 - fraction1) - 7 = fraction1.operator-(int);
 * 4. ((2 - fraction1) - 7) - fraction2 ) = fraction1.operator-(&fraction);
 */
