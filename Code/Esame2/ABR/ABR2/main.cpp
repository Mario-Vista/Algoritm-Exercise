#include <iostream>
#include "Abr.h"

using namespace std;

int main()
{
    Abr<int> abr;
    int num;
    ifstream iFile("input.txt");

    while(iFile>>num)
    {
        abr.insert(num);
    }

    iFile.close();

    cout << "max: " << abr.maximum() << endl;
    cout << "min: " << abr.minimum() << endl;
    cout << "pre: ";
    abr.preOrderVisit();
    cout << " in: ";
    abr.inOrderVisit();
    cout << " post: ";
    abr.postOrderVisit();
}
