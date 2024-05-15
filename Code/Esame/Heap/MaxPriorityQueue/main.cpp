#include "MaxHeap.h"
#include "MaxPriorityQueue.h"

#include <iostream>
#include <string>

int main(){


    MaxHeap<int> maxTree;
    
    maxTree.insert(100);
    maxTree.insert(10);
    maxTree.insert(36);
    maxTree.insert(5);
    maxTree.insert(40);
    maxTree.insert(159);
    maxTree.printTree();





    MaxPriorityQueue<int> maxPriorityQueue;
    maxPriorityQueue.queueInsert(120);
    maxPriorityQueue.queueInsert(10);
    maxPriorityQueue.queueInsert(50);
    maxPriorityQueue.queueInsert(90);
    maxPriorityQueue.print();
}
