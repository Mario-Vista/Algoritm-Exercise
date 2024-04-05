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
        list<Vertice<T>*> listaAdjN;
    
    public:
        Nodo(Vertice<T>* source):source{source}{ };
        Vertice<T>* getSource(){return this->source;}
        list<Vertice<T>*> getListaAdjN(){return this->listaAdjN;}

        void append(Vertice<T>* source){this->listaAdjN.push_back(source);}

        friend ostream& operator<<(ostream& out, const Nodo<T>& obj)
        {
            out << *obj.source << " -> ";
            for(auto i:obj.listaAdjN)
                out << *i << " -> ";
            out << "Null";
            return out;
        }
};


#endif //NODO_H