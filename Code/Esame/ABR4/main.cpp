#include <iostream>
#include <fstream>
#include "Abr.h"

using namespace std;

int main()
{
	Abr<int> abr;
	int num;
	ifstream inputFile("input.txt");

	while(inputFile >> num)
		abr.insert(num);

	inputFile.close();

	cout << "Massimo " << abr.maximum() << endl;
	cout << "Minimo " << abr.minimum() << endl;

	cout << "Preorder" << endl;
	abr.preOrderVisit();
	cout << endl <<  "Inorder" << endl;
	abr.inOrderVisit();
	cout << endl << "Postorder" << endl;
	abr.postOrderVisit();

}