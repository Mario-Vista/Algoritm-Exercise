#ifndef NODO_H
#define NODO_H

#include "Vertice.h"
#include <list>
#include <iostream>

using namespace std;

template <class T>
class Nodo
{
    private:
        Vertice<T>* sorgente;
        list<Vertice<T>*> listaAdiacenze;
    public:
        Nodo(Vertice<T>* sorgente):sorgente{sorgente}{}
        Vertice<T>* getSorgente(){return this->sorgente;}
        list<Vertice<T>*> getListaAdiacenza(){return this->listaAdiacenze;}

        void append(Vertice<T>* vertice){this->listaAdiacenze.push_back(vertice);}

        friend ostream& operator<<(ostream& out, const Nodo<T>&obj)
        {
            out << *obj.sorgente << " --> ";
            for(auto i: obj.listaAdiacenze)
                out << *i << " --> ";
            out << "Null";
            return out;
        }   
};




#endif //NODO_H