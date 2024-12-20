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
    int left(int i){return (2*i)+1;}
    int right(int i){return (2*i)+2;}
    int parent(int i){return (i-1)/2;}
    void swap(T&,T&);
    void maxHeapify(int);
    void buildMaxHeap();

    public:
    MaxHeap(vector<T>*);
    MaxHeap();
    void heapSort();
    void insert(T);
    void printToFile(const string&);
};

template <class T>
MaxHeap<T> :: MaxHeap(vector<T>* tree)
{
    this->tree = tree;
    this->heapSize = tree->size();
    buildMaxHeap();
}

template <class T>
MaxHeap<T> :: MaxHeap()
{
    this->tree = new vector<T>;
    this->heapSize = 0;
}

template <class T>
void MaxHeap<T> :: swap(T&a, T&b)
{
    T tmp;tmp = a; a = b; b = tmp;
}

template <class T>
void MaxHeap<T> :: buildMaxHeap()
{
    for(int i = heapSize/2; i >= 0; i--)
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
    if(max != i)
    {
        swap(tree->at(i), tree->at(max));
        maxHeapify(max);
    }
}

template <class T>
void MaxHeap<T> :: insert(T value)
{
    tree->push_back(value);
    heapSize++;
    int i = heapSize-1;
    while(i >= 0 && tree->at(i) > tree->at(parent(i)))
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
        swap(tree->at(0), tree->at(i));
        heapSize--;
        maxHeapify(0);
    }
}

template <class T>
void MaxHeap<T> :: printToFile(const string& filename)
{
    ofstream oFile(filename);
    for(int i = 0; i < tree->size(); i++)
        oFile << tree->at(i) << " ";
}



#endif //MAXHEAP_H