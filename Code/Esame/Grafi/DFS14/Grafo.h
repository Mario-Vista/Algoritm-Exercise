#ifndef GRAFO_H
#define GRAFO_H

#include <queue>
#include <vector>
#include <list>
#include <iostream>
#include "Vertice.h"
#include "Nodo.h"

using namespace std;

template <class T>
class Grafo
{
private:
	vector<Nodo<T>> grafo;
	list<Vertice<T>*> getListaAdj(Vertice<T>* vert);
	int time;
	queue<T> q;
	void dfsVisit(Vertice<T>*u);

public:
	Grafo(){};
	int searchIndex(Vertice<T>* vert);
	Vertice<T>* searchVert(T value);
	void dfs();
	queue<T> getQueue(){return this->q;}
	void addNodo(Nodo<T> nodo){this->grafo.push_back(nodo);}
	void addArco(Vertice<T>* v1, Vertice<T>* v2);
};

template <class T>
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

template <class T>
Vertice<T>* Grafo<T> :: searchVert(T value)
{
	for(auto i : grafo)
		if(i.getSource().getValue() == value)
			return i.getSource();
	return nullptr;
}

template <class T>
void Grafo<T> :: addArco(Vertice<T>* v1, Vertice<T>* v2)
{
	int index = searchIndex(v1);
	grafo.at(index).append(v2);
}

template <class T>
void Grafo<T> :: dfs()
{
	for(auto i : grafo)
	{
		i.getSource()->setColor(Color::white);
		i.getSource()->setInizioV(0);
	}
	time = 0;
	for(auto i : grafo)
		if(i.getSource()->getColor() == Color::white)
			dfsVisit(i.getSource());
}

template <class T>
void Grafo<T> :: dfsVisit(Vertice<T>* u)
{
	u->setColor(Color::grey);
	u->setInizioV(++time);
	list<Vertice<T>*> adj = getListaAdj(u);
	for(auto i : adj)
		if(i->getColor() == Color::white)
		{
			//i->setPredecessore(u);
			dfsVisit(i);
		}
	u->setColor(Color::black);
	u->setFineV(++time);
	q.push(u->getValue());
}






#endif //GRAFO_H