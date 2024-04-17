#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "MaxHeap.h"

using namespace std;

int main(){

	string input = "fileInput.txt";
	ifstream file;
	file.open(input);

	if(!file.is_open())
	{
		cerr << "impossibile aprire il file" << endl;
		return 1;
	}

	vector<int> numbers;
	int num;

	while(file >> num)
		numbers.push_back(num);
	file.close();
	MaxHeap<int> heap(&numbers);

	cout << "preSort" << endl;
	heap.printTree();

	heap.heapSort();

	cout << "sorted" << endl;
	heap.printTree();



	return 0;
}

 
