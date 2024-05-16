#include <iostream>
#include <fstream>
#include <vector>
#include "MaxHeap.h"

using namespace std;

int main()
{
	ifstream iFile("input.txt");
	vector<int> numbers;
	int num;

	while(iFile>>num)
		numbers.push_back(num);

	MaxHeap<int> heap(&numbers);

	heap.printTree();
	heap.heapSort();
	heap.printTree();




	return 0;
}