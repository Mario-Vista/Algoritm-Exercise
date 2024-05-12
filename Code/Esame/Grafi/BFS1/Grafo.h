#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <queue>
#include "Nodo.h"
#include "Vertice.h"

using namespace std;

template <class T>
class Grafo
{
    private:
        vector<Nodo<T>> grafo;
        list<Vertice<T>*> getListaAdj(Vertice<T>*);
        queue<T> q;

    public:
        Grafo(){ };
        queue<T> getQ(){return this->q;}
        void addNodo(Nodo<T> nodo){this->grafo.push_back(nodo);}
        void addEdge(int i, Vertice<T>* vert){this->grafo.at(i).append(vert);}
        void bfs(Vertice<T>* source);
        int searchAddress(Vertice<T>* vertice);
        Vertice<T> *getIndirizzoVertice(T value);
        friend ostream& operator<<(ostream& out, const Grafo<T> &obj)
        {
            for(auto i : obj.grafo)
            {
                out << i << endl;
            }
            return out;
        }
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
void Grafo<T> :: bfs(Vertice<T> *source)
{
    for(auto i : grafo)
    {
        i.getSource()->setColor(Color::WHITE);
        i.getSource()->setPredecessore(nullptr);
        i.getSource()->setDistanza(UINT16_MAX);
    }
    source->setColor(Color::GREY);
    source->setPredecessore(nullptr);
    source->setDistanza(UINT16_MAX);

    queue<Vertice<T>*> q;
    q.push(source);

    while(!q.empty())
    {
        auto u = q.front();
        q.pop();

        auto adj = getListaAdj(u);

        for(auto v:adj)
        {
            v->setColor(Color::GREY);
            v->setPredecessore(u);
            v->setDistanza(u->getDistanza()+1);
            q.push(v);
        }
        u->setColor(Color::BLACK);
    }
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
        if(i.getSource()->getValue() == value)
            return i.getSource();
    }
    return nullptr;
}



#endif //GRAFO_H