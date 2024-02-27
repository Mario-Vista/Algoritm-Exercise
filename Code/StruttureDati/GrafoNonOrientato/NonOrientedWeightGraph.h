#ifndef NONORIENTEDWEIGHTGRAPH_H
#define NONORIENTEDWEIGHTGRAPH_H

#include <vector>
#include "Node.h"
#include <iostream>
#include "Vertex.h"
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
    list<Vertex<T>*> getListaAdj();
    priority_queue< Vertex<T>*, vector<Vertex<T>*>, confronta<T> > minQueue;    //usata per prim
    void makeSet(vertice<T>*);
    void unionA(Vertex<T>*, Vertex<T>*);
    void link(Vertex<T>*, Vertex<T>*);
    Vertice<T>* findSet(Vertex<T>*);

    public:
        NonOrientedWeightGraph(){
            w.resize(VERTEX_NUMBER);
        }

    

};



#endif //NONORIENTEDWEIGHTGRAPH_H
