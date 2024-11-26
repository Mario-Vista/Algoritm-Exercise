#ifndef ABR_H
#define ABR_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Nodo.h"

using namespace std;

template <class T>
class Abr
{
    private:
        Nodo<T>* root;
        void insertNodo(T, Nodo<T>*, Nodo<T>*);
        void preOrder(Nodo<T>*);
        void inOrder(Nodo<T>*);
        void postOrder(Nodo<T>*);

    public:
        Abr(Nodo<T>* root); 
        Abr();

        Nodo<T>* getRoot(){return this->root;}

        void insert(T);

        T minimum();
        T maximum();
        T minimum(Nodo<T>*);
        T maximum(Nodo<T>*);

        T successor(Nodo<T>*);
        T predecessor(Nodo<T>*);

        void preOrder();
        void inOrder();
        void postOrder();
};

template <class T>
Abr<T> :: Abr(Nodo<T>* root)
{
    this->root = root;
}

template <class T>
Abr<T> :: Abr()
{
    this->root == nullptr;
}

template<class T>
void Abr<T> :: insert(T key)
{
    this->insertNodo(key, nullptr, this->root);
}

template <class T>
void Abr<T> :: insertNodo(T key, Nodo<T>*prev, Nodo<T>* curr)
{
    curr = new Nodo<T>(key);
    curr->setParent(prev);
    if(prev == nullptr)
        this->root = curr;
    else if(key > prev->getValue())
        prev->setRight(curr);
    else
        prev->setLeft(curr);
}

template <class T>
T Abr<T> :: minimum()
{
    auto tmp = root;
    while(tmp->getLeft() != nullptr)
        tmp = tmp->getLeft();
    return tmp->getValue();
}

template <class T>
T Abr<T> :: maximum()
{
    auto tmp = root;
    while(tmp->getRight() != nullptr)
        tmp = tmp->getRight();
    return tmp->getValue();
}

template <class T>
T Abr<T> :: minimum(Nodo<T>* nodo)
{
    while(nodo->getLeft() != nullptr)
        nodo = nodo->getLeft();
    return nodo->getValue();
}

template <class T>
T Abr<T> :: maximum(Nodo<T>* nodo)
{
    while(nodo->getRight() != nullptr)
        nodo = nodo->getRight();
    return nodo->getValue();
}

template <class T>
T Abr<T> :: successor(Nodo<T>* nodo)
{
    if(nodo->getRight() != nullptr)
        return this->minimum(nodo->getRight());
    auto y = nodo->getParent();
    while(y != nullptr && nodo == y->getRight())
    {
        nodo = y;
        y = y->getParent();
    }
    return y->getValue();
}

template <class T>
T Abr<T> :: predecessor(Nodo<T>* nodo)
{
    if(nodo->getLeft() != nullptr)
        return this->maximum(nodo->getLeft());
    auto y = nodo->getParent();
    while(y != nullptr && nodo == y->getLeft())
    {
        nodo = y;
        y = y->getParent();
    }
    return y->getValue();
}

template <class T>
void Abr<T> :: preOrder()
{
    this->preOrder(this->root);
}

template <class T>
void Abr<T> :: inOrder()
{
    this->inOrder(this->root);
}

template <class T>
void Abr<T> :: postOrder()
{
    this->postOrder(this->root);
}


template <class T>
void Abr<T> :: preOrder(Nodo<T>* curr)
{
    if(curr == nullptr)
        return;
    cout << curr->getValue() << " ";
    this->preOrder(curr->getLeft());
    this->preOrder(curr->getRight());    
}

template <class T>
void Abr<T> :: inOrder(Nodo<T>* curr)
{
    if(curr == nullptr)
        return;
    this->preOrder(curr->getLeft());
    cout << curr->getValue() << " ";
    this->preOrder(curr->getRight()); 
}

template <class T>
void Abr<T> :: postOrder(Nodo<T>* curr)
{
    if(curr == nullptr)
        return;
    this->preOrder(curr->getLeft());
    this->preOrder(curr->getRight());
    cout << curr->getValue() << " ";
}

#endif //ABR_H