#ifndef NODE_H
#define NODE_H

#include "Vertex.h"
#include <list>
#include <iostream>

using namespace std;

template <class T>
class Node
{
    public:
        Vertex<T> *source;
        list<Vertex<T>*> adjList;
    private:
        Node(Vertex<T>* source):source{source}{};

        Vertex<T>* getSource(){return this->source;}
        list<Vertex<T>*> getAdjList(){return this->adjList;}

        void append(Vertex<T>* vertex){this->adjList.push_back(vertex);}

        friend ostream& operator<<(ostream& out, const Node<T>& obj)
        {
            out << *obj.source << " --> ";
            for(auto i:obj.adjList)
                out << *i << " --> ";
            out << "Null";
            return out;
        }   
};

#endif //NODE_H