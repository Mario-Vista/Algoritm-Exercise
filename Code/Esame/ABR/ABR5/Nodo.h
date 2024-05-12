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
	Nodo<T>(T value): value(value), left(nullptr), right(nullptr), parent(nullptr){};
	Nodo<T>(T value, Nodo<T>* left, Nodo<T>* right, Nodo<T>* parent): value(value), left(left), right(right), parent(parent){};

	T getValue(){return this->value;}
	Nodo<T>* getLeft(){return this->left;}
	Nodo<T>* getRight(){return this->right;}
	Nodo<T>* getParent(){return this->parent;}

	void setValue(T value){this->value = value;}
	void setLeft(Nodo<T>* l){this->left = l;}
	void setRight(Nodo<T>* r){this->right = r;}
	void setParent(Nodo<T>* p){this->parent = p;}
};


#endif //NODO_H