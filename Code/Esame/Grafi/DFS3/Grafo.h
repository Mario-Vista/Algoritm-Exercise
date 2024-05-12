#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include "Nodo.h"

using namespace std;

template <class T>
class Grafo
{
    private:
        vector<Nodo<T>> grafo;
        int time;

        void dfsVisit(Vertice<T> *u);
        list<Vertice<T>*> getListaAdj(Vertice<T>* vertice);

    public:
        Grafo(){ };
        void dfs();
        void addNodo(Nodo<T> nodo){grafo.push_back(nodo);}
        void addEdge(int i, Vertice<T>*vertice){grafo.at(i).append(vertice);}

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

    for(auto i : grafo)
    {
        if(i.getSource()->getColor() == Color::WHITE)
            dfsVisit(i.getSource());
    }
}


template <class T>
void Grafo<T> :: dfsVisit(Vertice<T> *u)
{
    u->setColor(Color::GREY);
    u->setInizioV(++time);

    list<Vertice<T>*> adj = getListaAdj(u);

    for(auto v: adj)
        if(v->getColor() == Color::WHITE)
            dfsVisit(v);
    u->setColor(Color::BLACK);
    u->setFineV(++time);
}





#endif //GRAFO_H