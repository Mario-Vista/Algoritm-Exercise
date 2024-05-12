#include "MaxHeap.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string input = "fileInput.txt";
    ifstream file;
    file.open(input);

    if (!file.is_open()) {
    cerr << "Impossibile aprire il file." << endl;
    return 1; // Uscita con codice di errore
    }

    vector<int> numbers;
    int num;
    while(file>>num)
        numbers.push_back(num);
    file.close();

    MaxHeap<int> myHeap(&numbers);

    cout <<"Pre Sort"<<endl;
    myHeap.printTree();

    myHeap.heapSort();
    cout << endl << "post sort" << endl;
    myHeap.printTree();

    return 0;
}