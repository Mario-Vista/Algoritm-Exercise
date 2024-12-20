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
    list<Vertice<T>*> getListaAdj(Vertice<T>*);
    int time;
    void dfsVisit(Vertice<T>*);

    public:
    Grafo(){};
    void dfs();
    void addNodo(Nodo<T> nodo){this->grafo.push_back(nodo);}
    void addArco(Vertice<T>* v1, Vertice<T>* v2);
    int searchIndex(Vertice<T>*);
    Vertice<T>* searchVert(T);

    friend ostream& operator<<(ostream& out, const Grafo<T>& obj)
    {
        for(auto i : obj.grafo)
            out << i << endl;
        return out;
    }

};

template <class T>
list<Vertice<T>*> Grafo<T> ::getListaAdj(Vertice<T>* vert)
{
    for(auto i:grafo)
        if(i.getSource() == vert)
            return i.getListaAdj();
    return this->grafo.at(0).getListaAdj();
}

template <class T>
void Grafo<T> :: addArco(Vertice<T>* v1, Vertice<T>* v2)
{
    auto index = searchIndex(v1);
    this->grafo.at(index).append(v2);
}

template <class T>
int Grafo<T> :: searchIndex(Vertice<T>*vert)
{
    for(int i = 0; i < grafo.size(); i++)
        if(this->grafo.at(i).getSource() == vert)
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
        i.getSource()->setP(nullptr);
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

    for(auto v:adj)
        if(v->getColor() == Color::white)
        {
            v->setP(u);
            dfsVisit(v);
        }
    u->setColor(Color::black);
    u->setFineV(++time);
}





#endif //GRAFO_H