#include <iostream>
#include <vector>
#include <fstream>
#include "MaxHeap.h"

using namespace std;

int main()
{
	vector<int> numbers;
	int num;

	ifstream iFile("input.txt");

	while(iFile >> num)
		numbers.push_back(num);

	iFile.close();

	MaxHeap<int> heap(&numbers);

	cout << "*** UNSORTED MAX HEAP ***" << endl;
	heap.printTree();

	cout << endl;

	heap.heapSort();
	
	cout << "*** SORTED MAX HEAP ***" << endl;
	heap.printTree();


	return 0;
}

