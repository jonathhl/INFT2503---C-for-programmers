#include <iostream>

using namespace std;

int find_sum(const int *table, int length) {
  int sum = 0;
  for(int i = 0; i < length; i++) {
    sum += *(table + i);
  }
  
  return sum;
}

int main() {
  const int length = 20;
  int table[length];
  
  for(int i = 0; i < length; i++) {
    table[i] = i + 1;
  }
  
  cout << "Summen av første 10: " << find_sum(table, 10) << endl;
  cout << "Summen for 5 neste: " << find_sum(&table[10], 5) << endl;
  cout << "Summen for 5 siste: " << find_sum(table + 15, 5) << endl;
  
  return 0;
}
