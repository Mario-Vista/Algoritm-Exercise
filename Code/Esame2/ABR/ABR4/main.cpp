#include <iostream>
#include <fstream>
#include "Abr.h"

using namespace std;

int main()
{
    ifstream iFile("input.txt");
    int num;
    Abr<int> abr;
    while(iFile >> num)
        abr.insert(num);
    abr.inOrderVisit();
    cout << endl;
}