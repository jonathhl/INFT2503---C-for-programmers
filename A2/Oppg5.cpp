#include <iostream>

using namespace std;

int main() {
  double number;
  double *pointer = &number;
  double &reference = number;
  
  // Metode 1: Printer ut nummer som normalt.
  number = 0.5;
  cout << number << endl;
  
  // Metode 2: Setter verdien via pointeren, og printer ut nummer.
  *pointer = 1.0;
  cout << number << endl;
  
  // Metode 3: Setter verdien via referansevariabelen og printer ut nummer.
  reference = 1.5;
  cout << number << endl;
  
  return 0;
}
