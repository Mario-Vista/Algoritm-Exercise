//Implementazione di una classe Nodo che rappresenta vertici tramite lista di adiacenza
#ifndef NODE_H
#define NODE_H

#include "Vertice.h"
#include <list>
#include <iostream>

using namespace std;

template <class T>
class Node
{
    private:
        Vertice<T>* source;                     //sorgente
        list<Vertice<T>*> listaAdiacenze;       //lista di adiacenza
    public:
        Node(Vertice<T>* sorgente);
        
        //getter
        Vertice<T>* getSource(){return this->source;}
        list<Vertice<T>*> getListaAdiacenze(){return this->listaAdiacenze;}

        //metodo per aggiungere un vertice alla lista di adiacenze
        void append(Vertice<T>* vert){this->listaAdiacenze.push_back(vert);}

        //overload dell'operatore << per una stampa la lista di adiacenza dei nodi
        friend ostream& operator <<(ostream& out, const Node<T>& obj)
        {
            out << *obj.source << " --> ";
            for(auto i:obj.listaAdiacenze)
                out << *i << " --> ";
            out << "Null";
            return out;
        }
};

template <class T>
Node<T> :: Node(Vertice<T> *sorgente)
{
    this->source = sorgente;
}




#endif //NODE_H