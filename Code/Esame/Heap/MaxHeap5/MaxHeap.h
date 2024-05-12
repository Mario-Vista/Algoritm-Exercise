#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <vector>


using namespace std;

template <class T>
class MaxHeap
{ 
	private:
		vector<T> *tree;
		int heapSize;

		int left(int i){return (2*i)+1;}
		int right(int i){return (2*i)+2;}
		int parent(int i){return (i-1)/2;}
		
		void buildMaxHeap();
		void maxHeapify(int i);
		void swap(T& a, T&b);
		void setHeapSize(int i){this->heapSize = i;}

	public:	
		MaxHeap(vector<T>*tree);
		void insert(T);
		void printTree();
		void heapSort();
};

template <class T>
MaxHeap<T> :: MaxHeap(vector<T>* tree)
{
	this->tree = tree;
	this->heapSize = tree->size();
	buildMaxHeap();
}

template <class T>
void MaxHeap<T> :: swap(T&a, T&b)
{
	T temp; temp = a; a = b; b = temp;
}

template <class T>
void MaxHeap<T> :: maxHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int max = i;

	if( l < heapSize && this->tree->at(max) < this->tree->at(l))
		max = l;
	if( r < heapSize && this->tree->at(max) < this->tree->at(r))
		max = r;

	if(max != i){
		swap(this->tree->at(max), this->tree->at(i));
		maxHeapify(max);
	}
}

template <class T>
void MaxHeap<T> :: buildMaxHeap()
{
	for(int i = heapSize/2; i >= 0; i--)
		maxHeapify(i);
}

template <class T>
void MaxHeap<T> :: insert(T value)
{
	//aumento il size dell'heap
	heapSize++;

	//inserisco il valore passato come parametro all'interno dell'heap
	this->tree->push_back(value);

	int i = heapSize-1;

	while(i != 0 && this->tree->at(i) > this->tree->at(parent(i))){
		swap(this->tree->at(i), this->tree->at(parent(i)));
		i = parent(i);
	}

}

template <class T>
void MaxHeap<T>::printTree()
{
    for (int i = 0; i < tree->size(); i++)
        cout << this->tree->at(i) << " ";
    cout << endl;
}


template <class T>
void MaxHeap<T> :: heapSort()
{
	//costruisco l'heap
	buildMaxHeap();

	for(int i = heapSize-1; i >=0; i--){
		swap(this->tree->at(0), this->tree->at(i));
		setHeapSize(i);
		maxHeapify(0);
	}

}


#endif //MAXHEAP_H
