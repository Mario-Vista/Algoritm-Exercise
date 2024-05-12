#include "Nodo.h"
#include "Vertice.h"
#include "Grafo.h"

#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main()
{
    Grafo<string> grafo;

    Vertice<string> a("A");
    Vertice<string> b("B");
    Vertice<string> c("C");
    Vertice<string> d("D");
    Vertice<string> e("E");

    grafo.addNodo(Nodo<string>(&a));
    grafo.addNodo(Nodo<string>(&b));
    grafo.addNodo(Nodo<string>(&c));
    grafo.addNodo(Nodo<string>(&d));
    grafo.addNodo(Nodo<string>(&e));

    grafo.addEdge(0, &b);
    grafo.addEdge(0, &e);
    grafo.addEdge(1, &c);
    grafo.addEdge(2, &d);
    grafo.addEdge(2, &e);
    grafo.addEdge(4, &c);

    cout << "*** DFS ***" << endl;
    grafo.dfs();

    cout << grafo;

    
}