#ifndef NODO_H
#define NODO_H

#include <iostream>

using namespace std;

template <class T>
class Nodo
{
    private:
    T value;
    Nodo<T>* left;
    Nodo<T>* right;
    Nodo<T>* parent;

    public:
    Nodo(T value, Nodo<T>*left, Nodo<T>*right, Nodo<T>*parent): value(value), left(left), right(right), parent(parent){};
    Nodo(T value): value(value), left(nullptr), right(nullptr), parent(nullptr){};
    T getValue(){return value;}
    Nodo<T>* getLeft(){return left;}
    Nodo<T>* getRight(){return right;}
    Nodo<T>* getParent(){return parent;}

    void setValue(T val){value = val;}
    void setLeft(Nodo<T>* le){left = le;}
    void setRight(Nodo<T>* ri){right = ri;}
    void setParent(Nodo<T>* pa){parent = pa;}

};


#endif //NODO_H