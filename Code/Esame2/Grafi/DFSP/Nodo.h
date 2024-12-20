#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <list>
#include "Vertice.h"

using namespace std;

template <class T>
class Nodo
{
    private:
    Vertice<T>* source;
    list<pair<Vertice<T>*, int>> listaAdj;
    public:
    Nodo(Vertice<T>* source):source(source){};
    Vertice<T>* getSource(){return source;}
    list<pair<Vertice<T>*, int>> getListaAdj(){return listaAdj;}
    void append(Vertice<T>* vert, int peso){listaAdj.push_back(make_pair(vert, peso));}
    friend ostream& operator<<(ostream& out, const Nodo<T>& obj)
    {
        out << *obj.source << " ";
        for(auto i : obj.listaAdj)
            out << "(" << *i.first << ", peso =" << i.second << ")";
        out << endl;
        return out; 
    }
};


#endif //NODO_H