#include <iostream>
#include <fstream>
#include <vector>
#include "MaxHeap.h"

using namespace std;

int main()
{
	ifstream inputFile("input.txt");
	vector<int> numbers;
	int num;
	while(inputFile >> num)
	{
		numbers.push_back(num);
	}

	inputFile.close();
	MaxHeap<int> heap(&numbers);
	heap.printTree();
	heap.heapSort();
	heap.printTree();




}