#include <iostream>
#include "Abr.h"
#include <fstream>

using namespace std;

int main()
{
    Abr<int> abr;
    int num;
    ifstream iFile("input.txt");

    while(iFile >> num)
        abr.insert(num);

    abr.inOrderVisit();
    cout << endl;
    cout << abr.maximum() << endl;
    cout << abr.minimum() << endl;
}