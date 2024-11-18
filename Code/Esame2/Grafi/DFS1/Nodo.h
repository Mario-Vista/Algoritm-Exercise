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
    Vertice<T>* source;
    list<Vertice<T>*> listAdj;

    public:
    Nodo(Vertice<T>* source): source(source){};
    Vertice<T>* getSource(){return this->source;}
    list<Vertice<T>*> getListaAdj(){return this->listAdj;}

    void append(Vertice<T>* vert){this->listAdj.push_back(vert);}

    friend ostream& operator<<(ostream& out, const Nodo<T>& obj)
    {
        out << *obj.source << "->";
        for(auto i : obj.listAdj)
            out << *i << "->";
        out << "null";
        return out;
    }
};


#endif //NODO_H