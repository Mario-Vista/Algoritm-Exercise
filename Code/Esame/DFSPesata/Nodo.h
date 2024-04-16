#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <list>
#include "Vertice.h"

template <class T, class WeightType>
class Nodo
{
    private:
        Vertice<T>* source;
        list<pair<Vertice<T>*, WeightType>> listaAdj;

    public:
        Nodo(Vertice<T>* source){this->source = source;}
        
        //i setter non servono

        //getter
        Vertice<T>* getSource(){return this->source;}

        list<pair<Vertice<T>*, WeightType>> getListaAdj(){return this->listaAdj;}

        void append(Vertice<T>* vertice, WeightType peso){this->listaAdj.push_back(make_pair(vertice, peso));}

        friend ostream& operator<<(ostream& out, const Nodo<T, WeightType>& obj)
        {
            out << *obj.source << " -> ";
            for(auto i: obj.listaAdj)
            {
                out <<  "( " << i.first->getValue() << ", Peso: " << i.second << ") -> ";
            }

            out << "null";
            return out;
        }    
};

#endif //NODO_H