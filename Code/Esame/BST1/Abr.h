#ifndef ABR_H
#define ABR_H

#include <iostream>
#include <vector>
#include <list>
#include "Nodo.h"

#define vuoto 5

using namespace std;

template <class T>

class Abr
{
    private:
        Nodo<T>* root;
        void insertNodo(T value, Nodo<T>* prev, Nodo<T>* curr);
        Nodo<T>* findPredecessor(Nodo<T>* x);
        Nodo<T>* findSuccessor(Nodo<T>* x);
        void inOrderAscii(Nodo<T>* x, int spazio);  

    public:
        Abr(){this->root = nullptr;}
        Nodo<T>* getRoot(){return this->root;}
       // void insert(T value);
        Nodo<T>* getMin(Nodo<T>* x);
        Nodo<T>* getMax(Nodo<T>* x);
        Nodo<T>* predecessor(Nodo<T>* x);
        Nodo<T>* successor(Nodo<T>* x);
        Nodo<T>* treeSearch(Nodo<T>* x, int key);
        void preOrderVisit(Nodo<T>* x);
        void inOrderVisit(Nodo<T>* x);
        void postOrderVisit(Nodo<T>* x);
        void printAsciiTree();
        void insert(T value);

};

//metodo per inserire un nodo nell'albero       
template <class T>
void Abr<T> :: insertNodo(T value, Nodo<T>* prev, Nodo<T>* curr)
{
    curr = new Nodo<T>(value);
    curr->setParent(prev);
    if(curr->getInfo() < prev->getInfo())
        prev->setLeft(curr);
    else
        prev->setRight(curr);
}

template <class T>
Nodo<T>* Abr<T> :: findPredecessor(Nodo<T>* x)
{
    if(x == nullptr)
        return nullptr;
    Nodo<T> *y = x->getParent();
    if(y == nullptr)
        return nullptr;
    else if(x == y->getRight())
        return y;
    else
        return findPredecessor(y);
}

template <class T>
Nodo<T>* Abr<T> :: findSuccessor(Nodo<T>* x)
{
    if(x == nullptr)
        return nullptr;
    Nodo<T>* y = x->getParent();
    if(y == nullptr)
        return nullptr;
    else if(x == y->getLeft())
        return y;
    else
        return findSuccessor(y);
}

template <class T>
Nodo<T>* Abr<T> :: getMin(Nodo<T>* x)
{
    if(x == nullptr)
        return nullptr;
    else if(x->getLeft() == nullptr)
        return x;
    else
        return getMax(x->getLeft());
}

template <class T>
Nodo<T>* Abr<T> :: getMax(Nodo<T>* x)
{
    if(x == nullptr)
        return nullptr;
    else if(x->getRight() == nullptr)
        return x;
    else
        return getMax(x->getRight());
}

template <class T>
Nodo<T>* Abr<T> :: predecessor(Nodo<T>* x)
{
    if(x == nullptr)
        return nullptr;
    else if(x->getLeft() != nullptr)
        return getMax(x->getLeft());
    else
        return findPredecessor(x);
}

template <class T>
Nodo<T>* Abr<T> :: successor(Nodo<T>* x)
{
    if(x == nullptr)
        return nullptr;
    else if(x->getRight()!= nullptr)
        return getMin(x->getRight());
    else
        return findSuccessor(x);
}


template <class T>
Nodo<T>* Abr<T> :: treeSearch(Nodo<T>* x, int key)
{
    if(x == nullptr || x->getInfo() == key)
        return x;
    else if(key < x->getInfo())
        return treeSearch(x->getLeft(), key);
    else
        return treeSearch(x->getRight(), key);
}


template <typename T>
void Abr<T>::preOrderVisit(Nodo<T>* x) {
    if(x != nullptr) {
        cout << x->getInfo() << "  ";
        preOrderVisit(x->getLeft());
        preOrderVisit(x->getRight());
    }
}   


template <typename T>
void Abr<T>::inOrderVisit(Nodo<T>* x) {
    if(x != nullptr) {
        preOrderVisit(x->getLeft());
        cout << x->getInfo() << "  ";
        preOrderVisit(x->getRight());
    }
}   


template <typename T>
void Abr<T>::postOrderVisit(Nodo<T>* x) {
    if(x != nullptr) {
        preOrderVisit(x->getLeft());
        preOrderVisit(x->getRight());
        cout << x->getInfo() << "  ";
    }
}   

template <class T>
void Abr<T> :: insert(T value)
{
    this->insertNodo(value, nullptr, this->root);
}


template<class T>
void Abr<T> :: inOrderAscii(Nodo<T>* x, int spazio)
{
    if(x == nullptr)
        return;
    spazio+=5;
    inOrderAscii(x->getRight(), spazio);
    cout << endl;
    for(int i = vuoto; i < spazio; i++)
        cout << " ";
    cout << x->getInfo() << endl;
    inOrderAscii(x->getLeft(), spazio);
}

template <class T>
void Abr<T> :: printAsciiTree()
{
    inOrderAscii(0,0); 
}



#endif //ABR_H