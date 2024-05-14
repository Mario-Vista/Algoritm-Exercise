#include <iostream>
#include <fstream>
#include <string>
#include "MaxHeap.h"

using namespace std;

int main()
{
	vector<int> numbers;
	int num;

	ifstream iFile("input.txt");

	while(iFile>>num)
		numbers.push_back(num);

	MaxHeap<int> heap(&numbers);

	heap.printTree();
	heap.heapSort();
	heap.printTree();



	return 0;
}