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

        int left(int i){return (i*2)+1;}
        int right(int i){return (i*2)+2;}
        int parent(int i){return (i-1)/2;}

        void buildMaxHeap();
        void swap(T &a, T &b);
        void maxHeapify(int i);
        void setHeapSize(int i){this->heapSize = i;}

    public:
        MaxHeap(vector<T> *tree);
        MaxHeap();
 
        void insert(T);
        void printTree();
        void heapSort();

};

template <class T>
MaxHeap<T>:: MaxHeap(vector<T>* tree)
{
    this->tree = tree;
    this->heapSize = tree->size();
    buildMaxHeap();
}

template <class T>
void MaxHeap<T> :: swap(T& a, T&b)
{
    T temp;temp = a; a = b; b = temp;    
}

template <class T>
void MaxHeap<T> :: buildMaxHeap()
{
    for(int i = heapSize/2; i >=0; i--)
        maxHeapify(i);
}

template <class T>
void MaxHeap<T> :: maxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int max = i;

    
    if(l < heapSize && this->tree->at(max) < this->tree->at(l))
        max = l;
    if(r < heapSize && this->tree->at(max) < this->tree->at(r))
        max = r;
    if(max != i)
    {
        swap(this->tree->at(i), this->tree->at(max));
        maxHeapify(max);
    }

}


template <class T>
void MaxHeap<T> :: heapSort()
{
    buildMaxHeap();
    for(int i = heapSize-1; i>=0; i--)
    {
        swap(this->tree->at(0), this->tree->at(i));
        setHeapSize(i);
        maxHeapify(0);
    }
}

template <class T>
void MaxHeap<T> :: insert(T value)
{
    heapSize++;
    this->tree->push_back(value);
    int i = heapSize-1;
    while(i != 0 && this->tree->at(parent(i)) < this->tree->at(i))
    {
        swap(this->tree->at(parent(i)), this->tree->at(i));
        i = parent(i);
    }
}

template <class T>
void MaxHeap<T> :: printTree()
{
    cout << "tree" << endl;
    for(auto num :*tree)
    {
        cout << num << " ";
    }
    cout << endl;

}




#endif //MAXHEAP