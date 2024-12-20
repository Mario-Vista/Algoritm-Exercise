#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <vector>

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

    void maxHeapify(int);
    void buildMaxHeap();
    void swap(T&,T&);

    public:
    MaxHeap(vector<T>* tr);
    MaxHeap();
    void insert(T);
    void printTree();
    void heapSort();
};

template <class T>
MaxHeap<T> :: MaxHeap(vector<T>* tr)
{
    tree = tr;
    heapSize = tr->size();
    buildMaxHeap();
}

template <class T>
MaxHeap<T> :: MaxHeap()
{
    tree = new vector<int>;
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
    if(max != i)
    {
        swap(this->tree->at(i), this->tree->at(max));
        maxHeapify(max);
    }
}

template <class T>
void MaxHeap<T> :: swap(T& a, T& b)
{
    T tmp;tmp = a; a = b; b = tmp;
}

template <class T>
void MaxHeap<T> :: heapSort()
{
    buildMaxHeap();
    for(int i = heapSize-1; i >=0; i--)
    {
        swap(this->tree->at(i), this->tree->at(0));
        heapSize--;
        maxHeapify(0);
    }
}

template <class T>
void MaxHeap<T> :: insert(T value)
{
    tree->push_back(value);
    heapSize++;
    int i = heapSize-1;
    while(i >= 0 && this->tree->at(i) > this->tree->at(parent(i)))
    {
        swap(this->tree->at(i), this->tree->at(parent(i)));
        i = parent(i);
    }
}

template <class T>
void MaxHeap<T> :: printTree()
{
    for(int i = 0; i < tree->size(); i++)
        cout << this->tree->at(i) << " ";
    cout << endl;
}

#endif //MAXHEAP_H