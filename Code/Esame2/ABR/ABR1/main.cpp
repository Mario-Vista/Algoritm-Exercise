#include <iostream>
#include <fstream>
#include "Abr.h"

using namespace std;

int main()
{
    Abr<int> abr;

    ifstream iFile("input.txt");
    int value;

    while(iFile >> value)
        abr.insert(value);
    iFile.close();

    if(abr.getRoot() == nullptr)
    {
        cerr << "nessun nodo presente";
        return -1;
    }

    abr.preOrder();
    cout << "Visita stampata" << endl;
    return 0;
}