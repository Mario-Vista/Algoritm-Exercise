#ifndef ABR_H
#define ABR_H

#include <iostream>
#include "Nodo.h"

using namespace std;

template class Abr
{
	private:
		Nodo<T>* root;
		void insert(T, Nodo<T>*, Nodo<T>*)
		void insertNodo(T, Nodo<T>*, Nodo<T>*);

		void preOrder(Nodo<T>*);
		void inOrder(Nodo<T>*);
		void postOrder(Nodo<T>*);

	public:
		Abr(Node<T>* root);
		Abr();

		Node<T>* getRoot(){return this->root;}

		void insert(T);

		T minimum();
		T maximum();
		T minumum(Node<T>*);
		T maximum(Node<T>*);

		T successor(Node<T>*);
		T predecessor(Node<T>*);

		void preOrder();
		void postOrder();
		void inOrder();
}

template <class T>
Abr<T> :: Abr(Node<T>* root)
{
	this->root = root;
}

template <class T>
Abr<T> :: Abr()
{
	this->root = nullptr;
}

template <class T>
void Abr<T> :: insert(T value)
{
	if(this->root == nullptr)
		this->root = new Nodo<T>(value);
	else
		this->insert(value, nullptr, this->root);
}

template <class T>
void Abr<T> :: insert(T value, Nodo<T>* prev, Node<T>* curr)
{
	if(curr == nullptr)
		this->insertNodo(value, prev, curr);
	else if(key > curr->getValue())
		this->insert(value, curr, curr->getRight());
	else
		this->insert(value, curr, curr->getLeft());
}


template <class T>
void Abr<T> :: insertNodo(T value, Nodo<T>* prev, Nodo<T>* curr)
{
	if(prev == nullptr)
		curr = new Nodo<T>(value);
	else
		curr = new Nodo<T>(value);
		curr->setParent(prev);
		if(key > prev->getValue())
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
T Abr<T> :: predecessor(Nodo<T>* nodo)
{
	if(nodo->getLeft() != nullptr)
		return this->maximum(nodo->getLeft();
	auto y = nodo->getParent();
	while(y != nullptr && nodo == y->getLeft())
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
		return this->minimum(nodo->getRight());
	auto y = nodo->getParent()
	while(y != nullptr && nodo == y->getRight())
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
void Abr<T> :: preOrder(Node<T>* curr)
{
	if(curr == nullptr)
		return;
	cout << curr->getValue() << " ";
	this->preOrder(curr->getLeft());
	this->preOrder(curr->getRight();
}

template <class T>
void Abr<T> :: inOrder(Node<T>* curr)
{
	if(curr == nullptr)
		return;
	this->inOrder(curr->getLeft());
	cout << curr->getValue() << " ";
	this->inOrder(curr->getRight();
}

template <class T>
void Abr<T> :: postOrder(Node<T>* curr)
{
	if(curr == nullptr)
		return;
	this->postOrder(curr->getLeft());
	this->postOrder(curr->getRight();
	cout << curr->getValue() << " ";
}


#endif //ABR_H
