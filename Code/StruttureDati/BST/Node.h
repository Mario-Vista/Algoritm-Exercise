#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
   private:
    T value;
    Node<T> *parent;
    Node<T> *left;
    Node<T> *right;

    public:
        Node(T value):value(value),parent(nullptr),left(nullptr),right(nullptr){};
        Node(T value, Node<T> *parent, Node<T> *left, Node<T> *right):value(value),parent(parent),left(left),right(right){};

        T getValue(){return this->value;}
        Node<T>* getParent(){return this->parent;}
        Node<T>* getLeft(){return this->left;}
        Node<T>* getRight(){return this->right;}

        void setValue(T value){this->value = value;}
        void setParent(Node<T>* parent){this->parent = parent;}
        void setLeft(Node<T> *left){this->left = left;}
        void setRight(Node<T> *right){this->right = right;}
};

#endif //NODE_H