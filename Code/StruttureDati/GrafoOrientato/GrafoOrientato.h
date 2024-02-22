#ifndef GRAFOORIENTATO_H
#define GRAFOORIENTATO_H

#include <vector>
#include "Node.h"
#include "Vertice.h"
#include <iostream>
#include <limits>
#include <queue>
#include <list>
#include <map>
#include "../Stack/Stack.h"

using namespace std;

template <class T>
class GrafoOrientato
{
    private:
        vector<Node<T>> grafo;

        bool cycle;
        int timeDfs;
        int counterSCC;

        Stack<Vertice<T>*> L;       //stack utilizzato per ordinamento topologico
        vector<Node<T>> grafoTransposto;
        vector<Node<T>> SCC;
        map<Vertice<T>*, int> amap;     //mappa che associa vertici ai loro indici nel grafo


        list<Vertice<T>*> getListaAdj(Vertice<T>*);
        list<Vertice<T>*> getListaAdjGT(Vertice<T>*);

        void dfsVisit(Vertice<T>*);
        string classificazioneArchi(Vertice<T>*, Vertice<T>*);

        bool dfsCiclo();
        

};

#endif //GRAFOORIENTATO_H