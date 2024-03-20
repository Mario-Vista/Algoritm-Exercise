#include <iostream>
#include "Grafo.h"
#include "Vertice.h"
#include "Nodo.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    Grafo<int> grafo;
    ifstream file;
    file.open("input.txt");

    ofstream output;
    output.open("output.txt");

    string line;
    int i = 0, numVert = 0, numArc = 0, arco, vertice;
    
    while(getline(file, line))
    {
        stringstream lineIn(line);
        if(i == 0)
        {
            lineIn >> numVert;
            lineIn >> numArc;
            i++;
        }
        else {
            lineIn >> arco;
            lineIn >> vertice;

            Vertice<int> *v1 = new Vertice<int>(arco);
            Vertice<int> *v2 = new Vertice<int>(vertice);

            if(grafo.searchAddress(v1) == -1)
                grafo.addNodo(v1);
            if(grafo.searchAddress(v2) == -1)
                grafo.addNodo(v2);
            grafo.addEdge(grafo.searchAddress(v1), v2);            
        }
    }

    cout << "grafo pre dfs" << endl;
    cout << grafo << endl;
    grafo.dfs();
    cout << "grafo dfs" << endl;
    cout << grafo << endl;

    auto u = grafo.getQueue();

    while(!u.empty())
    {
        output << u.front() << endl;
        u.pop();
    }

    file.close();
    output.close();

    return 0;
}