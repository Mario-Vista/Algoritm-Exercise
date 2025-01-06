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
  void insertNodo(T,Nodo<T>*, Nodo<T>*);
  void inOrderVisit(Nodo<T>*);
  void preOrderVisit(Nodo<T>*);
  void postOrderVisit(Nodo<T>*);
  
  public:
  Abr(Nodo<T>* root): root(root){};
  Abr():root(nullptr){};
  void insert(T);
  T maximum();
  T minimum();
  T maximum(Nodo<T>*);
  T minimum(Nodo<T>*);
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
  Nodo<T>* temp = root;
  while(temp->getRight() != nullptr)
    temp = temp->getRight();
  return temp;
}

template <class T>
T Abr<T> :: maximum(Nodo<T>* temp)
{
  while(temp->getRight() != nullptr)
    temp = temp->getRight();
  return temp;
}


template <class T>
T Abr<T> :: minimum()
{
  Nodo<T>* temp = root;
  while(temp->getLeft() != nullptr)
    temp = temp->getLeft();
  return temp;
}

template <class T>
T Abr<T> :: minimum(Nodo<T>* temp)
{
  while(temp->getLeft() != nullptr)
    temp = temp->getLeft();
  return temp;
}

template <class T>
T Abr<T> :: predecessor(Nodo<T>* nodo)
{
  if(nodo->getLeft()!=nullptr)
    return maximum(nodo->getLeft);
  auto y = nodo->getParent();
  while(nodo != y->getLeft() && y != nullptr)
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
    return minimum(nodo->getRight());
  auto y = nodo->getParent();
  while(y != nullptr && y->getRight() != nodo)
  {
    nodo = y;
    y = y->getParent();
  }
  return y->getParent();
}

template <class T>
void Abr<T> ::inOrderVisit()
{
  inOrderVisit(root);
}

template <class T>
void Abr<T> ::preOrderVisit()
{
  preOrderVisit(root);
}

template <class T>
void Abr<T> ::postOrderVisit()
{
  postOrderVisit(root);
}

template <class T>
void Abr<T> ::inOrderVisit(Nodo<T>* nodo)
{
  if(nodo == nullptr)
    return;
  inOrderVisit(nodo->getLeft());
  cout << nodo->getValue() << " ";
  inOrderVisit(nodo->getRight());
}

template <class T>
void Abr<T> ::preOrderVisit(Nodo<T>* nodo)
{
  if(nodo == nullptr)
    return;
  cout << nodo->getValue() << " ";
  preOrderVisit(nodo->getLeft());
  preOrderVisit(nodo->getRight());
}

template <class T>
void Abr<T> ::postOrderVisit(Nodo<T>* nodo)
{
  if(nodo == nullptr)
    return;
  postOrderVisit(nodo->getLeft());
  postOrderVisit(nodo->getRight());
  cout << nodo->getValue() << " ";
}



#endif //ABR_H
