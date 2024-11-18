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
    list<Vertice<T>*> getAdjList(Vertice<T>*);

    public:
    Grafo(){};

    void addNodo(Nodo<T> nodo){this->grafo.push_back(nodo);}
    void addEdge(Vertice<T>* v1, Vertice<T>* v2);
    void bfs(Vertice<T>* source);
    int searchAddress(Vertice<T>* vertice);
    Vertice<T>* getIndirizzoVertice(T value);

    friend ostream& operator<<(ostream& out, const Grafo<T>& obj)
    {
        for(auto i : obj.grafo)
            out << i << endl;
        return out;
    }
};

template <class T>
list<Vertice<T>*> Grafo<T> :: getAdjList(Vertice<T>* vert)
{
    for(auto i : grafo)
        if(i.getSource() == vert)
            return i.getListaAdj();
    return this->grafo.at(0).getListaAdj();
}

template <class T>
void Grafo<T> :: bfs(Vertice<T>* source)
{
    for(auto i : grafo)
    {
        i.getSource()->setColor(Color::white);
        i.getSource()->setDistanza(0);
        i.getSource()->setPredecessore(nullptr);
    }

    source->setColor(Color::grey);
    source->setDistanza(0);
    source->setPredecessore(nullptr);
    queue<Vertice<T>*> q;
    q.push(source);

    while(!q.empty())
    {
        auto u = q.front();
        q.pop();
        auto adj = getAdjList(u);
        for(auto v : adj)
        {
            v->setColor(Color::grey);
            v->setDistanza(u->getDistanza()+1);
            v->setPredecessore(u);
            q.push(v);
        }
        u->setColor(Color::black);
    }
}

template<class T>
int Grafo<T> :: searchAddress(Vertice<T>* vertice)
{
    for(int i = 0; i < this->grafo.size(); i++)
        if(this->grafo.at(i).getSource() == vertice)
            return i;
    return -1;
} 

template <class T>
Vertice<T>* Grafo<T> :: getIndirizzoVertice(T value)
{
    for(auto i : grafo)
        if(i.getSource()->getValue() == value)
            return i.getSource();
    return nullptr;
}

template <class T>
void Grafo<T> :: addEdge(Vertice<T>* v1, Vertice<T>* v2)
{
    int index = searchAddress(v1);
    this->grafo.at(index).append(v2);
}


#endif //GRAFO_H