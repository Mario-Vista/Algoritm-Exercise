#ifndef MAXPRIORITYQUEUE_H
#define MAXPRIORITYQUEUE_H

#include "MaxHeap.h"
#include <vector>
#include <iostream>

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
        void printAsciiTree();
};

template <class T>
MaxPriorityQueue<T> :: MaxPriorityQueue(vector<T>* tree):MaxHeap<T>(tree){

}

template <class T>
MaxPriorityQueue<T>::MaxPriorityQueue(){

}

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
    this->swap(this->getTree()->at(0), this->getTree()->at(this->getHeapSize()-1));
    this->setHeapSize(this->getHeapSize()-1);
    this->maxHeapify(0);
    return max;
}

template <class T>
void MaxPriorityQueue<T> :: queueInsert(T key)
{
    this->insert(key);
}

template <class T>
void MaxPriorityQueue<T> :: increasePriority(int i, T key)
{
    if(key < this->getTree()->at(i))
        return;

    this->setTree(i, key);

    while(i > 0 && this->getTree()->at(this->parent(i)) < this->getTree()->at(i))
    {
        this->swap(this->getTree()->at(this->parent(i)), this->getTree()->at(i));
        i = this->parent(i);
    }
}

template <class T>
void MaxPriorityQueue<T> :: decreasePriority(int i, T key)
{
    if(key > this->getTree()->at(i))
        return;

    this->setTree(i,key);
    this->maxHeapify(i);
}

template <class T>
void MaxPriorityQueue<T>::print(){
    cout << endl << "***Max Heap***" << endl;
    for (int i=0; i<this->getHeapSize(); i++)
        cout << this->getTree()->at(i) << " ";
}

template <class T>
void MaxPriorityQueue<T>::printAsciiTree(){
    cout << endl << "***Max Ascii Heap***" << endl;
    this->inOrderAscii(0,0);
}



#endif //MAXPRIORITYQUEUE_H