#include <iostream>
#include <fstream>
#include <vector>
#include "MaxHeap.h"

using namespace std;

int main()
{
    ifstream iFile("input.txt");
    vector<int> num;
    int number;

    while(iFile >> number)
        num.push_back(number);
    
    iFile.close();
    MaxHeap<int> heap(&num);
    heap.printTree();
    heap.heapSort();
    heap.printTree();
}