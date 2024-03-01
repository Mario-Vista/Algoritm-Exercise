#include "OrientedGraph.h"
#include <iostream>
#include "Vertice.h"
#include "Node.h"

using namespace std;

int main(){

    OrientedGraph<string> grafoOrientato;

    Vertice<string> a("A");
     Vertice<string> b("B");
     Vertice<string> c("C");
     Vertice<string> d("D");
     Vertice<string> e("E");
     Vertice<string> f("F");

     grafoOrientato.addVertex(Node<string>(&a));
     grafoOrientato.addVertex(Node<string>(&b));
     grafoOrientato.addVertex(Node<string>(&c));
     grafoOrientato.addVertex(Node<string>(&d));
     grafoOrientato.addVertex(Node<string>(&e));
     grafoOrientato.addVertex(Node<string>(&f));

     grafoOrientato.addEdge(0, &b);
     grafoOrientato.addEdge(0, &e);
     grafoOrientato.addEdge(1, &c);
     grafoOrientato.addEdge(2, &d);
     grafoOrientato.addEdge(2, &e);
     grafoOrientato.addEdge(4, &f);

     cout << endl << "***Grafo Orientato Connesso***" << endl;
     grafoOrientato.bfs(&a);
     cout << grafoOrientato;

    OrientedGraph<string> grafoSconnesso;

    Vertice<string> u("U");
    Vertice<string> v("V");
    Vertice<string> w("W");
    Vertice<string> x("X");
    Vertice<string> y("Y");
    Vertice<string> z("Z");

    grafoSconnesso.addVertex(&u);
    grafoSconnesso.addVertex(&v);
    grafoSconnesso.addVertex(&w);
    grafoSconnesso.addVertex(&x);
    grafoSconnesso.addVertex(&y);
    grafoSconnesso.addVertex(&z);

    grafoSconnesso.addEdge(0, &v);
    grafoSconnesso.addEdge(0, &x);
    grafoSconnesso.addEdge(1, &y);
    grafoSconnesso.addEdge(2, &y);
    grafoSconnesso.addEdge(2, &z);
    grafoSconnesso.addEdge(3, &v);
    grafoSconnesso.addEdge(4, &x);
    grafoSconnesso.addEdge(5, &z);

    cout << endl << "***Grafo Orientato Sconnesso***" << endl;
    grafoSconnesso.dfs();
    cout << endl << grafoSconnesso;

    OrientedGraph<string> DAG;

    Vertice<string> g("G");
    Vertice<string> h("H");
    Vertice<string> i("I");

    DAG.addVertex(&g);
    DAG.addVertex(&h);
    DAG.addVertex(&i);

    DAG.addEdge(0, &h);
    DAG.addEdge(1, &i);

    cout << endl << "***Grafo Orientato Aciclico***" << endl;
    DAG.topologicalSort();
    cout << DAG;

    /*OrientedGraph<string> grafoOrientatoSCC;

    Vertice<string> a("A");
    Vertice<string> b("B");
    Vertice<string> c("C");
    Vertice<string> d("D");
    Vertice<string> e("E");
    Vertice<string> f("F");
    Vertice<string> g("G");
    Vertice<string> h("H");

    grafoOrientatoSCC.addVertice(Nodo<string>(&a));
    grafoOrientatoSCC.addVertice(Nodo<string>(&b));
    grafoOrientatoSCC.addVertice(Nodo<string>(&c));
    grafoOrientatoSCC.addVertice(Nodo<string>(&d));
    grafoOrientatoSCC.addVertice(Nodo<string>(&e));
    grafoOrientatoSCC.addVertice(Nodo<string>(&f));
    grafoOrientatoSCC.addVertice(Nodo<string>(&g));
    grafoOrientatoSCC.addVertice(Nodo<string>(&h));

    grafoOrientatoSCC.addEdge(0, &b);
    grafoOrientatoSCC.addEdge(1, &e);
    grafoOrientatoSCC.addEdge(1, &f);
    grafoOrientatoSCC.addEdge(1, &c);
    grafoOrientatoSCC.addEdge(2, &d);
    grafoOrientatoSCC.addEdge(2, &g);
    grafoOrientatoSCC.addEdge(3, &c);
    grafoOrientatoSCC.addEdge(3, &h);
    grafoOrientatoSCC.addEdge(4, &a);
    grafoOrientatoSCC.addEdge(4, &f);
    grafoOrientatoSCC.addEdge(5, &g);
    grafoOrientatoSCC.addEdge(6, &f);
    grafoOrientatoSCC.addEdge(6, &h);
    grafoOrientatoSCC.addEdge(7, &h);

/*
    cout << "***Grafo Orientato SCC***" << endl;
    cout << grafoOrientatoSCC;


    grafoOrientatoSCC.depthFirstSearch();

    // grafoOrientatoSCC.calcolaComponentiFortenemeteConnesse();

    // cout << "***Componenti Fortemente Connesse***" << endl; // da capire la rappresentazione giusta
    // for (auto i : grafoOrientatoSCC.getComponentiFortementeConnsesse() )
    //     cout << i << endl;
    */

    return 0;
}