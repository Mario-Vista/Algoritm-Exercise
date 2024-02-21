#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
    private:
        Node<T>* next;
        T* data;

    public:
        Node<T>(Node<T> *next, T* info);
        ~Node();

        void setNext(Node<T> next){this->next=next;}
        void setData(T info){this->data = info;}

        Node<T>* getNext(){return this->next;}
        T* getData(){return this->data;}
};


template <class T>
Node<T>::Node(Node<T>* next, T* info)
{
    this->next = next;
    this->data = info;
}

template <class T>
Node<T>::~Node()
{
    delete next;
    delete data;
} 



#endif //NODE_H