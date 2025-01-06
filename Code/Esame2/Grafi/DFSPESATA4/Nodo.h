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
    list<pair<Vertice<T>*, int>> listaAdj; // Lista di adiacenza con pesi

public:
    Nodo(Vertice<T>* source) : source(source) {}
    
    Vertice<T>* getSource() { return source; }
    list<pair<Vertice<T>*, int>> getListaAdj() { return listaAdj; }
    
    void append(Vertice<T>* v, int peso) {
        this->listaAdj.push_back(make_pair(v, peso)); // Aggiunta con peso
    }
    
    friend ostream& operator<<(ostream& out, const Nodo<T>& obj) {
        out << *obj.source << " -> ";
        for (auto i : obj.listaAdj)
            out << "(" << *i.first << ", peso=" << i.second << ") -> ";
        out << "null";
        return out;
    }
};

#endif //NODO_H
