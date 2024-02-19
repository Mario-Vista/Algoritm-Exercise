#include <iostream>
#include "MaxHeap.h"

int main() {
    MaxHeap<int> maxHeap;

    // Inserimento di alcuni elementi nell'heap
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(30);
    maxHeap.insert(5);

    // Stampa dell'heap
    maxHeap.print();

    // Stampa dell'heap in formato ASCII
    maxHeap.printAsciiTree();

    return 0;
}
