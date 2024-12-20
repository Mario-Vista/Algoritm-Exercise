#ifndef MAXPRIORITYQUEUE_H
#define MAXPRIORITYQUEUE_H

#include <iostream>
#include <vector>
#include "MaxHeap.h"

using namespace std;

template <class T>
class MaxPriorityQueue:private MaxHeap<T>
{
    public:
    MaxPriorityQueue(vector<T>*);
    MaxPriorityQueue();

    T maximum();
    T extractMax();

    void queueInsert(T);
    void increasePriority(int, T);
    void decreasePriority(int, T);
    void print();
};

template <class T>
MaxPriorityQueue<T> :: MaxPriorityQueue(vector<T>* tree): MaxHeap<T>(tree)
{}

template <class T>
MaxPriorityQueue<T> :: MaxPriorityQueue():
{}

template <class T>
T MaxPriorityQueue<T> :: maximum()
{
    return this->getRoot();
}

template <class T>
T MaxPriorityQueue<T> :: extractMax()
{
    if(this->getHeapSize() == 0)
        return false;
    T max = this->getRoot();
    swap(this->getTree()->at(0), this->getTree()->at(getHeapSize()-1));
    setHeapSize(getHeapSize()-1);
    return max;
}

template <class T>
void MaxPriorityQueue<T> :: queueInsert(T value)
{
    insert(value);
}

template <class T>
void MaxPriorityQueue<T> :: increasePriority(int i, T key)
{
    if(key < getTree()->at(i))
        return;

    setTree(i, key);
    maxHeapify(i);
}

template <class T>
void MaxPriorityQueue<T> :: decreasePriority(int i, T key)
{
    if(key > getTree()->at(i))
        return;
    setTree(i, key);
    maxHeapify(i);
}

template<class T>
void MaxPriorityQueue<T> :: print()
{
	cout << endl << "***Max Heap***" << endl;
    for (int i=0; i<this->getHeapSize(); i++)
        cout << this->getTree()->at(i) << " ";
}

#endif //MAXPRIORITYQUEUE_H