#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

template <class T>
class MaxHeap
{
    private:
    vector<T>* tree;
    int heapSize;
    void buildMaxHeap();
    void maxHeapify(int);
    void swap(T&, T&);
    
    public:
    MaxHeap(vector<T>*);
    MaxHeap();
    void insert(T);
    void heapSort();
    void printToFile(const string filename);
};

template <class T>
MaxHeap<T> :: MaxHeap(vector<T>* tree)
{
    this->tree = tree;
    int heapSize = tree->size();
    buildMaxHeapify();
}

template <class T>
MaxHeap<T> :: MaxHeap()
{
    this->tree = new vector<T>*;
    heapSize = 0;
}

template <class T>
void MaxHeap<T> :: buildMaxHeap()
{
    for(int i = heapSize/2; i>=0; i--)
        maxHeapify(i);
}

template <class T>
void MaxHeap<T> :: maxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int max = i;
    if(l < heapSize && this->tree->at(l) > this->tree->at(max))
        max = l;
    if(r < heapSize && this->tree->at(r) > this->tree->at(max))
        max = r;
    if(max!=i)
    {
        swap(this->tree->at(i), this->tree->at(max));
        maxHeapify(max);
    }
}

template <class T>
void MaxHeap<T> ::swap(T&a, T&b)
{
    T tmp;tmp = a;a=b;b=tmp;
}

template <class T>
void MaxHeap<T> :: insert(T value)
{
    tree->push_back(value);
    heapSize++;
    int i = heapSize-1;
    while(i >=0 && tree->at(i) > tree->at(parent(i)))
    {
        swap(tree->at(i), tree->at(parent(i)));
        i = parent(i);
    }
}

template <class T>
void MaxHeap<T> :: heapSort()
{
    buildMaxHeap();
    for(int i = heapSize-1; i >= 0; i--)
    {
        swap(this->tree->at(i), this->tree->at(0));
        i--;
        maxHeapify(i);
    }
    
}


#endif //MAXHEAP_H