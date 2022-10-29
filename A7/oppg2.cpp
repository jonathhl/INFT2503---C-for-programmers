#include "Set.hpp"
#include <iostream>

int main() {
    Set table1;
    table1+=1;
    table1+=4;
    table1+=7;
    std::cout << "Set 1: " << table1 << std::endl;

    Set table2;
    table2+=1;
    table2+=2;
    table2+=7;
    table2+=5;
    std::cout << "Set 2: " << table2 << std::endl;


    Set union_table;
    union_table = table1.operator<<(table2);
    std::cout << "Union of Set 1 and 2: " << std::endl;
    std::cout << union_table << std::endl;


    table2.operator+=(3);
    std::cout << "Set 2 with 3 added: " << table2 << std::endl;
    table2.operator+=(1);
    std::cout << "Set 2 with 1 tried added: " << table2 << std::endl;

    Set temp_table2;
    temp_table2.operator=(table2);
    std::cout << "Copied table: " << temp_table2 << std::endl;
    std::cout << "Original table: " << table2 << std::endl;

    return 0;
}
