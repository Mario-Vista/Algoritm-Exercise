#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include "Vertice.h"
#include "Nodo.h"

using namespace std;

template <class T>
class Grafo
{
    private:
        int time;
        vector<Nodo<T>> grafo;
        list<Vertice<T>*> getListaAdj(Vertice<T>*);
        queue<T> q;
        void dfsVisit(Vertice<T>*);
    public:
        Grafo(){};
        void dfs();
        void getQ(){return this->q;}
        int searchIndex(Vertice<T>*);
        Vertice<T>* searchVerti(T);
        void addNodo(Nodo<T> nodo){this->grafo.push_back(nodo);}
        void addArco(Vertice<T>*, Vertice<T>*);
};

template <class T>
list<Vertice<T>*> Grafo<T> :: getListaAdj(Vertice<T>* vert)
{
    for(auto i : grafo)
        if(i.getSource() == vert)
            return i.getListaAdj();
    return this->grafo.at(0).getListaAdj();
}

template <class T>
int Grafo<T> :: searchIndex(Vertice<T>* vert)
{
    for(int i = 0, i < grafo.size(); i++)
        if(grafo.at(i).getSource() == vert)
            return i;
    return -1;
}

template <class T>
Vertice<T>* Grafo<T> :: searchVerti(T val)
{
    for(auto i : grafo)
        if(i.getSource()->getValue() == val)
            return i.getSource();
    return nullptr;
}

template <class T>
void Grafo<T> :: addArco(Vertice<T>*v1, Vertice<T>*v2)
{
   int index = searchIndex(v1);
   this->grafo.at(index).append(v2); 
}

template <class T>
void Grafo<T> ::  dfs()
{
    for(auto i : grafo)
    {
        i.getSource()->setColor(Color::white);
        i.getSource()->setInizioV(0);
        i.getSource()->setFineV(0);
        i.getSource()->setP(nullptr)
   }
    time = 0;
   for(auto i : grafo)
    if(i.getSource()->getColor() == Color::white)
        dfsVisit(i.getSource());
}

template <class T>
void Grafo<T> :: dfsVisit(Vertice<T>* u)
{
    u->setColor(Color::white);
    u->setInizioV(++time);
    list<Vertice<T>*> adj = getListaAdj(u);
    for(auto v : adj)
        if(v->getColor() == Color::white)
        {
            v->setP(u);
            dfsVisit(v);
        }
    u->setColor(Color::black);
    u->setFineV(++time);
    q.push(u->getValue());
}








#endif //GRAFO_H