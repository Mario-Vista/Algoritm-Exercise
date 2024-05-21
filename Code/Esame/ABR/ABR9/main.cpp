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

	iFile.close();

	cout << "Massimo: " << abr.maximum() << endl;

	cout << "Minimo: " << abr.minimum() << endl;


	abr.inOrderVisit();

	return 0;
}