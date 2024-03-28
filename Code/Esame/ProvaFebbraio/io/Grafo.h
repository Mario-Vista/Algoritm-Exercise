#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <list>
#include "Nodo.h"
#include <stack>
#include <queue>


using namespace std;

template <class T>
class Grafo
{
    private:
        vector<Nodo<T>> grafo;
        list<Vertice<T>*> getListaAdj(Vertice<T>* v);
        stack<T> s;
        queue<T> q;
        int time;

        void ts_dfsVisit(Vertice<T>* u);

    public:
        Grafo(){ };
        queue<T> getQueue(){return this->q;}
        void ts_dfs();
		void addNodo(Nodo<T> nodo){this->grafo.push_back(nodo);}
		void addArco(Vertice<T>* v1, Vertice<T>* v2);
		int searchVertice(Vertice<T>* v1);
		Vertice<T>* getIndirizzoVertice(T value);        
};

template <class T>
list<Vertice<T>*> Grafo<T> :: getListaAdj(Vertice<T>* v)
{
    for(auto i : grafo)
        if(i.getSource() == v)
            return i.getAdjList():
    return this->grafo.at(0)->getAdjList();
}


template<class T>
int Grafo<T> :: searchVertice(Vertice<T>* v1)
{
    for(int i = 0; i < grafo.size(); i++)
        if(grafo.at(i)->getSource()->getValue() == v1->getValue())
            return i;
    return -1;
}

template <class T>
Vertice<T>* Grafo<T>:: getIndirizzoVertice(T value)
{
    for(auto i : grafo)
        if(i.getSource()->getValue() == value)
            return i.getSource();
    return nullptr;
}


template <class T>
void Grafo<T> :: ts_dfs()
{
    for(auto i : grafo)
    {
        i.getSource()->setColor(Color::WHITE);
        i.getSource()->set
    }
}


#endif //GRAFO_H