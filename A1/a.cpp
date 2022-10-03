#include <iostream>

using namespace std;

int main() {
  const int length = 5;
  int BELOW_10 = 0;
  int BETWEEN = 0;
  int ABOVE_20 = 0;
  int temps[5];

  cout << "Du skal skrive inn 5 temperaturer" << endl;

  cout << "Temperatur 1: " << endl;
  cin >> temps[0];
  cout << "Temperatur 2: " << endl;
  cin >> temps[1];
  cout << "Temperatur 3: " << endl;
  cin >> temps[2];
  cout << "Temperatur 4: " << endl;
  cin >> temps[3];
  cout << "Temperatur 5: " << endl;
  cin >> temps[4];

  for (int i = 0; i < length; i++) {
    cout << "Temperatur nr " << i << ": " << temps[i] << endl;
    if (temps[i] < 10) {
      BELOW_10++;
    } else if (temps[i] >= 10 && temps[i] <= 20) {
      BETWEEN++;
    } else {
      ABOVE_20++;
    }
  }

  cout << "Antall under 10 er: " << BELOW_10 << endl;
  cout << "Antall mellom eller lik 10 og 20 er: " << BETWEEN << endl;
  cout << "Antall over 20 er: " << ABOVE_20 << endl;
}
