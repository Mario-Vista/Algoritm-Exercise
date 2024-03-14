#include <iostream>
#include <vector>
#include <string>
#include "MaxHeap.h"
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    string heap = "sort.txt";
    ifstream myFile(heap);

    if(!myFile.is_open())
    {
        cerr << "Error while opening file" << endl;
        return 1;
    }

    vector<int> vec;
    int num;

    while(myFile >> num){
        vec.push_back(num);
    }    
    myFile.close();

    cout << "Valori letti dal file" <<endl;
    for(auto i : vec)
        cout << i << endl;
    
    MaxHeap<int> tree = MaxHeap<int>(vec);
    tree.heapSort();
    cout << "HeapSort" << endl;
    tree.printTree();



}