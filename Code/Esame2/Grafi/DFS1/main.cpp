#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>
#include <string>
#include "Grafo.h"
#include "Vertice.h"
#include "Nodo.h"

using namespace std;

int main()
{
    Grafo<int> grafo;
    ifstream iFile("input.txt");
    ofstream oFile("output.txt");


    int i = 0, numVertice = 0, numArchi = 0, vertice, arco;

    string line;

    while(getline(iFile, line))
    {
        stringstream linein(line);

        if(i == 0)
        {
            linein >> numVertice;
            linein >> numArchi;
            i++;
        } else 
        {
            linein >> vertice;
            linein >> arco;
            auto* v1 = new Vertice<int>(vertice);
            auto*v2 = new Vertice<int>(arco);

            if(grafo.searchIndex(v1) == -1)
                grafo.addNodo(v1);
            if(grafo.searchIndex(v2) == -1)
                grafo.addNodo(v2);
            grafo.addArco(v1,v2);
        }
    }
    iFile.close();

    grafo.dfs();
    
    oFile << grafo;
    cout << grafo;

    oFile.close();

    return 0;
}