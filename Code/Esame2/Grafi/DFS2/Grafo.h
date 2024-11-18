#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <list>
#include "Vertice.h"
#include "Nodo.h"

using namespace std;

template <class T>
class Grafo
{
private:
	vector<Nodo<T>> grafo;
	list<Vertice<T>*> getListaAdj(Vertice<T>* vert);
	void dfsVisit(Vertice<T>*);
	int time;
public:
	Grafo(){};
	int searchIndex(Vertice<T>*);
	Vertice<T>* getVert(T);
	void addNodo(Nodo<T> nodo){this->grafo.push_back(nodo);}
	void addArco(Vertice<T>*, Vertice<T>*);
	void dfs();

    friend ostream& operator<<(ostream& out, const Grafo<T>& obj)
    {
        for(auto i : obj.grafo)
            out << i << endl;
        return out;
    }
};

template<class T>
list<Vertice<T>*> Grafo<T> :: getListaAdj(Vertice<T>* vert)
{
	for(auto i : grafo)
		if(i.getSource() == vert)
			return i.getListaAdj();
	return this->grafo.at(0).getListaAdj();
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
Vertice<T>* Grafo<T> :: getVert(T value)
{
	for(auto i : grafo)
		if(i.getSource()->getValue() == value)
			return i;
	return nullptr;
}

template <class T>
void Grafo<T> :: addArco(Vertice<T>*v1, Vertice<T>*v2)
{
	int index = searchIndex(v1);
	this->grafo.at(index).append(v2);
}

template <class T>
void Grafo<T> :: dfsVisit(Vertice<T>*u)
{
	u->setColor(Color::grey);
	u->setInizioV(++time);
	list<Vertice<T>*>adj = getListaAdj(u);
	for(auto v : adj)
	{
		v->setP(u);
		dfsVisit(v);
	}
	u->setFineV(++time);
	u->setColor(Color::black);
}


template <class T>
void Grafo<T> :: dfs()
{
	for(auto i : grafo)
	{ 
		i.getSource()->setColor(Color::white);
		i.getSource()->setInizioV(0);
		i.getSource()->setFineV(0);
		i.getSource()->setP(nullptr);
	}
	time = 0;

	for(auto i : grafo)
		if(i.getSource()->getColor() == Color::white)
			dfsVisit(i.getSource());
}



#endif //GRAFO_H