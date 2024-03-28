#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <list>
#include "Vertice.h"

using namespace std;

template <class T>
class Node{
    private:
        Vertice<T>* source;
        list<Vertice<T>*> listaAdj;
    public:
        Node(Vertice<T>* source ): source{source} {};
        Vertice<T>* getSource(){return this->source;}
        list<Vertice<T>*> getListaAdj(){return this->listaAdj;}
        void append(Nodo<T>* nodo){this->listaAdj.push_back(nodo);}
        
};



#endif //NODO_H