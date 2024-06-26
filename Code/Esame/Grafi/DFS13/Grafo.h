#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include "Nodo.h"
#include "Vertice.h"

using namespace std;

template <class T>
class Grafo
{
private:
	vector<Nodo<T>> grafo;
	list<Vertice<T>*> getListaAdj(Vertice<T>*);
	vector<vector<int>> w;
	queue<T> q;
	int time;
	void dfsVisit(Vertice<T>*);

public:
	Grafo(){};
	queue<T> getQueue(){return this->q;}
	int searchIndex(Vertice<T>*);
	Vertice<T>* searchVert(T);
	void addNodo(Nodo<T> nodo){this->grafo.push_back(nodo);}
	void addArco(Vertice<T>* v1, Vertice<T>* v2, int peso);
	void dfs();

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
	for(int i = 0; i < this->grafo.size(); i++)
		if(this->grafo.at(i).getSource() == vert)
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
void Grafo<T> :: addArco(Vertice<T>* v1, Vertice<T>* v2, int peso)
{
	int index1 = searchIndex(v1);
	int index2 = searchIndex(v2);
	w.at(index1).at(index2) = peso;
	this->grafo.at(index1).append(v2);
}

template <class T>
void Grafo<T> :: dfs()
{
	for(auto i : grafo)
	{
		i.getSource()->setColor(Color::white);
		i.getSource()->setInizioV(0);
		i.getSource()->setFineV(0);
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
			i->setPredecessore(u);
			dfsVisit(i);
		}
	u->setColor(Color::black);
	u->setFineV(++time);
	q.push(u->getValue());
}



#endif //GRAFO_H