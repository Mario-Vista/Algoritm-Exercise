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
    list<Vertice<T>*> listaAdj;

    public:
    Nodo(Vertice<T>* vert): source(vert){};
    Vertice<T>* getSource(){return this->source;}
    list<Vertice<T>*> getListaAdj(){return this->listaAdj;}

    void append(Vertice<T>* vert){this->listaAdj.push_back(vert);}

    friend ostream& operator<<(ostream& out, const Nodo<T>&obj)
    {
        out << *obj.source << "->";
        for(auto i : obj.listaAdj)
            out << *i << "->";
        out << "null";
        return out;
    }

};


#endif //NODO_H