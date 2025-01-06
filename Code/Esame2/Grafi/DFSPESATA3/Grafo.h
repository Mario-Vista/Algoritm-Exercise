#ifndef GRAFO_H
#define GRAFO_H

#include <list>
#include <vector>
#include <iostream>
#include "Nodo.h"

using namespace std;

template <class T>
class Grafo
{
  private:
    vector<Nodo<T>> grafo;
    list<pair<Vertice<T>*, int>> getListaAdj(Vertice<T>*);
    int time;
    void dfsVisit(Vertice<T>*, list<Vertice<T>*>&, list<Vertice<T>*>&, int&, int);

  public:
    void dfs();
    int searchIndex(Vertice<T>*);
    Vertice<T>* searchVert(T);
    void addNodo(Nodo<T> nodo) { grafo.push_back(nodo); }
    void addArco(Vertice<T>* v1, Vertice<T>* v2, int peso);

    friend ostream& operator<<(ostream& out, const Grafo<T>& obj)
    {
        for (auto i : obj.grafo)
            out << i << endl;
        return out;
    }
};

template <class T>
list<pair<Vertice<T>*, int>> Grafo<T>::getListaAdj(Vertice<T>* vert)
{
    for (auto i : grafo)
        if (i.getSource() == vert)
            return i.getListaAdj();
    return grafo.at(0).getListaAdj();
}

template <class T>
void Grafo<T>::addArco(Vertice<T>* v1, Vertice<T>* v2, int peso)
{
    int index = searchIndex(v1);
    grafo.at(index).append(v2, peso);
}

template <class T>
int Grafo<T>::searchIndex(Vertice<T>* vert)
{
    for (int i = 0; i < grafo.size(); i++)
        if (grafo.at(i).getSource() == vert)
            return i;
    return -1;
}

template <class T>
Vertice<T>* Grafo<T>::searchVert(T value)
{
    for (auto i : grafo)
        if (i.getSource()->getValue() == value)
            return i.getSource();
    return nullptr;
}

template <class T>
void Grafo<T>::dfs()
{
    // Variabili per il ciclo più lungo.
    list<Vertice<T>*> currentCycle;
    list<Vertice<T>*> longestCycle;
    int maxWeight = 0;

    // Ripristina lo stato iniziale di tutti i nodi.
    for (auto i : grafo) {
        i.getSource()->setColor(Color::white);
        i.getSource()->setP(nullptr);
        i.getSource()->setInizioV(0);
        i.getSource()->setFineV(0);
    }

    time = 0;

    // Esegui DFS per ogni nodo bianco.
    for (auto i : grafo) {
        if (i.getSource()->getColor() == Color::white) {
            dfsVisit(i.getSource(), currentCycle, longestCycle, maxWeight, 0);
        }
    }

    // Stampa il ciclo più lungo.
    if (!longestCycle.empty()) {
        cout << "Ciclo più lungo trovato con peso " << maxWeight << ": ";
        for (auto v : longestCycle) {
            cout << v->getValue() << " ";
        }
        cout << endl;
    } else {
        cout << "Nessun ciclo trovato." << endl;
    }
}

template <class T>
void Grafo<T>::dfsVisit(Vertice<T>* u, list<Vertice<T>*>& currentCycle, list<Vertice<T>*>& longestCycle, int& maxWeight, int currentWeight)
{
      u->setColor(Color::grey);
    u->setInizioV(++time);
    currentCycle.push_back(u);

    list<pair<Vertice<T>*, int>> adj = getListaAdj(u);

    for (auto i : adj) {
        Vertice<T>* v = i.first;
        int peso = i.second;

        if (v->getColor() == Color::white) {
            v->setP(u);
            dfsVisit(v, currentCycle, longestCycle, maxWeight, currentWeight + peso);
        } else if (v->getColor() == Color::grey) {
            // Rileva un ciclo.
            if (currentWeight + peso > maxWeight) {
                maxWeight = currentWeight + peso;

                // Memorizza il ciclo trovato.
                longestCycle.clear();
                auto it = currentCycle.rbegin();
                while (it != currentCycle.rend()) {
                    longestCycle.push_front(*it);
                    if (*it == v) break;
                    ++it;
                }
            }
        }
    }

    u->setColor(Color::black);
    u->setFineV(++time);
    currentCycle.pop_back();
}

#endif // GRAFO_H
