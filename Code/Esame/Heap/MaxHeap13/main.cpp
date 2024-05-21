#include <iostream>
#include <vector>
#include <fstream>
#include "MaxHeap.h"

using namespace std;

int main()
{
	ifstream iFile("input.txt");
	vector<T> numbers;
	int num;

	while(iFile >> num)
		numbers.push_back(num);
	iFile.close();

	MaxHeap<int> heap(&numbers);

	heap.printTree();
	heap.heapSort();
	heap.printTree();
}
