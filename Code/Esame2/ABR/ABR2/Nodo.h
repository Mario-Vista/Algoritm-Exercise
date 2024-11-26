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
    Nodo(T value):value(value), parent(nullptr), left(nullptr), right(nullptr){};
    Nodo(T value, Nodo<T>*parent, Nodo<T>*left, Nodo<T>*right):value(value), parent(parent), left(left), right(right){};

    T getValue(){return this->value;}
    Nodo<T>* getLeft(){return this->left;}
    Nodo<T>* getRight(){return this->right;}
    Nodo<T>* getParent(){return this->parent;}

    void setLeft(Nodo<T>* l){this->left = l;}
    void setRight(Nodo<T>* r){this->right = r;}
    void setParent(Nodo<T>* p){this->parent = p;}
};


#endif //NODO_H