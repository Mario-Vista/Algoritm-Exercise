#include <iostream>
#include <fstream>
#include "Abr.h"

using namespace std;

int main()
{
	int num;
	Abr<int> abr;

	ifstream iFile("input.txt");

	while(iFile>>num)
		abr.insert(num);

	cout << abr.maximum() << endl;
	cout << abr.minimum() << endl;
	abr.inOrderVisit();
}