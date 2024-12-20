#include <iostream>
#include <fstream>
#include <vector>
#include "MaxHeap.h"

using namespace std;

int main()
{
    vector<int> num;
    int number;
    ifstream iFile ("input.txt");

    while(iFile >> number)
        num.push_back(number);

    iFile.close();

    MaxHeap<int> heap(&num);

    heap.printTree();
    heap.heapSort();
    heap.printTree();


}