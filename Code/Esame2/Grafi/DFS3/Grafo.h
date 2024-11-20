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
	int time;
	queue<T> q;
	void dfsVisit(Vertice<T>*);

public:
	Grafo(){};
	int searchIndex(Vertice<T>*);
	Vertice<T>* searchVert(T);
	void addNodo(Nodo<T> nodo){this->grafo.push_back(nodo);}
	void addArco(Vertice<T>*, Vertice<T>*);
	queue<T> getQueue(){return this->q;}
	void dfs();

	friend ostream& operator<<(ostream& out, const Grafo<T>& obj)
	{
		for(auto i : obj.grafo)
			out << i << endl;
		return out;
	}

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
		if(this->grafo.at(i).getSource() == vert)
			return i;
	return -1;
}

template <class T>	
Vertice<T>* Grafo<T> :: searchVert(T val)
{
	for(auto i : grafo)
		if(i.getSource()->getValue() == val)
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
void Grafo<T> :: dfs()
{
	for(auto i : grafo)
	{
		i.getSource()->setColor(Color::white);
		i.getSource()->setP(nullptr);
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
			i->setP(u);
			dfsVisit(i);
		}

	u->setColor(Color::black);
	u->setFineV(++time);
	q.push(u->getValue());

}






#endif //GRAFO_H