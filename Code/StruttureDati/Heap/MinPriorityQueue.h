#ifndef MINPRIORITYQUEUE_H
#define MINPRIORITYQUEUE_H

#include <iostream>
#include <vector>
#include "MinHeap.h"

using namespace std;

template <class T>
class MinPriorityQueue:private MinHeap<T>
{
    public:
        MinPriorityQueue(vector<T>*);
        MinPriorityQueue();
        
        void increaseKey(int, T);
        void decreaseKey(int, T);

        void queueInsert(T);

        T minimum();
        T extractMin();

        void print();
        void printAsciTree();
};

template <class T>
MinPriorityQueue<T> :: MinPriorityQueue(vector<T>* tree):MinHeap<T>(tree)
{

}

template <class T>
MinPriorityQueue<T> :: MinPriorityQueue()
{

}

template <class T>
T MinPriorityQueue<T> :: minimum()
{
    return this->getRoot();
}

template <class T>
T MinPriorityQueue<T> :: extractMin()
{
    if(this->getHeapSize() == 0)
        return;

    T min = this->getRoot();

    swap(this->getTree()->at(0), this->getTree()->at(this->getHeapSize()-1));
    this->setHeapSize(this->getHeapSize()-1);
    this->minHeapify(0);
    return min;
}

template <class T>
void MinPriorityQueue<T> ::increaseKey(int i, T key)
{
    if(key < this->getTree()->at(i))
        return;

    this->setTree(i, key);

    while(i >0 && this->getTree()->at(this->parent(i)) > this->getTree()->at(i))
    {
        swap(this->getTree()->at(this->parent(i)), this->getTree()->at(i));
        i = this->parent(i);
    }

}


template <class T>
void MinPriorityQueue<T> ::decreaseKey(int i, T key)
{
    if(key > this->getTree()->at(i))
        return;
    this->setTree(i, key);
    this->minHeapify(i);

}


template <class T>
void MinPriorityQueue<T> :: queueInsert(T key)
{
    this->insert(key);
}


template <class T>
void MinPriorityQueue<T> :: printAsciTree()
{
    this->inOrderAscii(0,0);
}










#endif //MINPRIORITYQUEUE_H