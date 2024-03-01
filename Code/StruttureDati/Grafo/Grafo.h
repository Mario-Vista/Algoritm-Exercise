#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <iostream>
#include "Nodo.h"

using namespace std;

template <class T>
class Grafo
{
    private:
        vector<Nodo<T>> grafo;
        vector<vector<int>> w;
        int NUMERO_VERTICI;
    public:
        Grafo(int numeroVertici)
        {
            this->NUMERO_VERTICI = numeroVertici;
            w.resize(NUMERO_VERTICI,vector<int>(NUMERO_VERTICI));
        }

        vector<Nodo<T>> getGrafo(){return this->grafo;}
        vector<vector<int>> getW(){return this->w;}
        const int getNUMEROVERTICI(){return this->NUMERO_VERTICI;}

        void setW(int neW){this->w = neW;}

        void addVertice(Vertice<T>* vertice){this->grafo.push_back(vertice);}
        void addEdge(int i, Vertice<T>* vertice){this->grafo.at(i).append(vertice);}

        void inizializeSingleSource(Vertice<T>*);
        void relax(Vertice<T>*, Vertice<T>*);
        void dijkstra(Vertice<T>*);

        friend ostream& operator<<(ostream& out, const Grafo<T>&obj)
        {
            for(auto i : obj.grafo)
                out << i << endl;
            return out;
        }
};

template <class T>
void Grafo<T>::inizializeSingleSource(Vertice<T>* sorgente)
{
    for(auto i:grafo){
        i.getSorgente()->setPredecessore(nullptr);
        i.getSorgente()->setDistanza(UINT16_MAX);
    }
    sorgente->setDistanza(0);
}

template <class T>
void Grafo<T>::relax(Vertice<T>* u, Vertice<T>* v)
{
    if( v->getDistanza() > u->getDistanza()+ w.at(u->getID()).at(v->getID()))
    {
        v->setDistanza(u->getDistanza()+w.at(u->getID).at(v->getID()));
        v->setPredecessore(u);
    }
}

template <class T>
void Grafo<T>::dijkstra(Vertice<T>* sorgente)
{
    this->initializeSingleSource(sorgente);
}

#endif //GRAFO_H