#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <list>
#include "Nodo.h"

using namespace std;

template <class T>
class Grafo
{
    private:
    vector<Nodo<T>> grafo;
    list<pair<Vertice<T>*, int>> getListaAdj(Vertice<T>*);
    int time;
    void dfsVisit(Vertice<T>*);
    public:
    Grafo(){};
    void addArco(Vertice<T>*v1, Vertice<T>*v2, int peso);
    void addNodo(Nodo<T> nodo){grafo.push_back(nodo);}
    void dfs();
    int searchIndex(Vertice<T>*);
    Vertice<T>* searchVert(T);
    friend ostream& operator<<(ostream& out, const Grafo<T>& obj) {
        for (auto& i : obj.grafo)
            out << i << endl;
        return out;
    }
};

template <class T>
list<pair<Vertice<T>*, int>> Grafo<T>:: getListaAdj(Vertice <T>* vert)
{
    for(auto &i :grafo)
        if(i.getSource() == vert)
            return i.getListaAdj();
    return {};
}

template <class T>
void Grafo<T> :: addArco(Vertice<T>*v1, Vertice<T>*v2, int peso)
{
    int index = searchIndex(v1);
    grafo.at(index).append(v2, peso);
}

template <class T>
void Grafo<T> :: dfsVisit(Vertice<T>* u) {
        u->setColor(Color::grey);
        u->setInizioV(++time);
        list<pair<Vertice<T>*, int>> adj = getListaAdj(u);
        for (auto v : adj)
            if (v.first->getColor() == Color::white)
                dfsVisit(v.first);
        u->setColor(Color::black);
        u->setFineV(++time);
}

template <class T>
void Grafo<T> :: dfs()
{
for (auto& i : grafo)
{
    i.getSource()->setColor(Color::white);
    i.getSource()->setInizioV(0);
    i.getSource()->setFineV(0);
    i.getSource()->setP(nullptr);
}
time = 0;
for (auto& i : grafo)
    if (i.getSource()->getColor() == Color::white)
        dfsVisit(i.getSource());
}

template <class T>
Vertice<T>* Grafo<T> :: searchVert(T val) {
        for (auto i : grafo)
            if (i.getSource()->getValue() == val)
                return i.getSource();
        return nullptr;
}

template <class T>
int Grafo<T> :: searchIndex(Vertice<T>*vert)
{
    for(int i = 0; i < grafo.size(); i++)
        if(grafo.at(i).getSource() == vert)
            return i;
    return -1;
}


#endif //GRAFO_H