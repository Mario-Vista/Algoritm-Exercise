#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <queue>
#include "Nodo.h"
#include "Vertice.h"
#include <list>

using namespace std;

template <class T>
class Grafo
{
    private:
        vector<Nodo<T>> grafo;
        list<Vertice<T>*> getListaAdj(Vertice<T>* vertice);
        int time;
        queue<T> q;
        void dfsVisit(Vertice<T>* u);

    public:
        Grafo(){ };
        void dfs();
        queue<T> getQueue(){return this->q;}
        void addNodo(Nodo<T> nodo){this->grafo.push_back(nodo);}
        void addEdge(int i, Vertice<T>* vertice){this->grafo.at(i).append(vertice);}
        int searchAddress(Vertice<T>*vertice);
        Vertice<T>* getIndirizzoVertice(T value);
        friend ostream& operator<<(ostream& out, const Grafo<T> &obj)
        {
            for(auto i : obj.grafo)
                out << i << endl;
            return out;
        }
};

template <class T>
list<Vertice<T>*> Grafo<T> :: getListaAdj(Vertice<T>* vertice)
{
    for(auto i : grafo)
        if(i.getSource() == vertice)
            return i.getListaAdj();
    return this->grafo.at(0).getListaAdj();
}

template <class T>
void Grafo<T> :: dfs()
{
    for (auto i : grafo)
    {
        i.getSource()->setColor(Color::WHITE);
        i.getSource()->setPredecessore(nullptr);
        time = 0;
    }
    for(auto i : grafo)
        if(i.getSource()->getColor() == Color::WHITE)
            this->dfsVisit(i.getSource());

}

template <class T>
void Grafo<T> :: dfsVisit(Vertice<T>* u)
{
    u->setColor(Color::GREY);
    u->setInizioV(++time);
    
    list<Vertice<T>*> adj = this->getListaAdj(u);

    for(auto i : adj)
        if(u->getColor() == Color::WHITE)
            this->dfsVisit(i);
    u->setColor(Color::BLACK);
    u->setFineV(++time);
    q.push(u->getValue());
}

template <class T>
int Grafo<T> :: searchAddress(Vertice<T>*vertice)
{
    for(int i = 0; i < grafo.size(); i++)
        if(this->grafo.at(i).getSource()->getValue() == vertice->getValue())
            return i;
    return -1;
}

template <class T>
Vertice<T>* Grafo<T> :: getIndirizzoVertice(T value)
{
    for(auto i : grafo)
    {
        if(i.getSource()->getValue() == value)
            return i.getSource();
    }
    return nullptr;
}

#endif //GRAFO_H