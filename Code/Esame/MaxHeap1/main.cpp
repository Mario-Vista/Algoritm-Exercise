#include <iostream>
#include <vector>
#include <string>
#include "MaxHeap.h"
#include <fstream>

using namespace std;

int main()
{
    string heap = "sort.txt";
    ifstream myFile(heap); // Utilizzo ifstream diretto, non c'è bisogno di convertirlo in c-string

    if (!myFile.is_open()) {
        cerr << "Errore nell'apertura del file " << heap << endl;
        return 1;
    }

    vector<int> vec;
    int num;

    while (myFile >> num) { // Legge direttamente l'intero dal file
        vec.push_back(num);
    }

    myFile.close();

    cout << "Valori letti dal file:" << endl;
    for (auto i : vec)
        cout << i << endl;

    cout << endl << "File ordinato: " << endl;
    MaxHeap<int> tree = MaxHeap<int>(vec);
    tree.heapSort();
    tree.print();
    tree.printAsciiTree();

    return 0;
}
