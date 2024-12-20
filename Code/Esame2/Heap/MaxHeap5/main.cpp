#include <iostream>
#include <fstream>
#include <vector>
#include "MaxHeap.h"

using namespace std;

int main()
{
    vector<int> num;
    int numbers;
    ifstream iFile("input.txt");

    while(iFile >> numbers)
        num.push_back(numbers);
    
    iFile.close();
    MaxHeap<int> heap(&num);
    heap.printTree();
    heap.heapSort();
    heap.printTree();
}