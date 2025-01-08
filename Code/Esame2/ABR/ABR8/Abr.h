#ifndef ABR_H
#define ABR_H

#include <iostream>
#include "Nodo.h"

using namespace std;

template <class T>
class Abr
{
    private:
    Nodo<T>* root;
    void insert(T value, Nodo<T>*prev, Nodo<T>*curr);
    void insertNodo(T value, Nodo<T>*prev, Nodo<T>*curr);
    void inOrderVisit(Nodo<T>*);
    void preOrderVisit(Nodo<T>*);
    void postOrderVisit(Nodo<T>*);

    public:
    Abr(Nodo<T>* root):root(root){};
    Abr():root(nullptr){};
    void insert(T);
    T minimum();
    T maximum();
    T minimum(Nodo<T>*);
    T maximum(Nodo<T>*);
    T predecessor(Nodo<T>*);
    T successor(Nodo<T>*);
    void inOrderVisit();
    void preOrderVisit();
    void postOrderVisit();
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
void Abr<T> :: insert(T value, Nodo<T>* prev, Nodo<T>* curr)
{
    if(curr == nullptr)
        insertNodo(value, prev, curr);
    else if(curr->getValue() > value)
        insert(value, curr, curr->getLeft());
    else    
        insert(value, curr, curr->getRight());
}

template <class T>
void Abr<T> :: insertNodo(T value,Nodo<T>* prev, Nodo<T>*curr)
{
    if(prev == nullptr)
        root = new Nodo<T>(value);
    else
    {
        curr = new Nodo<T>(value);
        curr->setParent(prev);
        if(prev->getValue() > value)
            prev->setLeft(curr);
        else
            prev->setRight(curr);
    }
}

template <class T>
T Abr<T> :: maximum()
{
    Nodo<T>* tmp = root;
    while(tmp->getRight() != nullptr)
        tmp = tmp->getRight();
    return tmp->getValue();
}


template <class T>
T Abr<T> :: minimum()
{
    Nodo<T>* tmp = root;
    while(tmp->getLeft() != nullptr)
        tmp = tmp->getLeft();
    return tmp->getValue();
}



template <class T>
T Abr<T> :: maximum(Nodo<T>* tmp)
{
    while(tmp->getRight() =! nullptr)
        tmp = tmp->getRight();
    return tmp->getValue();
}


template <class T>
T Abr<T> :: minimum(Nodo<T>* tmp)
{
    while(tmp->getLeft() =! nullptr)
        tmp = tmp->getLeft();
    return tmp->getValue();
}


template <class T>
T Abr<T> :: predecessor(Nodo<T>* nodo)
{
    if(nodo->getLeft() != nullptr)
        return maximum(nodo->getLeft());
    auto y = nodo;
    while(y != nullptr && nodo != y->getRight())
    {
        nodo = y;
        y = y->getParent();
    }
    return y->getParent();
}

template <class T>
T Abr<T> :: successor(Nodo<T>* nodo)
{
    if(nodo->getRight() != nullptr)
        return minimum(nodo->getLeft());
    auto y = nodo;
    while(y != nullptr && nodo != y->getLeft())
    {
        nodo = y;
        y = y->getParent();
    }
    return y->getParent();
}

template <class T>
void Abr<T> :: inOrderVisit()
{
    inOrderVisit(root);
}

template <class T>
void Abr<T> :: preOrderVisit()
{
    preOrderVisit(root);
}

template <class T>
void Abr<T> :: postOrderVisit()
{
    postOrderVisit(root);
}


template <class T>
void Abr<T> :: inOrderVisit(Nodo<T>* nodo)
{
    if(nodo == nullptr)
        return;
    inOrderVisit(nodo->getLeft());
    cout << nodo->getValue() << " ";
    inOrderVisit(nodo->getRight());
}

template <class T>
void Abr<T> :: preOrderVisit(Nodo<T>* nodo)
{
    if(nodo == nullptr)
        return;
    cout << nodo->getValue() << " ";
    preOrderVisit(nodo->getLeft());
    preOrderVisit(nodo->getRight());
}

template <class T>
void Abr<T> :: postOrderVisit(Nodo<T>* nodo)
{
    if(nodo == nullptr)
        return;
    postOrderVisit(nodo->getLeft());
    postOrderVisit(nodo->getRight());
    cout << nodo->getValue() << " ";
}




#endif //ABR_H