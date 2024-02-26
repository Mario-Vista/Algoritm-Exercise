#ifndef ORIENTEDGRAPH_H
#define ORIENTEDGRAPH_H

#include <vector>
#include "Node.h"
#include "Vertice.h"
#include <iostream>
#include <limits>
#include <queue>
#include <list>
#include <map>
#include "../Stack/Stack.h"

using namespace std;

template <class T>
class OrientedGraph
{
    private:
        vector<Node<T>> graph;

        bool cycle;
        int timeDfs;
        int counterSCC;

        Stack<Vertice<T>*> L;       //stack used for topological sort
        vector<Node<T>> transposedGraph;
        vector<Node<T>> SCC;
        map<Vertice<T>*, int> amap;     //map to bind vertex to them index in graph

        //adjacency lists
        list<Vertice<T>*> getAdjList(Vertice<T>*);
        list<Vertice<T>*> getAdjListGT(Vertice<T>*);

        //DFS
        void dfsVisit(Vertice<T>*);
        string edgeClassification(Vertice<T>*, Vertice<T>*);

        //DFS to find cycle in graph
        bool dfsCycle();
        void dfsVisitCycle(Vertice<T>*);

        //topological sort
        void tsDfs();
        void tsDfsVisit();
        void printTs();

        //grafo trasposto
        void createTransposedGraph();
        void dfsVisit2(Vertice<T>*);
        Node<T> getNodeTransposedGraph(Vertice<T>*);

    public:
        //getter
        vector<Node<T>> getGraph(){return this->graph;}
        vector<Node<T>> getTransposedGraph(){return this->transposedGraph;}
        vector<Node<T>> getSCC(){return this->SCC;}

        //methods to add a vertex or an edge in the graph
        void addVertex(Node<T> node){this->graph.push_back(node);}
        void addEdge(int i, Vertice<T>* vertex){this->graph.at(i).append(vertex);}

        //overload of << operator to customize print
        friend ostream& operator<<(ostream &out, const OrientedGraph<T>& obj)
        {
            for (auto i:obj.graph)
                out << i << endl;
            return out;
        }

        //visit algorithm
        void bfs(Vertice<T>*);
        void dfs();

        void isDag();
        void topologicalSort();
        void calculateSCC();
};


//estraggo la lista di adiacenza di quel vertice
template<class T>
list<Vertice<T> *> OrientedGraph<T>::getAdjList(Vertice<T> *vertex)
{
    for(auto i:graph)   //i is Node<T>
        if(i.getSource() == vertex)
            return i.getListaAdiacenze();
    return graph.at(0).getListaAdiacenze();
}

template <class T>
void OrientedGraph<T> :: bfs(Vertice<T> *source)
{
    for(auto i:graph)
    {
        i.getSource()->setColor(Color :: WHITE);
        i.getSource()->setPredecessore(nullptr);
        i.getSource()->setDistanza(0);
    }
    source->setColor(Color::GREY);
    source->setDistanza(0);
    source->setPredecessore(nullptr);

    queue<Vertice<T>*> q;
    q.push(source);

    while(!q.empty())
    {
        auto u = q.front();
        q.pop();

        auto adj = this->getAdjList(u);
        for(auto v:adj){
            if(v->getColor() == Color::WHITE)
            {
                v->setColor(Color::GREY);
                v->setPredecessore(u);
                v->setDistanza(u->getDistanza()+1);
                q.push(v);
            }
        }
        u->setColor(Color::BLACK);
    }
}

template <class T>
void OrientedGraph<T> :: dfs()
{
    for(auto i:graph)
    {
        i.getSource()->setPredecessore(nullptr);
        i.getSource()->setColor(Color ::WHITE);
        this->timeDfs =0;
    }
    for(auto u:graph)
    {
        if(u.getSource()->getColor() == Color :: WHITE)
            this->dfsVisit(u.getSource());
    }
}


template<class T>
void OrientedGraph<T> :: dfsVisit(Vertice<T>* u)
{
    u->setColor(Color::GREY);
    u->setTempoD(++timeDfs);

    auto adj = this->getAdjList(u);

    for(auto v:adj)
    {
        cout << endl << this->edgeClassification(u, v);
        if(v->getColor() == Color::WHITE){
            v->setPredecessore(u);
            this->dfs(v);
        }
    }
    u->setColor(Color::BLACK);
    u->setFineVisitaF(++timeDfs);
}


template <class T> string OrientedGraph<T>::edgeClassification(Vertice<T>* u, Vertice<T>* v){
    if ( v->getColor() == Color::WHITE )
        return "Arco dell'Albero";
    else if ( v->getColor() == Color::GREY )
        return "Arco dell'Indietro";
    else if ( v->getColor() == Color::BLACK && u->getTempoD() < v->getTempoD() )
        return "Arco In Avanti";
    else 
        return "Arco Trasversale";
}

#endif //ORIENTEDGRAPH_H