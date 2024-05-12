#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <queue>
#include "Nodo.h"

using namespace std;

template <class T>
class Grafo
{
    private:
        vector<Nodo<T>> grafo;
        int time;
        queue<T> myQueue;
        list<Vertice<T>*> getListaAdj(Vertice<T>* vertice);
        void dfsVisit(Vertice<T> *u);
    
    public:
        Grafo(){ };
        void dfs();
        queue<T> getQueue(){return this->myQueue;}
        void addNodo(Nodo<T> nodo){grafo.push_back(nodo);}
        void addEdge(int i, Vertice<T>* vertice){grafo.at(i).append(vertice);}
        int searchAddress(Vertice<T>* vertice);
        Vertice<T>* getIndirizzoVertice(T value);

 
        friend ostream& operator<<(ostream& out, const Grafo<T>& obj)
        {
            for(auto i : obj.grafo)
                out << i << endl;
            return out;
        }
};


template<class T>
list<Vertice<T>*> Grafo<T> :: getListaAdj(Vertice<T>* vertice)
{
    for(auto i : grafo)
        if(i.getSource() == vertice)
            return i.getAdjList();
    return grafo.at(0).getAdjList();
}



template <class T>
void Grafo<T> :: dfs()
{
    for(auto i : grafo)
    {
        i.getSource()->setColor(Color::WHITE);
        i.getSource()->setPredecessore(nullptr); 
        time = 0;
    }

    for(auto i: grafo)
        if(i.getSource()->getColor() == Color::WHITE)
            dfsVisit(i.getSource());
}

template <class T>
void Grafo<T> :: dfsVisit(Vertice<T>* u)
{
    u->setColor(Color::GREY);
    u->setInizioV(++time);
    list<Vertice<T>*> adj = this->getListaAdj(u);

    for(auto i : adj)
        if(i->getColor() == Color::WHITE)
            dfsVisit(i);
    u->setColor(Color::BLACK);
    u->setFineV(++time);
    myQueue.push(u->getValue());
}


template <class T>
int Grafo<T> :: searchAddress(Vertice<T>* vertice)
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
        if(i.getVertice()->getValue() == value)
            return i.getVertice();
    }
    return nullptr;
}

#endif //GRAFO_H