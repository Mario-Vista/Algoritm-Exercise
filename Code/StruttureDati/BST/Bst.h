#ifndef BST_H
#define BST_H
#include "Node.h"
#include <iostream>

template <class T>
class Bst
{
    private:
        Node<T>* root;
        void insert(T, Node<T>*, Node<T>*);
        void insertNodo(T, Node<T>*, Node<T>*);

        //algoritmi di visita
        void preOrder(Node<T>*);
        void inOrder(Node<T>*);
        void postOrder(Node<T>*);

    public:
        Bst(Node<T> *root);
        Bst();

        Node<T>* getRoot(){return root;}

        void insert(T);

        T minimum();
        T maximum();
        T minimum(Node<T>*);
        T maximum(Node<T>*);

        T successor(Node<T>*);
        T predecessor(Node<T>*);

        void preOrder();
        void inOrder();
        void postOrder();

};

template <class T>
Bst<T> :: Bst(Node<T> *root)
{
    this->root = root;
}

template <class T>
Bst<T> :: Bst()
{
    this->root = nullptr;
}


template <class T>
void Bst<T> :: insert(T key)
{
    if(this->root==nullptr)
        this->root = new Node<T>(key);
    else
        this->insert(key, nullptr, this->root);
}

template <class T>
void Bst<T> :: insert(T key, Node<T> *prev, Node<T> *curr)
{
    if(curr == nullptr)
        this->insertNodo(key, prev, curr);
    else if(key > curr->getValue())
        this->insert(key, curr, curr->getRight());
    else
        this->insert(key, curr, curr->getLeft());
}

template <class T>
void Bst<T> :: insertNodo(T key, Node<T> *prev, Node<T> *curr)
{
    if(prev == nullptr)
        curr == new Node<T>(key);
    else
    {
        curr = new Node<T>(key);
        curr->setParent(prev);
        if(key > prev->getValue())
            prev->setRight(curr);
        else
            prev->setLeft(curr);
    }
}

template <class T>
T Bst<T> ::minimum()
{
    auto tmp = root;
    while(tmp->getLeft() != nullptr)
        tmp = tmp->getLeft();
    return tmp->getValue();
}

template <class T>
T Bst<T> ::maximum()
{
    auto tmp = root;
    while(tmp->getRight() != nullptr)
        tmp = tmp->getRight();
    return tmp->getValue();
}

template <class T>
T Bst<T> ::minimum(Node<T> *nodo)
{
    while(nodo->getLeft() != nullptr)
        nodo = nodo->getLeft();
    return nodo->getValue();
}

template <class T>
T Bst<T> ::maximum(Node<T> *nodo)
{
    while(nodo->getRight() != nullptr)
        nodo = nodo->getRight();
    return nodo->getValue();
}

template <class T>
T Bst<T> :: successor(Node<T> *node)
{
    if(node->getRight() != nullptr)
    {
        return this->minimum(node->getRight());
    }

    auto y = node->getParent();
    while(y != nullptr && node == y->getRight())
    {
        node = y;
        y = y->getParent();
    }
    return y->getValue();

}

template <class T>
T Bst<T> :: predecessor(Node<T> *node)
{
    if(node->getLeft() != nullptr)
    {
        return this->maximum(node->getLeft());
    }

    auto y = node->getParent();
    while(y != nullptr && node == y->getLeft())
    {
        node = y;
        y = y->getParent();
    }
    return y->getValue();
}

template <class T>
void Bst<T> :: preOrder()
{
    this->preOrder(this->root);
}

template <class T>
void Bst<T> :: inOrder()
{
    this->inOrder(this->root);
}

template <class T>
void Bst<T> :: postOrder()
{
    this->postOrder(this->root);
}

template <class T>
void Bst<T> :: preOrder(Node<T> *curr)
{
    if(curr == nullptr)
        return;

    std::cout << curr->getValue() << " ";
    this->preOrder(curr->getLeft());
    this->preOrder(curr->getRight());
}

template <class T>
void Bst<T> :: inOrder(Node<T> *curr)
{
    if(curr == nullptr)
        return;

    this->preOrder(curr->getLeft());
    std::cout << curr->getValue() << " ";
    this->preOrder(curr->getRight());
}

template <class T>
void Bst<T> :: postOrder(Node<T> *curr)
{
    if(curr == nullptr)
        return;

    this->preOrder(curr->getLeft());
    this->preOrder(curr->getRight());
    std::cout << curr->getValue() << " ";
}


#endif //BST_H