#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

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
    void buildMaxHeap();
    void maxHeapify(int);
    void swap(T&,T&);

    public:
    MaxHeap(vector<T>*);
    MaxHeap();
    void insert(T);
    void heapSort();
    void printToFile(const string& filename);
};

template <class T>
MaxHeap<T>::MaxHeap(vector<T>* tree)
{
    this->tree = tree;
    heapSize = tree->size();
}

template <class T>
MaxHeap<T> :: MaxHeap()
{
    tree = new vector<T>;
    heapSize = 0;
}

template <class T>
void MaxHeap<T> :: buildMaxHeap()
{
    for(int i = heapSize/2; i>= 0; i--)
        maxHeapify(i);
}

template <class T>
void MaxHeap<T> :: maxHeapify(int i)
{
    int max = i;
    int l = left(i);
    int r = right(i);

    if(l < heapSize && tree->at(l) > tree->at(max))
        max = l;
    if(r < heapSize && tree->at(r) > tree->at(max))
        max = l;
    if(max!=i)
    {
        swap(tree->at(max), tree->at(i));
        maxHeapify(max);
    }
}

template <class T>
void MaxHeap<T>::swap(T&a, T&b)
{
    T tmp;tmp=a;a=b;b=tmp;
}

template <class T>
void MaxHeap<T> :: insert(T value)
{
    tree->push_back(value);
    heapSize++;
    int i = heapSize-1;
    while(i>=0 && tree->at(i) > tree->at(parent(i)))
    {
        swap(tree->at(i), tree->at(parent(i)));
        i--;
    }
}

template <class T>
void MaxHeap<T> :: heapSort()
{
    buildMaxHeap();
    for(int i = heapSize-1; i >=0; i--)
    {
        swap(this->tree->at(0), this->tree->at(i));
        i--;
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