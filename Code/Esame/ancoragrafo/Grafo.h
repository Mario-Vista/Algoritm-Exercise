#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <list>
#include "Nodo.h"
#include "Vertice.h"

using namespace std;

template <class T>
class Grafo
{
    private:
        vector<Nodo<T>> grafo;
        list<Vertice<T>*> getListaG(Vertice<T>* vertice);
        int time;
        void dfsVisit(Vertice<T>* u);

    public: 
        Grafo(){ };
        void addArco(Nodo<T> v1, Nodo<T> v2);
        void addNodo(V)



        void dfs();

};






#endif //GRAFO_H