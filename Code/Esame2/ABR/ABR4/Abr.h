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
    void insert(T, Nodo<T>*, Nodo<T>*);
    void insertNodo(T, Nodo<T>*, Nodo<T>*);
    void inOrderVisit(Nodo<T>*);
    void preOrderVisit(Nodo<T>*);
    void postOrderVisit(Nodo<T>*);

    public:
    Abr(Nodo<T>* root):root(root){};
    Abr(){root = nullptr;}
    void insert(T value);
    void inOrderVisit();
    void preOrderVisit();
    void postOrderVisit();
    T maximum(Nodo<T>*);
    T minimum(Nodo<T>*);
    T maximum();
    T minimum();
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
void Abr<T> :: insert(T value, Nodo<T>* prev, Nodo<T>* curr)
{
    if(curr == nullptr)
        insertNodo(value, prev, curr);
    else if(value > curr->getValue())
        insert(value, curr, curr->getRight());
    else
        insert(value, curr, curr->getLeft());
}

template <class T>
void Abr<T> :: insertNodo(T value, Nodo<T>* prev, Nodo<T>* curr)
{
    if(prev == nullptr)
        root = new Nodo<T>(value);
    else{
        curr = new Nodo<T>(value);
        curr->setParent(prev);
        if(value > prev->getValue())
            prev->setRight(curr);
        else
            prev->setLeft(curr);
    }
}

template <class T>
T Abr<T> :: maximum(Nodo<T>* temp)
{
    while(temp->getRight!=nullptr)
        temp = temp->getRight();
    return temp->getValue();
}

template <class T>
T Abr<T> :: minimum(Nodo<T>* temp)
{
    while(temp->getLeft!=nullptr)
        temp = temp->getLeft();
    return temp->getValue();
}


template <class T>
T Abr<T> :: maximum()
{
    Nodo<T>* temp = root;
    while(temp->getRight!=nullptr)
        temp = temp->getRight();
    return temp->getValue();
}

template <class T>
T Abr<T> :: minimum()
{
    Nodo<T>* temp = root;
    while(temp->getLeft!=nullptr)
        temp = temp->getLeft();
    return temp->getValue();
}

template <class T>
T Abr<T> :: predecessor(Nodo<T>* nodo)
{
    if(nodo->getLeft()!= nullptr)
        return maximum(nodo->getLeft);
    auto y = nodo->getParent();
    while(y != nullptr && nodo = y->getLeft())
    {
        nodo = y;
        y = y->getParent();
    }
    return y->getParent();
}

template <class T>
T Abr<T> :: successor(Nodo<T>* nodo)
{
    if(nodo->getRight()!= nullptr)
        return minimum(nodo->getRight);
    auto y = nodo->getParent();
    while(y != nullptr && nodo = y->getRight())
    {
        nodo = y;
        y = y->getParent();
    }
    return y->getParent();
}

template <class T>
void Abr<T> :: inOrderVisit(Nodo<T>* nod)
{
    if(nod == nullptr)
        return;
    inOrderVisit(nod->getLeft());
    cout << nod->getValue() << " ";
    inOrderVisit(nod->getRight());

}
template <class T>
void Abr<T> :: preOrderVisit(Nodo<T>* nod)
{
    if(nod == nullptr)
        return;
    cout<<nod->getValue();
    preOrderVisit(nod->getLeft());
    preOrderVisit(nod->getRight());
    
}
template <class T>
void Abr<T> :: postOrderVisit(Nodo<T>* nod)
{
    if(nod == nullptr)
        return;
    postOrderVisit(nod->getLeft());
    postOrderVisit(nod->getRight());
    cout<<nod->getValue();
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


#endif //ABR_H