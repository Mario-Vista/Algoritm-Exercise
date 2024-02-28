#ifndef NONORIENTEDWEIGHTGRAPH_H
#define NONORIENTEDWEIGHTGRAPH_H

#include <vector>
#include "Node.h"
#include <iostream>
#include "Vertex.h"
#include "../../Algorithm/Algorithm.h"
#include <limits>
#include <queue>

#define VERTEX_NUMBER 9

using namespace std;

template <class T>
struct confronta
{
    bool operator()(Vertex<T>*a, Vertex<T>* b)
    {
        return a->getKey() > b->getKey();
    }
};

template <class T>
class Edge
{
    private:
        Vertex<T>* a;
        Vertex<T>* b;
        int w;
    public:
        Edge(Vertex<T>* a, Vertex<T>* b, int w):a{a},b{b},w{w}{};

        //getter
        Vertex<T>* getA(){return this->a;}
        Vertex<T>* getB(){return this->b;}
        int getW(){return this->w;}

        //operators overloading
        friend bool operator<(const Edge<T> &a, const Edge<T> &b){return a.w < b.w;}
        friend bool operator>(const Edge<T> &a, const Edge<T> &b){return a.w > b.w;}
        friend bool operator==(const Edge<T> &a, const Edge<T> &b){return a.w == b.w;}
        friend ostream& operator<<(ostream& out, const Edge<T> &obj)
        {
            out << obj.a->getValue() << " -- " << obj.w << " -- " << obj.b->getValue();
            return out;
        }
};


template <class T>
class NonOrientedWeightGraph
{
    private:
    vector<Node<T>> graph;
    int time;
    vector<vector<int>> w;      //matrice dei pesi
    list<Vertex<T>*> verticiEstratti;
    list<Vertex<T>*> getListaAdj(Vertex<T>*);
    priority_queue< Vertex<T>*, vector<Vertex<T>*>, confronta<T> > minQueue;    //usata per prim
    void makeSet(Vertex<T>*);
    void unionA(Vertex<T>*, Vertex<T>*);
    void link(Vertex<T>*, Vertex<T>*);
    Vertex<T>* findSet(Vertex<T>*);

    public:
        NonOrientedWeightGraph(){
            w.resize(VERTEX_NUMBER, vector<int>(VERTEX_NUMBER));
        }

        vector<Node<T>> getGraph(){return this->graph;}

        void addVertice(Node<T> nodo){this->graph.push_back(nodo);}
        void addEdge(int i, Vertex<T>* vertice){this->graph.at(i).append(vertice);}
        void addW(int i, int j, int w){this->w.at(i).at(j) = w;}

        friend ostream& operator<<(ostream& out, const NonOrientedWeightGraph<T>& obj)
        {
            for(auto i:obj.graph)
                out << i << endl;
            return out;
        }

        bool appartieneCoda(Vertex<T>*);

        void dfs();
        void dfsVisit();

        void connectedComponents();
        void viewCC();
        void mstKruskal();
        void mstPrim(Vertex<T>*);

        void viewPesi()
        {
            for(auto i: w)
            {
                for(auto j:i)
                    cout << j << " ";
                    cout << endl;
            }
        }

        int getW(int i, int j)
        {
            return w.at(i).at(j);
        }  

};

template <class T>
list<Vertex<T>*> NonOrientedWeightGraph<T> :: getListaAdj(Vertex<T>*source)
{
    for(auto i : graph)
        if(i.getSource() == source)
            return i.getAdjList();
        return graph.at(0).getAdjList();

}


template <class T>
Vertex<T>* NonOrientedWeightGraph<T> :: findSet(Vertex<T>* x)
{
    if(x->getLeader() != x)
        x->setLeader(findSet(x->getLeader()));
    return x->getLeader();
}

template <class T>
void NonOrientedWeightGraph<T> :: makeSet(Vertex<T>* x)
{
    x->setLeader(x);
    x->setRank(0);
}


template <class T>
void NonOrientedWeightGraph<T> :: unionA(Vertex<T>*x, Vertex<T> *y)
{
    this->link(findSet(x), findSet(y));
}

template<class T>
void NonOrientedWeightGraph<T> :: link(Vertex<T>* x, Vertex<T>* y)
{
    if(x->getRank() > y->getRank())
        x->setLeader(y);
    else{
        y->setLeader(x);
        if(x->getRank == y->getRank())
            y->setRank(y->getRank()+1);
    }
}

template <class T>
void NonOrientedWeightGraph<T> :: viewCC()
{
    cout << "***Componenti Connesse***" << endl;
    for(auto v:graph)
        cout << *(v.getSource()) << " " << *(v.getSource()->getPredecessor()) << endl;
}

template <class T>
void NonOrientedWeightGraph<T> :: mstKruskal()
{
    for(auto v : graph)
        this->makeSet(v.getSouce());

    vector<Edge<T>> pesi;
    for(int i=0; i < VERTEX_NUMBER; i++)
        for(int j = 0; j < VERTEX_NUMBER; j++)
            if(w.at(i).at(j) != 0)
                pesi.push_back(Edge<T>(graph.at(i).getSource(), graph.at(j).getSource(), w.at(i).at(j)));
    Algorithm::quickSort<Edge<T>>(pesi.begin(), pesi.end()-1);

    for(auto i : graph)
    {
        if(findSet(i.getA()) != findSet(i.getB()))
            unionA(i.getA(), i.getB());
    }
}

template <class T>
void NonOrientedWeightGraph<T> :: mstPrim(Vertex<T>* root)
{
    for(auto i:graph)
    {
        i.getSource()->setPredecessor(nullptr);
        i.getSource()->setKey(UINT16_MAX);
    }
    root->setKey(0);

    for(auto i:graph)
        minQueue.push(i.getSource());

    while(!minQueue.empty())
    {
        auto u = minQueue.top();
        verticiEstratti.push_back(u);
        minQueue.pop();

        auto adj = this->getListaAdj(u);

        for(auto v:adj)
            if(appartieneCoda(v) && getW(u->getID(), v->getID()) < v->getKey())
                v->setPredecessor(u);
    }
}



template <class T>
bool NonOrientedWeightGraph<T> :: appartieneCoda(Vertex<T>*v)
{
    bool appartiene = true;
    for( auto i : verticiEstratti)
        if(i == v)
            appartiene = false;
    return appartiene;
}


#endif //NONORIENTEDWEIGHTGRAPH_H
