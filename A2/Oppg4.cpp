#include <iostream>

using namespace std;

int main() {
    int a = 5; // Ingen feil på denne linjen
    int &b = a; // Variabelen må bli initialisert, den kan ikke stå som int &b;
    int *c;
    c = &b;
    a = b + *c; // Her er *c en verdi, da c settes som c = &b (&b er en adresse, se forrige linje)
    b = 2; // Krever verdi her og ikke adresse. &b = 2;
    
    cout << a << ", " << b << ", " << c << endl;
    // Til slutt blir alt kompilert, a blir definert som en verdi i starten, b blir definert som verdi = 2 helt til slutt,
    // og c blir definert som en adresse på linje 9. Grunnen til alle feil utenom linje 7 kommer fra at variablene må stemme.
    // Det kan ikke være miks mellom verdi og adresse.
    
    return 0;
}
