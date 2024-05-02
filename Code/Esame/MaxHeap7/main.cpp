#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "MaxHeap.h"

using namespace std;

int main()
{
	vector<int> nums;

	ifstream inputFile("input.txt");
	if(!inputFile)
	{
		cerr << "Error while open input File" << endl;
		return 1;
	}

	int num;

	while(inputFile>>num)
	{
		nums.push_back(num);
	}
	inputFile.close();
	MaxHeap<int> heap(&nums);

	cout << "not sorted" << endl;
	heap.printTree();

	heap.heapSort();

	cout << "sorted" << endl;
	heap.printTree();


return 0;

}