#ifndef NODO_H
#define NODO_H

#include "Vertice.h"
#include <iostream>
#include <list>

using namespace std;

template <class T>
class Nodo
{
    private:
    Vertice<T>* source;
    list<Vertice<T>*> listaAdj;

    public:
        Nodo(Vertice<T>* sorgente):source{sorgente}{};

        Vertice<T>*getSource(){return this->source;}
        list<Vertice<T>*> getListaAdj(){return this->listaAdj;}

        void append(Vertice<T>* vertice){this->listaAdj.push_back(vertice);}

        friend ostream& operator<<(ostream& out, const Nodo<T>& obj)
        {
            out << *obj.source << " --> ";
            for(auto i : obj.listaAdj)
                out << *i << " --> ";
            out << "NULL";
            return out;
        }
};

#endif //NODO_H

