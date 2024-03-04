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

#include <string>

int main(){

    // Stack<int> memStack;
    // int primo = 10;
    // memStack.Push(primo);
    // memStack.Pop(primo);

    // Nodo<int> nodo(nullptr,new int(1));
    // nodo.setNext(new Nodo<int>(nullptr,new int(2)));

    // LinkedList<string>* lista = new LinkedList<string>;
    // lista->insNodo(lista->getLast(),new string("Ciao"));
    // lista->insNodo(lista->getLast(),new string("Attilio"));

    // MaxHeap<int> maxTree;
    
    // maxTree.insert(100);
    // maxTree.insert(10);
    // maxTree.insert(36);
    // maxTree.insert(5);
    // maxTree.insert(40);
    // maxTree.insert(159);
    // maxTree.print();
    // maxTree.printAsciiTree();


    // MinHeap<int> minTree;

    // minTree.insert(100);
    // minTree.insert(10);
    // minTree.insert(36);
    // minTree.insert(5);
    // minTree.insert(40);
    // minTree.insert(159);
    // minTree.print();
    // minTree.printAsciiTree();

    // MinHeap<int> minTree;
    // minTree.insert(10);

    // MaxKappaHeap<int> maxKappaTree(4);
    // maxKappaTree.insert(10);

    // MaxKappaHeap<int> minKappaTree(6);
    // minKappaTree.insert(10);

    MaxPriorityQueue<int> maxPriorityQueue;
    maxPriorityQueue.queueInsert(120);
    maxPriorityQueue.queueInsert(10);
    maxPriorityQueue.queueInsert(50);
    maxPriorityQueue.queueInsert(90);
    maxPriorityQueue.printAsciiTree();


    // MinPriorityQueue<double> minPriorityQueue;
    // minPriorityQueue.queueInsert(120);
    
    return 0;
}