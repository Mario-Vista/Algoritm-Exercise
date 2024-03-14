#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <list>
#include "Vertice.h"

using namespace std;

template <class T>
class Nodo
{
    private:
        Vertice<T> *source;
        list<Vertice<T>*> adjList;

    public:
        Nodo(Vertice<T>* source): source{source}{};
        Vertice<T>* getSource(){return this->source;}
        list<Vertice<T>*> getAdjList(){return this->adjList;}

        void append(Vertice<T>*vertice){adjList.push_back(vertice);}

        friend ostream& operator<<(ostream& out, const Nodo<T>& obj)
        {
            out << *obj.source << " -> ";
            for(auto i : obj.adjList)
                out << *i << " -> ";
            out << " Null ";
            return out;
        }
};

#endif //NODO_H