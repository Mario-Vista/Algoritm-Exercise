#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <list>
#include <iostream>
#include <queue>
#include "Nodo.h"
#include "Vertice.h"

using namespace std;

template <class T>
class Grafo
{
	private:
		vector<Nodo<T>> grafo;
		list<Vertice<T>*> getListaAdj(Vertice<T>* vertice);
		queue<T> q;
		int time;

		void dfsVisit(Vertice<T>* u);

	public:
		Grafo(){ };
		queue<T> getQueue(){return this->q;}
		void dfs();
		//void bfs(Vertice<T>* source);
		void addNodo(Nodo<T> nodo){this->grafo.push_back(nodo);}
		void addArco(Vertice<T>* v1, Vertice<T>* v2);
		int searchVertice(Vertice<T>* v1);
		Vertice<T>* getIndirizzoVertice(T value);

		friend ostream& operator<<(ostream& out, const Grafo<T> &obj)
		{
			for(auto i : obj.grafo)
				out << i << endl;
			return out;

		}
};

template <class T>
list<Vertice<T>*> Grafo<T> :: getListaAdj(Vertice<T>* vertice)
{
	for(auto i: grafo)
		if(i.getSource() == vertice)
			return i.getListaAdj();
	return this->grafo.at(0).getListaAdj();
}


template <class T>
int Grafo<T> :: searchVertice(Vertice<T>* v1)
{
	for(int i = 0; i < grafo.size(); i++)
			if(grafo.at(i).getSource()->getValue() == v1->getValue())
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
void Grafo<T> :: addArco(Vertice<T>* v1, Vertice<T>* v2)
{
	int vert = searchVertice(v1);
	grafo.at(vert).append(v2);
}

//DFS
template <class T>
void Grafo<T> :: dfs()
{
	for(auto i : grafo)
	{
		i.getSource()->setColor(Color::WHITE);
		i.getSource()->setPredecessore(nullptr);
		time = 0;
	}
	for(auto i : grafo)
		if(i.getSource()->getColor() == Color::WHITE)
			this->dfsVisit(i.getSource());
}

template <class T>
void Grafo<T>::dfsVisit(Vertice<T>* u)
{
	u->setColor(Color::GREY);
	u->setInizioV(++time);
	list<Vertice<T>*> adj = this->getListaAdj(u);
	for(auto i : adj)
		if(i->getColor() == Color::WHITE)
		{
			i->setPredecessore(u);
			this->dfsVisit(i);
		}
	u->setColor(Color::BLACK);
	u->setFineV(++time);
	q.push(u->getValue());
}
	



#endif //GRAFO_H