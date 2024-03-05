/*
    Test Strutture Dati:
        • Stack
        • Nodo
        • LinkedList
        • MaxHeap
        • MinHeap
        • MaxKappaHeap
        • MinKappaHeap
        • MaxPriorityQueue
        • MinPriorityQueue
*/

#include "MaxHeap.h"
#include "MinHeap.h"
#include "MaxKappaHeap.h"
#include "MaxPriorityQueue.h"
#include "MinPriorityQueue.h"

#include <string>

int main(){


    MaxHeap<int> maxTree;
    
    maxTree.insert(100);
    maxTree.insert(10);
    maxTree.insert(36);
    maxTree.insert(5);
    maxTree.insert(40);
    maxTree.insert(159);
    maxTree.print();
    maxTree.printAsciiTree();


    MinHeap<int> minTree;

    minTree.insert(100);
    minTree.insert(10);
    minTree.insert(36);
    minTree.insert(5);
    minTree.insert(40);
    minTree.insert(159);
    minTree.print();
    minTree.printAsciiTree();


    MaxKappaHeap<int> maxKappaTree(4);
    maxKappaTree.insert(10);


    MaxPriorityQueue<int> maxPriorityQueue;
    maxPriorityQueue.queueInsert(120);
    maxPriorityQueue.queueInsert(10);
    maxPriorityQueue.queueInsert(50);
    maxPriorityQueue.queueInsert(90);
    maxPriorityQueue.printAsciiTree();


    MinPriorityQueue<double> minPriorityQueue;
    minPriorityQueue.queueInsert(120);
    minPriorityQueue.queueInsert(120);
    minPriorityQueue.queueInsert(10);
    minPriorityQueue.queueInsert(50);
    minPriorityQueue.queueInsert(90);
    minPriorityQueue.printAsciTree();

    
    return 0;
}