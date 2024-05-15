#include <iostream>
#include <fstream>
#include "Abr.h"
#include "Nodo.h"

using namespace std;

int main()
{
	ifstream iFile("input.txt");
	Abr<int> abr;
	int num;
	while(iFile>>num)
		abr.insert(num);

	cout << "Massimo: " << abr.maximum() << endl;
	cout << "Minimo: " << abr.minimum() << endl;
	cout << "PreOrder: " << endl;
	abr.preOrderVisit();

		cout << endl << "PostOrder: " << endl;
	abr.postOrderVisit();

		cout << endl << "inOrder: " << endl;
	abr.inOrderVisit();


}