#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

class Set {

    bool number_exists(int number) const;

public:
    std::vector<int> table;
    Set();
    Set &operator<<(const Set &set);
    Set &operator+=(int number);
    Set &operator=(const Set &set);
    friend std::ostream &operator<<(std::ostream &os, const Set &set);
};

Set::Set(){};

bool Set::number_exists(int number) const {
    for(int table_num : table) {
        if(table_num == number) return true;
    }
    return false;
}

Set &Set::operator<<(const Set &set) {
    for(int number : set.table) {
        if(!number_exists(number)) *this+=number;
    }
    return *this;
}

Set &Set::operator+=(int number) {
    if(!number_exists(number)) table.push_back(number);
    return *this;
}

Set &Set::operator=(const Set &set) {
    table = set.table;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Set &set) {
    os << "{ ";
    for(int i = 0; i < set.table.size() - 1; i++) os << set.table[i] << ", ";
    os << set.table[set.table.size() - 1];
    os << " }";
}