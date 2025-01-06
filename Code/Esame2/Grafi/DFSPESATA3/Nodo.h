#ifndef NODO_H
#define NODO_H

#include <list>
#include <iostream>
#include "Vertice.h"

using namespace std;

template <class T>
class Nodo
{
  private:
  Vertice<T>* source;
  list<pair<Vertice<T>*, int>> listaAdj;
  
  public:
  Nodo(Vertice<T>* source): source(source){};
  Vertice<T>* getSource(){return this->source;}
  list<pair<Vertice<T>*, int>> getListaAdj(){return this->listaAdj;}
  void append(Vertice<T>* vert, int peso){this->listaAdj.push_back(make_pair(vert, peso));}
  
  friend ostream& operator<<(ostream& out, const Nodo<T>& obj)
  {
    out << *obj.source << "->";
    for(auto i : obj.listaAdj)
      out << "(Valore: " << *i.first << " Peso: " << i.second << "->";
    out << "nullptr" << endl;
    return out;
  }

};



#endif
