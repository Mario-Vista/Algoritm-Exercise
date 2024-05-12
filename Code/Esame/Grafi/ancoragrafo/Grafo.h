#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include "Vertice.h"
#include "Nodo.h"
#include <vector>
#include <list>

using namespace std;

template <class T>
class Grafo
{
    private:
        vector<Nodo<T>> grafo;
        list<Vertice<T>*> getListaAdjG();

        void dfsVisit(Vertice<T>* u);
    public:
        Grafo(){ };
        

};

#endif //GRAFO_H