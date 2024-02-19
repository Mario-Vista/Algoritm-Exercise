#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <iostream>

template <class T>
class LinkedList
{  
    private:
        Node<T>* head;
        Node<T>* tail;

        void insHead(T* newNode);
        void insTail(T* newNode);
    
    public:
        LinkedList();
        ~LinkedList();

        //setter
        void setHead(Node<T>* newNode){this->head = newNode;}
        void setTail(Node<T>* newNode){this->tail = newNode;}

        //getter
        Node<T>* getHead(){return this->head;}
        Node<T>* getTail(){return this->tail;}

        void insNodo(Node<T>* tail, T* newNode);

        void printList();

};

template <class T>
LinkedList<T>::LinkedList()
{
    this->head = nullptr;
    this->tail = head;
}

template <class T>
LinkedList<T> ::~LinkedList()
{
    while(this->head != nullptr)
    {
        auto *tmp=head;
        head = head->getNext();
        delete tmp;
    }
}

template <class T>
void LinkedList<T>::insHead(T* newNode)
{
    Node<T> *node = new Node<T>(nullptr, newNode);
    node->setNext(head);
    this->head = node;
}

template <class T>
void LinkedList<T>::insTail(T* newNode)
{
    Node<T> *node= new Node<T>(nullptr, newNode);
    tail->setNext(node);
    tail = node;
}

template <class T>
void LinkedList<T> :: insNodo(Node<T>* tail, T* newNode)
{
    if(tail = nullptr)
        insHead(newNode);
    else
        insTail(newNode);
}

template <class T>
void LinkedList<T> :: printList()
{
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->getData() << " ";
            current = current->getNext();
        }
        std::cout << std::endl;
}


#endif //LINKEDLIST_H