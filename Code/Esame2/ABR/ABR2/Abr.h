#ifndef ABR_H
#define ABR_H

#include <iostream>
#include <fstream>
#include "Nodo.h"

using namespace std;

template <class T>
class Abr
{
    private:
    Nodo<T>* root;
    void insert(T, Nodo<T>*, Nodo<T>*);
    void insertNodo(T, Nodo<T>*, Nodo<T>*);
    void inOrderVisit(Nodo<T>*);
    void preOrderVisit(Nodo<T>*);
    void postOrderVisit(Nodo<T>*);

    public:
    Abr(Nodo<T>* root){this->root = root;}
    Abr(){this->root = nullptr;}
    void insert(T);
    void inOrderVisit();
    void preOrderVisit();
    void postOrderVisit();
    Nodo<T>* getRoot(){return this->root;}
    T maximum();
    T minimum();
    T maximum(Nodo<T>*);
    T minimum(Nodo<T>*);
    T predecessor(Nodo<T>*);
    T successor(Nodo<T>*);
};


template <class T>
void Abr<T> :: insert(T value)
{
    if(root == nullptr)
        root = new Nodo<T>(value);
    else
        insert(value, nullptr, root);   
}

template <class T>
void Abr<T> :: insert(T value, Nodo<T>*prev, Nodo<T>*curr)
{
    if(curr == nullptr)
        this->insertNodo(value, prev, curr);
    else if(value > curr->getValue())
        insert(value, curr, curr->getRight());
    else
        insert(value, curr, curr->getLeft());
}

template <class T>
void Abr<T> :: insertNodo(T value, Nodo<T>*prev, Nodo<T>* curr)
{
    if(prev == nullptr)
        root = new Nodo<T>(value);
    else
    {
        curr = new Nodo<T>(value);
        curr->setParent(prev);
        if(value > prev->getValue())
            prev->setRight(curr);
        else
            prev->setLeft(curr);
    }
}

template <class T>
T Abr<T> :: maximum(Nodo<T>* nodo)
{
    while(nodo->getRight() != nullptr)
        nodo = nodo->getRight();
    return nodo->getValue();
}

template <class T>
T Abr<T> :: minimum(Nodo<T>* nodo)
{
    while(nodo->getLeft() != nullptr)
        nodo = nodo->getLeft();
    return nodo->getLeft();
}

template <class T>
T Abr<T> :: maximum()
{
    auto nodo = root;
    while(nodo->getRight() != nullptr)
        nodo = nodo->getRight();
    return nodo->getValue();
}

template <class T>
T Abr<T> :: minimum()
{
    auto nodo = root;
    while(nodo->getLeft() != nullptr)
        nodo = nodo->getLeft();
    return nodo->getValue();
}

template <class T>
T Abr<T> :: predecessor(Nodo<T>*nodo)
{
    if(nodo->getLeft() != nullptr)
        return maximum(nodo->getLeft());

    auto y = nodo->getParent();
        while(y != nullptr && nodo == y->getLeft())
        {
            nodo = y;
            y = y->getParent();
        }
    return y->getParent();
}

template <class T>
T Abr<T> ::successor(Nodo<T>*nodo)
{
    if(nodo->getRight())
        return minimum(nodo->getRight());

    auto y = nodo->getParent();
        while(y != nullptr && nodo == y->getRight())
        {
            nodo = y;
            y = y->getParent();
        }
    return y->getParent();
}

template <class T>
void Abr<T> :: inOrderVisit()
{
    inOrderVisit(this->root);
}

template <class T>
void Abr<T> :: preOrderVisit()
{
    preOrderVisit(this->root);
}

template <class T>
void Abr<T> :: postOrderVisit()
{
    postOrderVisit(this->root);
}

template <class T>
void Abr<T> :: inOrderVisit(Nodo<T>* nodo)
{
    if(nodo == nullptr)
        return;
    inOrderVisit(nodo->getLeft());
    cout << nodo->getValue();
    inOrderVisit(nodo->getRight());
}

template <class T>
void Abr<T> :: preOrderVisit(Nodo<T>* nodo)
{
    if(nodo == nullptr)
        return;
    cout << nodo->getValue();
    preOrderVisit(nodo->getLeft());
    preOrderVisit(nodo->getRight());}

template <class T>
void Abr<T> :: postOrderVisit(Nodo<T>* nodo)
{
    if(nodo == nullptr)
        return;
    postOrderVisit(nodo->getLeft());
    postOrderVisit(nodo->getRight());
    cout << nodo->getValue();
}

#endif //ABR_H