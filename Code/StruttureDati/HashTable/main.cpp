#include <iostream>
#include <vector>
#include "HashTable.h"

int main() {
    HashTable<int> table(10);
    table.insert(1, 100);
    table.insert(11, 200);
    table.insert(21, 300);
    std::cout << table.get(11) << std::endl;
    return 0;
}