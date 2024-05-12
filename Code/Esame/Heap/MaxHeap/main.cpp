#include "MaxHeap.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string input = "input.txt";
	ifstream file;
	file.open(input);

	vector<int> numbers;
	int num;
	while(file >> num)
		numbers.push_back(num);
	file.close();
	MaxHeap<int> heap(numbers);
	for(auto i : numbers)
		cout << i << endl;

	heap.printTree();

	heap.heapSort();

	heap.printTree();
}