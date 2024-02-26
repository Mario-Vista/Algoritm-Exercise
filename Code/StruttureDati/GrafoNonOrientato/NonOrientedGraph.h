#ifndef NONORIENTEDGRAPH_H
#define NONORIENTEDGRAPH_H

#include <vector>
#include "Node.h"
#include <iostream>

using namespace std;

template <class T>
class NonOrientedGraph
{
    private:
        vector<Node<T>> graph;
        int time;

        list<Vertex<T>*> getAdjList(Vertex<T>*);

        void makeSet(Vertex<T>*);
        void unionA(Vertex<T>*, Vertex<T>*);
        void link(Vertex<T>*, Vertex<T>*);
        Vertex<T>* findSet(Vertex<T>*);
    public:
        vector<Node<T>> getGraph(){return this->graph;}

        void addVertex(Node<T> node){this->graph.push_back(node);}
        void addEdge(int i, Vertex<T>* vertex){this->graph.at(i).append(vertex);}

        friend ostream& operator<<(ostream& out, const NonOrientedGraph<T>& obj)
        {
            for(auto i:obj.graph)
                out << i << endl;
            return out;
        }        

        void dfs();
        void dfsVisit(Vertex<T>*);

        void connectedComponents();
        void viewCC();        
};

template<class T>
list<Vertex<T>*> NonOrientedGraph<T> ::getAdjList(Vertex<T>*source)
{
    for(auto i : graph)
    {
        if(i.getSource() == source)
            return i.getAdjList();
        return graph.at(0).getAdjList();
    }
}

template <class T>
void NonOrientedGraph<T>::dfs()
{
    for(auto i : graph)
    {
        i.getSource()->setColor(Color::WHITE);
        i.getSource()->setPredecessor(nullptr);
    }
    time = 0;
    for(auto u : graph)
    {
        if (u.getSource()->getColor() == Color::WHITE)
            dfsVisit(u.getSource());
    }
}

template <class T>
void NonOrientedGraph<T>::dfsVisit(Vertex<T>* u)
{
    u->setColor(Color::GREY);
    u->setBeginVisitTime(++this->time);

    auto adj = this->getAdjList(u);

    for(auto v: adj)
        if(v.getSource()->getColor() == Color::WHITE)
        {
            v->setPredecessor(u);
            this->dfsVisit(v);
        }
    u->setColor(Color::BLACK);
    u->setEndTimeVisit(++this->time);
}

template <class T>
void NonOrientedGraph<T> :: makeSet(Vertex<T>*x)
{
    x->setPredecessor(x);
    x->setRank(0);
}

template <class T>
Vertex<T>* NonOrientedGraph<T> :: findSet(Vertex<T>* x)
{
    if(x->getPredecessor() != x)
    {
        x->setPredecessor(findSet(x->getPredecessor()));
    }
    return x->getPredecessor();
}

template <class T>
void NonOrientedGraph<T> :: unionA(Vertex<T> *x, Vertex<T>* y)
{
    this->link(findSet(x), findSet(y));
}

template <class T>
void NonOrientedGraph<T> :: link(Vertex<T> *x, Vertex<T>* y)
{
    if(x->getRank() > y->getRank())
    {
        x->setPredecessor(y);
    }
    else{
        y->setPredecessor(x);
        if(x->getRank() == y->getRank())
            y->setRank(y->getRank()+1);
    }
}

template <class T>
void NonOrientedGraph<T> :: connectedComponents()
{
    for(auto v : graph)
        makeSet(v.getSource());

    for(auto v: graph)
    {
        auto adj = this->getAdjList(v.getSource());

        for(auto u : adj)
            if(findSet(u)->getValue() != findSet(v.getSource())->getValue())
                this->unionA(u, v.getSource());
    }
}


template <class T> void NonOrientedGraph<T>::viewCC(){
    cout << "***Connected Components**" << endl;
    for (auto v: graph)
        cout << *(v.getSource()) <<  " " << *(v.getSource()->getPredecessor()) << endl;
}

#endif //NONORIENTEDGRAPH_H