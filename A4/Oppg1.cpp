#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<double> numbers;
    for(int i = 1; i < 6; i++) numbers.emplace_back(i);
    cout << "Første tall: " << numbers.front() << ", Andre tall: " << numbers.back() << endl;

    numbers.emplace(numbers.begin() + 1, 0.5);
    cout << "Første tall: " << numbers.front() << endl;
    cout << "Andre tall: " << numbers[1] << endl;

    auto iterator= find(numbers.begin(), numbers.end(), 3);
    if(iterator != numbers.end()) cout << "The value is found, and it is: " << *iterator << endl;
    else cout << "Value not found.." << endl;

    return 0;
}
