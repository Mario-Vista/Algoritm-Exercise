#include <iostream>
#include <fstream>
#include "Abr.h"
#include "Nodo.h"

using namespace std;

int main()
{
	ifstream iFile("input.txt");
	int value;
	Abr<int> abr;

	while(iFile>>value)
		abr.insert(value);


	cout << "massimo: " << abr.maximum() << endl;
	cout << "minimo: " << abr.minimum() << endl;

	abr.inOrderVisit();

	cout << endl;

	abr.preOrderVisit();

	cout << endl;

	abr.postOrderVisit();


	return 0;
}