#include <iostream>
#include <vector>
#include <fstream>
#include "MaxHeap.h"

using namespace std;

int main()
{
    ifstream iFile("input.txt");
    int num;
    vector<int> vec;
    while(iFile>>num)
        vec.push_back(num);
    MaxHeap<int> heap(&vec);
        
    cout << endl;
    heap.heapSort();
    heap.printTree();
}