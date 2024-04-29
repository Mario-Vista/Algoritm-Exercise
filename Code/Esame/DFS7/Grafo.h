#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include "Nodo.h"
#include "Vertice.h"

using namespace std;

template <class T>
class Grafo
{
    private:
        vector<Nodo<T>> grafo;
        int time;
        queue<T> q;
        void dfsVisit(Vertice<T>* u);
        list<Vertice<T>*> getListaAdj(Vertice<T>* vert);


    public:
        Grafo(){};

        queue<T> getQueue(){return this->q;}
        void addNodo(Nodo<T> nodo){grafo.push_back(nodo);}
        void addArco(Vertice<T>* v1, Vertice<T>*v2);
        void dfs();
        int searchIndex(Vertice<T>* vertice);
        Vertice<T>* searchVert(T value);
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
int Grafo<T> :: searchIndex(Vertice<T>* vertice)
{
    for(int i = 0; i < grafo.size(); i++)
        if(this->grafo.at(i).getSource() == vertice)
            return i;
    return -1;
}

template <class T>
Vertice<T>* Grafo<T> ::searchVert(T value)
{
    for(auto i : grafo)
        if(i.getSource()->getValue() == value)
            return i.getSource();
    return nullptr;
}

template <class T>
void Grafo<T> :: addArco(Vertice<T>* v1, Vertice<T>* v2)
{
    int vertice = searchIndex(v1);
    grafo.at(vertice).append(v2);
}

template <class T>
void Grafo<T> :: dfs()
{
    for(auto i : grafo)
    {
        i.getSource()->setColor(Color::white);
        i.getSource()->setInizioV(0);
    }
    time = 0;
    for(auto i : grafo)
        if(i.getSource()->getColor() == Color::white)
            dfsVisit(i.getSource());
}

template <class T>
void Grafo<T> :: dfsVisit(Vertice<T>* u)
{
    u->setColor(Color::grey);
    u->setInizioV(++time);
    list<Vertice<T>*> adj = getListaAdj(u);
    for(auto i : adj)
        if(i->getColor() == Color :: white)
            dfsVisit(i);
    u->setColor(Color::black);
    u->setFineV(++time);
    q.push(u->getValue());
}

#endif //GRAFO_H