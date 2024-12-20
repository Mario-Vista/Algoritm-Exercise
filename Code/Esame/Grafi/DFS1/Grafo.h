#ifndef GRAFO_H
#define GRAFO_H

//d7#BXZrzgtyUfh

#include <iostream>
#include <vector>
#include "Nodo.h"

using namespace std;

template <class T>
class Grafo
{
    private:
        vector<Nodo<T>> grafo;
        int time;   //per dfs

        void dfsVisit(Vertice<T>*);
        list<Vertice<T>*> getListaAdj(Vertice<T>*);

    public:
        Grafo(){ };
        void addNodo(Nodo<T> nodo){grafo.push_back(nodo);}
        void addEdge(int i, Vertice<T>* vertice){grafo.at(i).append(vertice);}

        void dfs();

        friend ostream& operator<<(ostream& out, const Grafo<T> &obj)
        {
            for(auto i: obj.grafo)
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
    return grafo.at(0).getListaAdj();

}


template <class T>
void Grafo<T> :: dfs()
{
    for(auto i: grafo)
    {
        i.getSource()->setColor(Color::WHITE);
        i.getSource()->setPredecessore(nullptr);
        time = 0;
    }
    for(auto u: grafo)
        if(u.getSource()->getColor() == Color::WHITE)
            this->dfsVisit(u.getSource());
    
}

template <class T>
void Grafo<T> :: dfsVisit(Vertice<T>* u)
{
    u->setColor(Color::GREY);
    u->setInizioV(++time);

    list<Vertice<T>*> adj = getListaAdj(u);

    for(auto v:adj)
        if(v->getColor() == Color::WHITE)
            this->dfsVisit(v);
    u->setColor(Color::BLACK);
    u->setFineV(++time);
}



#endif //GRAFO_H
