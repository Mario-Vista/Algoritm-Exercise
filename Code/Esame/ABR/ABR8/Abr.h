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
	T maximum(Nodo<T>*);
	T minimum(Nodo<T>*);

public:
	Abr(Nodo<T>* root){this->root = root;}
	Abr() {this->root = nullptr;}

	void insert(T);

	T maximum();
	T minimum();

	T successor(Nodo<T>*);
	T predecessor(Nodo<T>*);

	void inOrderVisit();
	void preOrderVisit();
	void postOrderVisit();

};

template <class T>
void Abr<T> :: insert(T value)
{
	if(this->root == nullptr)
		root = new Nodo(value);
	else
		this->insert(value, nullptr, root);
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
	{
		curr = new Nodo(value);
	}
	else
	{
		curr = new Nodo(value);
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
	return nodo->getValue();
}

template <class T>
T Abr<T> :: maximum()
{
	return maximum(this->root);
}

template <class T>
T Abr<T> :: minimum()
{
	return minimum(this->root);
}

template <class T>
T Abr<T> :: predecessor(Nodo<T>* nodo)
{
	if(nodo->getLeft() != nullptr)
		return maximum(nodo->getLeft());
	auto y = nodo;
	while(y != nullptr && y->getLeft() == nodo)
	{
		nodo = y;
		y = nodo->getParent();
	}
	return y->getValue();
}

template <class T>
T Abr<T> :: successor(Nodo<T>* nodo)
{
	if(nodo->getRight() != nullptr)
		return minimum(nodo->getLeft());
	auto y = nodo;
	while(y != nullptr && y->getRight() == nodo)
	{
		nodo = y;
		y = nodo->getParent();
	}
	return y->getValue();
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






#endif //ABR_H