#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;
    
    
    cout << "Oppgave 1a: " << endl;
    cout << "Henholdsvis verdi og adresse for i: " << i << ", " << &i << endl;
    cout << "Henholdsvis verdi og adresse for j: " << j << ", " << &j << endl;
    cout << "Henholdsvis verdi og adresse for *p: " << *p << ", " << &p << endl;
    cout << "Henholdsvis verdi og adresse for *q: " << *q << ", " << &q << endl;
    cout << "---------------------------------------------------" << endl; // 
    cout << "Oppgave 1b: " << endl;
    *p = 7; 
    *q += 4; // *q = 9, *p = 7
    *q = *p + 1; // *q = 8, *p = 7
    p = q; // *q = 8, *p = 8
    cout << *p << ", " << *q << endl;
    
    return 0;
}
