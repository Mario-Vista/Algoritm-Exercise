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
		Node(T value): value(value), parent(nullptr), left(nullptr), right(nullptr){};
		Node(T value,  Node<T>* parent, Node<T>* left,  Node<T>* right): value(value), parent(parent), left(left), right(right) {};

		//getter
		T getValue(){return this->value;}
		Nodo<T> *parent(){return this->value;}
		Nodo<T> *left(){return this->left;}
		Nodo<T> *right(){return this->right;}

		//setter
		void setValue(T value){this->value = value;}
		void setParent(Nodo<T>* parent){this->parent = parent;}
		void setLeft(Nodo<T>* left){this->left = left;}
		void setRight(Nodo<T>* right){this->right = right;}
}


#endif //NODO_H
