#include <iostream>
#include "Nodo.h"
#include "Vertice.h"
#include "Grafo.h"
#include <vector>
#include <string>
#include <list>

using namespace std;

int main()
{
    Grafo<string> grafo;
    
    Vertice<string> a("A");
    Vertice<string> b("B");
    Vertice<string> c("C");
    Vertice<string> d("D");
    Vertice<string> e("E");
    Vertice<string> f("F");

    grafo.addNodo(Nodo<string>(&a));
    grafo.addNodo(Nodo<string>(&b));
    grafo.addNodo(Nodo<string>(&c));
    grafo.addNodo(Nodo<string>(&d));
    grafo.addNodo(Nodo<string>(&e));
    grafo.addNodo(Nodo<string>(&f));

    grafo.addEdge(0, &a);
    grafo.addEdge(0, &b);
    grafo.addEdge(1, &c);
    grafo.addEdge(0, &b);
    grafo.addEdge(0, &e);
    grafo.addEdge(1, &c);
    grafo.addEdge(2, &d);
    grafo.addEdge(2, &e);
    grafo.addEdge(4, &c);

    grafo.dfs();

    cout << "Grafo" << endl;
    cout << grafo;
}
