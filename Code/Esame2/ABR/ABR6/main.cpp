#include <iostream>
#include <fstream>
#include "Abr.h"

using namespace std;

int main()
{
    ifstream iFile("input.txt");
    Abr<int> abr;
    int num;

    while(iFile >> num)
        abr.insert(num);

    abr.inOrderVisit();
    cout << endl;

    abr.preOrderVisit();
    cout << endl;

    abr.postOrderVisit();
    cout << endl;
}