#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &table) {
    for (auto &e : table)
        out << e << " ";
    return out;
}

int main() {
    vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
    cout << "v1: " << v1 << endl;
    vector<int> v2 = {2, 3, 12, 14, 24};
    cout << "v2: " << v2 << endl;

    cout << endl << "Task a" << endl;
    auto pos = find_if(v1.begin(), v1.end(), [](int x) {
        return x > 15;
    });

    if(pos != v1.end()) {
        cout << "First value greater than 15 is in index: " << (pos - v1.begin());
        cout << " and has a value of " << *pos << endl;
    }


    cout << endl << "Task b" << endl;
    if(equal(v1.begin(), v1.end() + 5, v2.data()), [](int x, int y){
        return abs(x-y) <= 2;
    }) cout << "This looks about equal.." << endl;
    else cout << "This does not look equal.." << endl;

    // I can try other variants to play around, but the code will just be copy paste... I'll just comment it out
    /*
    if(equal(v1.begin(), v1.end() + 4, v2.data()), [](int x, int y){
        return abs(x-y) <= 2;
    }) cout << "This looks about equal.." << endl;
    else cout << "This does not look equal.." << endl;
     */


    cout << endl << "Task c" << endl;
    cout << "v1 before replacement: " << v1 << endl;
    auto replace = replace_copy_if(v1.begin(), v1.end(), v1.begin(), [](int x){
        return x%2 != 0;
    }, 100);

    cout << "Replacing all odd numbers with 100..." << endl;
    cout << "v1 after replacement: " << v1 << endl;

    return 0;
}
