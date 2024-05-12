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
	void insert(T value, Nodo<T>* prev, Nodo<T>* curr);
	void insertNodo(T value, Nodo<T>* prev, Nodo<T>* curr);
	void inOrderVisit(Nodo<T>* root);
	void preOrderVisit(Nodo<T>* root);
	void postOrderVisit(Nodo<T>* root);

public:
	Abr(Nodo<T>*root){this->root = root;}
	Abr(){this->root = nullptr;}

	void insert(T nodo);
	void inOrderVisit();
	void preOrderVisit();
	void postOrderVisit();
	T maximum();
	T minimum();
	T maximum(Nodo<T>* nodo);
	T minimum(Nodo<T>* nodo);
	T predecessor();
	T successor();
};

template <class T>
void Abr<T> :: insert(T value)
{
	if(this->root = nullptr)
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
		if(value > prev->getValue)
			prev->setRight(curr);
		else
			prev->setLeft(curr);
	}
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
T Abr<T> :: maximum(Nodo<T>* nodo)
{
	while(nodo->getRight() != nullptr)
		nodo = nodo->getRight();
	return nodo->getValue();
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
T Abr<T> :: minimum(Nodo<T>* nodo)
{
	while(nodo->getLeft() != nullptr)
		nodo = nodo->getLeft();
	return nodo->getValue();
}

template <class T>
T Abr<T> :: predecessor(Nodo<T>* nodo)
{
	if(nodo->getLeft()!= nullptr)
		return maximum(nodo->getLeft());
	auto y = nodo->getParent();
	while(y!= nullptr && nodo == nodo->getLeft())
	{
		nodo = y;
		y = y->getParent();
	}
	return y->getValue();
}

template <class T>
T Abr<T> :: successor(Nodo<T>* nodo)
{
	if(nodo->getRight() != nullptr)
		return minimum(nodo->getRight());
	auto y = nodo->getParent();
	while(y != nullptr && nodo = nodo->getRight())
	{
		nodo = y;
		y = y->getParent
	}
	return y->getValue();
}



#endif //ABR_H