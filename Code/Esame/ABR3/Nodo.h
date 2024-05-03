#ifndef NODO_H
#define NODO_H

template <class T>
class Nodo
{
private:
	T value;

	Nodo<T> *parent;
	Nodo<T> *left;
	Nodo<T> *right;

public:
	Nodo(T value): value(value), parent(nullptr), right(nullptr), left(nullptr) {};
	Nodo(T value, Nodo<T>* parent, Nodo<T>* left, Nodo<T>* right): value(value), parent(parent), right(right), left(left) {};

	T getValue(){return this->value;}
	Nodo<T>* getParent(){return this->parent;}
	Nodo<T>* getLeft(){return this->left;}
	Nodo<T>* getRight(){return this->right;}

	void setValue(T value){this->value = value;}
	void setParent(Nodo<T>* parent){this->parent = parent;}
	void setLeft(Nodo<T>* left){this->left = left;}
	void setRight(Nodo<T>* right){this->right = right;}
};



#endif //NODO_H