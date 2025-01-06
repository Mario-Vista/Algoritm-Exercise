#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include "Nodo.h"
#include <vector>

using namespace std;

template <class T>
class Grafo
{
    private:
    vector<Nodo<T>> grafo;
    list<pair<Vertice<T>*, int>> getListaAdj(Vertice<T>*);
    void dfsVisit(Vertice<T>* u, list<Vertice<T>*>&currentCycle,list<Vertice<T>*>&maxCycle, int& maxWeight, int currentWeight);
    int time;

    public:
    void dfs();
    void addArco(Vertice<T>* v1,Vertice<T>* v2, int peso);
    void addNodo(Nodo<T> nodo){grafo.push_back(nodo);}
    int searchIndex(Vertice<T>*);
    Vertice<T>* searchVert(T value);

    friend ostream& operator<<(ostream& out, const Grafo<T>&obj)
    {
        for(auto i : obj.grafo)
            out << i << endl;
        return out;
    }

};


template <class T>
list<pair<Vertice<T>*, int>> Grafo<T> :: getListaAdj(Vertice<T>* vert)
{
    for(auto i : grafo)
        if(i.getSource() == vert)
            return i.getListaAdj();
    return grafo.at(0).getListaAdj();
}

template <class T>
void Grafo<T> :: addArco(Vertice<T>* v1,Vertice<T>* v2, int peso)
{
    int index = searchIndex(v1);
    grafo.at(index).append(v2, peso);
}

template <class T>
int Grafo<T> :: searchIndex(Vertice<T>* vert)
{
    for(int i = 0; i < grafo.size(); i++)
        if(grafo.at(i).getSource() == vert)
            return i;
    return -1;
}

template<class T>
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
    list<Vertice<T>*> currentCycle;
    list<Vertice<T>*> maxCycle;
    int maxWeight = 0;
    for(auto i : grafo)
    {
        i.getSource()->setColor(Color::white);
        i.getSource()->setP(nullptr);
        i.getSource()->setInizioV(0);
        i.getSource()->setFineV(0);
    }
    time = 0;
    for(auto i : grafo)
        if(i.getSource()->getColor() == Color::white)
            dfsVisit(i.getSource(), currentCycle, maxCycle, maxWeight, 0);

    if(!maxCycle.empty())
    {
        cout << "Peso massimo: " << maxWeight << endl;
        for(auto v: maxCycle)
            cout << v->getValue() << " ";
        cout << endl;
    }else {
        cout << "Nessun ciclo trovato." << endl;
    }
}

template <class T>
void Grafo<T> :: dfsVisit(Vertice<T>* u, list<Vertice<T>*>&currentCycle,list<Vertice<T>*>&maxCycle, int& maxWeight, int currentWeight)
{
    u->setColor(Color::grey);
    u->setInizioV(++time);
    currentCycle.push_back(u);
    list<pair<Vertice<T>*, int>> adj = getListaAdj(u);
    for(auto v : adj)
    {
        int peso = v.second;
        if(v.first->getColor() == Color::white)
        {    
            v.first->setP(u);
            dfsVisit(v.first, currentCycle, maxCycle, maxWeight, currentWeight+peso);       
        }
        else if(v.first->getColor() == Color::grey)
        {
            if(maxWeight < currentWeight + peso)
            {   
                maxWeight = currentWeight + peso;
                maxCycle.clear();
                auto it = currentCycle.rbegin();
                while(it!=currentCycle.rend())
                {
                    maxCycle.push_front(*it);
                    if(*it==v.first)
                        break;
                    ++it;
                }
            }
        }
    }
    u->setColor(Color::black);
    u->setFineV(++time);
}



#endif //GRAFO_H