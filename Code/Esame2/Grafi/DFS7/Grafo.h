#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <list>
#include <vector>
#include "Nodo.h"
#include "Vertice.h"

using namespace std;

template <class T>
class Grafo
{
    private:
    vector<Nodo<T>> grafo;
    list<Vertice<T>*> getListaAdj(Vertice<T>* ve);
    int time;
    void dfsVisit(Vertice<T>*);
    
    public:
    Grafo(){};
    void addNodo(Nodo<T> nod){this->grafo.push_back(nod);}
    void addArco(Vertice<T>*, Vertice<T>*);
    int searchIndex(Vertice<T>*);
    Vertice<T>* searchVert(T value);
    void dfs();

    friend ostream& operator<<(ostream& out, const Grafo<T>&obj)
    {
        for(auto i : obj.grafo)
            out << i << endl;
        return out;
    }
};

template <class T>
list<Vertice<T>*> Grafo<T> :: getListaAdj(Vertice<T>* ve)
{
    for(auto i : grafo) 
        if(i.getSource() == ve)
            return i.getListaAdj();
    return grafo.at(0).getListaAdj(); 
}
    
template <class T>
void Grafo<T> ::dfsVisit(Vertice<T>* u)
{
    u->setColor(Color::grey);
    u->setInizioV(++time);
    list<Vertice<T>*> adj = getListaAdj(u);
    for(auto i : adj)
        if(i->getColor() == Color::white)
        {
            i->setPredecessore(u);
            dfsVisit(i);
        }
    u->setColor(Color::black);
    u->setFineV(++time);
}


template <class T>
void Grafo<T> :: addArco(Vertice<T>*v1, Vertice<T>*v2)
{
    int index = searchIndex(v1);
    grafo.at(index).append(v2);
}


template <class T>
int Grafo<T> :: searchIndex(Vertice<T>*v1)
{
    for(int i = 0; i < grafo.size(); i ++)
        if(grafo.at(i).getSource() == v1)
            return i;
    return -1;
}

template <class T>
Vertice<T>* Grafo<T> :: searchVert(T value)
{
    for(auto i : grafo)
        if(i.getSource()->getValue() == value)
            return i.getSource();
    return nullptr;
}


template <class T>
void Grafo<T> :: dfs()
{
    for(auto i : grafo)
    {
        i.getSource()->setColor(Color::white);
        i.getSource()->setInizioV(0);
        i.getSource()->setFineV(0);
    }
    time = 0;
    for(auto i : grafo)
        if(i.getSource()->getColor() == Color::white)
            dfsVisit(i.getSource());
}

#endif //GRAFO_H