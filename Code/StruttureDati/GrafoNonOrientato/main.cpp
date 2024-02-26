#include "NonOrientedGraph.h"
#include <string>
#include "Vertex.h"
#include <iostream>
#include "Node.h"

using namespace std;

int main(){

    NonOrientedGraph<string> grafoNonOrientato;

    Vertex<string> a("A");
    Vertex<string> b("B");
    Vertex<string> c("C");
    Vertex<string> d("D");
    Vertex<string> e("E");
    Vertex<string> f("F");
    Vertex<string> g("G");
    Vertex<string> h("H");
    Vertex<string> i("I");
    Vertex<string> j("J");

    grafoNonOrientato.addVertex(Node<string>(&a));
    grafoNonOrientato.addVertex(Node<string>(&b));
    grafoNonOrientato.addVertex(Node<string>(&c));
    grafoNonOrientato.addVertex(Node<string>(&d));
    grafoNonOrientato.addVertex(Node<string>(&e));
    grafoNonOrientato.addVertex(Node<string>(&f));
    grafoNonOrientato.addVertex(Node<string>(&g));
    grafoNonOrientato.addVertex(Node<string>(&h));
    grafoNonOrientato.addVertex(Node<string>(&i));
    grafoNonOrientato.addVertex(Node<string>(&j));

    grafoNonOrientato.addEdge(0, &b);
    grafoNonOrientato.addEdge(0, &c);

    grafoNonOrientato.addEdge(1, &a);
    grafoNonOrientato.addEdge(1, &c);
    grafoNonOrientato.addEdge(1, &d);

    grafoNonOrientato.addEdge(2, &a);
    grafoNonOrientato.addEdge(2, &b);

    grafoNonOrientato.addEdge(3, &b);

    grafoNonOrientato.addEdge(4, &f);
    grafoNonOrientato.addEdge(4, &g);

    grafoNonOrientato.addEdge(5, &e);
    
    grafoNonOrientato.addEdge(6, &e);

    grafoNonOrientato.addEdge(7, &i);

    grafoNonOrientato.addEdge(8, &h);

    grafoNonOrientato.dfs();

    cout << "***Grafo Non Orientato***" << endl;
    cout << grafoNonOrientato;


    // GrafoNonOrientatoPesato<string> grafoNonOrientatoPesato;

    // grafoNonOrientatoPesato.addVertice(&a);
    // grafoNonOrientatoPesato.addVertice(&b);
    // grafoNonOrientatoPesato.addVertice(&c);
    // grafoNonOrientatoPesato.addVertice(&d);
    // grafoNonOrientatoPesato.addVertice(&e);
    // grafoNonOrientatoPesato.addVertice(&f);
    // grafoNonOrientatoPesato.addVertice(&g);
    // grafoNonOrientatoPesato.addVertice(&h);
    // grafoNonOrientatoPesato.addVertice(&i);

    // grafoNonOrientatoPesato.addEdge(0, &b);
    // grafoNonOrientatoPesato.addEdge(0, &h);

    // grafoNonOrientatoPesato.addEdge(1, &a);
    // grafoNonOrientatoPesato.addEdge(1, &c);
    // grafoNonOrientatoPesato.addEdge(1, &h);

    // grafoNonOrientatoPesato.addEdge(1, &h);
    // grafoNonOrientatoPesato.addEdge(2, &b);
    // grafoNonOrientatoPesato.addEdge(2, &d);
    // grafoNonOrientatoPesato.addEdge(2, &f);
    // grafoNonOrientatoPesato.addEdge(2, &i);

    // grafoNonOrientatoPesato.addEdge(3, &c);
    // grafoNonOrientatoPesato.addEdge(3, &e);
    // grafoNonOrientatoPesato.addEdge(3, &f);

    // grafoNonOrientatoPesato.addEdge(4, &d);
    // grafoNonOrientatoPesato.addEdge(4, &f);

    // grafoNonOrientatoPesato.addEdge(5, &c);
    // grafoNonOrientatoPesato.addEdge(5, &d);
    // grafoNonOrientatoPesato.addEdge(5, &e);
    // grafoNonOrientatoPesato.addEdge(5, &f);

    // grafoNonOrientatoPesato.addEdge(6, &f);
    // grafoNonOrientatoPesato.addEdge(6, &h);
    // grafoNonOrientatoPesato.addEdge(6, &i);

    // grafoNonOrientatoPesato.addEdge(7, &a);
    // grafoNonOrientatoPesato.addEdge(7, &b);
    // grafoNonOrientatoPesato.addEdge(7, &g);
    // grafoNonOrientatoPesato.addEdge(7, &i);

    // grafoNonOrientatoPesato.addEdge(8, &c);
    // grafoNonOrientatoPesato.addEdge(8, &g);
    // grafoNonOrientatoPesato.addEdge(8, &h);

    // // A-0 B-1 C-2 D-3 E-4 F-5 G-6 H-7 I-8
    // grafoNonOrientatoPesato.addW(0,1,4);
    // grafoNonOrientatoPesato.addW(0,7,8);

    // grafoNonOrientatoPesato.addW(1,0,4);
    // grafoNonOrientatoPesato.addW(1,2,8);
    // grafoNonOrientatoPesato.addW(1,7,11);

    // grafoNonOrientatoPesato.addW(2,1,8);
    // grafoNonOrientatoPesato.addW(2,3,7);
    // grafoNonOrientatoPesato.addW(2,5,4);
    // grafoNonOrientatoPesato.addW(2,8,2);

    // grafoNonOrientatoPesato.addW(3,2,7);
    // grafoNonOrientatoPesato.addW(3,4,9);
    // grafoNonOrientatoPesato.addW(3,5,14);

    // grafoNonOrientatoPesato.addW(4,3,9);
    // grafoNonOrientatoPesato.addW(4,5,10);

    // grafoNonOrientatoPesato.addW(5,2,4);
    // grafoNonOrientatoPesato.addW(5,3,14);
    // grafoNonOrientatoPesato.addW(5,4,10);
    // grafoNonOrientatoPesato.addW(5,6,2);

    // // A-0 B-1 C-2 D-3 E-4 F-5 G-6 H-7 I-8
    // grafoNonOrientatoPesato.addW(6,5,2);
    // grafoNonOrientatoPesato.addW(6,7,1);
    // grafoNonOrientatoPesato.addW(6,8,6);

    // grafoNonOrientatoPesato.addW(7,0,8);
    // grafoNonOrientatoPesato.addW(7,1,11);
    // grafoNonOrientatoPesato.addW(7,6,1);
    // grafoNonOrientatoPesato.addW(7,8,7);

    // grafoNonOrientatoPesato.addW(8,2,2);
    // grafoNonOrientatoPesato.addW(8,6,6);
    // grafoNonOrientatoPesato.addW(8,7,7);

    // cout << "w(h,b): " << grafoNonOrientatoPesato.getW(7,1) << endl; 


    // grafoNonOrientatoPesato.viewPesi();

    // grafoNonOrientatoPesato.mstPrim(&a);

    return 0;
}