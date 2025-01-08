#include <iostream>
#include <fstream>
#include <vector>
#include "MaxHeap.h"

using namespace std;

int main()
{
    int num;
    vector<int> numbers;
    ifstream iFile("input.txt");

    while(iFile >> num)
        numbers.push_back(num);
    
    MaxHeap<int> heap(&numbers);

    heap.printToFile("output.txt");
}