#include <fstream>
#include <iostream>

using namespace std;

void read_temperatures(double temperatures[], int length);

int main() {
  int length = 10;
  double temperatures[length];
  int BELOW_10 = 0;
  int BETWEEN = 0;
  int ABOVE_20 = 0;

  read_temperatures(temperatures, length);

  for (int i = 0; i < length; i++) {
    cout << "Temperatur nr " << i + 1 << ": " << temperatures[i] << endl;

    if (temperatures[i] < 10)
      BELOW_10++;
    else if (temperatures[i] >= 10 && temperatures[i] <= 20)
      BETWEEN++;
    else
      ABOVE_20++;
  }

  cout << "Antall under 10 er: " << BELOW_10 << endl;
  cout << "Antall mellom eller lik 10 og 20 er: " << BETWEEN << endl;
  cout << "Antall over 20 er: " << ABOVE_20 << endl;

  return 0;
}

void read_temperatures(double temperatures[], int length) {
  ifstream file("/home/jonathan/Documents/INFT2503/A1/temps");

  if (!file) {
    cout << "ERROR: File could not be opened.." << endl;
    exit(1);
  }

  for (int i = 0; i < length; i++) {
    double temp;
    file >> temp;
    temperatures[i] = temp;
  }
}