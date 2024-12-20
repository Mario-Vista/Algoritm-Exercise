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

    MaxHeap<int> heap(&num);

    heap.heapSort();
    heap.printToFile("output.txt");


}