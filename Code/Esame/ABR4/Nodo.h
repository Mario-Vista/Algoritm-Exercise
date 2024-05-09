#ifndef NODO_H
#define NODO_H

template <class T>
class Nodo
{
private:
	T value;
	Nodo<T>* left;
	Nodo<T>* right;
	Nodo<T>* parent;

public:
	Nodo(T value): value(value), left(nullptr), right(nullptr), parent(nullptr){};
	Nodo(T value, Nodo<T>* left, Nodo<T>*right, Nodo<T>*parent): value(value), left(left), right(right), parent(parent){};

	T getValue(){return this->value;}
	Nodo<T>* getLeft(){return this->left;}
	Nodo<T>* getRight(){return this->right;}
	Nodo<T>* getParent(){return this->parent;}

	void setValue(T value){this->value = value;}
	void setLeft(Nodo<T>* left){this->left = left;}
	void setRight(Nodo<T>* right){this->right = right;}
	void setParent(Nodo<T>* parent){this->parent = parent;}
};

#endif //NODO_H