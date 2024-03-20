#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <list>
#include <vector>

using namespace std;

template <class T>
class Nodo
{
    private:
        T info;
        Nodo<T>* parent;
        Nodo<T>* left;
        Nodo<T>* right;
    public:
        Nodo(T info);
        void setInfo(T info){this->info = info;}
        T getInfo(){return this->info;}
        void setParent(Nodo<T>* parent){this->parent = parent;}
        Nodo<T>* getParent(){return this->parent;}
        void setLeft(Nodo<T>* left){this->left = left;}
        Nodo<T>* getLeft(){return this->left;}
        void setRight(Nodo<T>* right){this->right = right;}
        Nodo<T>* getRight(){return this->right;}
};

template <class T>
Nodo<T> :: Nodo(T info)
{
    this->info = info;
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

#endif //NODO_H