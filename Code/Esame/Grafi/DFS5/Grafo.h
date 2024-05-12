#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <list>
#include "Vertice.h"
#include "Nodo.h"
#include <queue>

using namespace std;

template <class T>
class Grafo
{
	private:
		vector<Nodo<T>> grafo;
		list<Vertice<T>*> getListaAdj(Vertice<T>* vertice);
		int time;
		queue<T> myqueue;

		void dfsVisit(Vertice<T>* u);

	public:
		Grafo(){};
		queue<T> getQueue(){return this->myqueue;}

		//metodo che restituisce l'indice nel vettore corrispondente al vertice passato in input
		int searchIndex(Vertice<T>* vertice);

		//metodo che restituisce il puntatore al vertice che ha valore dato in input
		Vertice<T>* getIndirizzoVertice(T value);

		void addNodo(Nodo<T> nodo){this->grafo.push_back(nodo);}
		void addArco(Vertice<T>*v1, Vertice<T>* v2);

		void dfs();

};


template <class T>
list<Vertice<T>*> Grafo<T> ::getListaAdj(Vertice<T>* vertice)
{
	for(auto i : grafo)
		if(i.getSource() == vertice)
			return i.getListaAdj();
	return grafo.at(0).getListaAdj();
}

template <class T>
int Grafo<T> :: searchIndex(Vertice<T>* vertice)
{
	for(int i = 0; i < grafo.size(); i++)
		if(this->grafo.at(i).getSource()->getValue() == vertice->getValue())
			return i;
	return -1;
}

template <class T>
Vertice<T>* Grafo<T> :: getIndirizzoVertice(T value)
{
	for(auto i : grafo)
		if(i.getSource()->getValue() == value)
			return i.getSource();
	return nullptr;
}

template <class T>
void Grafo<T> :: dfs()
{
	for(auto i : grafo)
	{
		i.getSource()->setColor(Color::white);
		i.getSource()->setPredecessore(nullptr);
	}
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
	myqueue.push(u->getValue());
}

template <class T>
void Grafo<T> :: addArco(Vertice<T>*v1, Vertice<T>* v2)
{
	int vertice = searchIndex(v1);
	grafo.at(vertice).append(v2);


}


#endif //GRAFO_H
