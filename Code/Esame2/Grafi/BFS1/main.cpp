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
    ifstream input;
    string inputFile = "input.txt";

    ofstream output;
    string outputFile = "output.txt";

    input.open(inputFile);
    output.open(outputFile);

    string line;
    int i = 0, numArchi = 0, numVertici = 0, arco, vertice, sorgente;
    while(getline(input, line))
    {
        stringstream linein(line);
        if (i == 0)
        {
            linein>>numArchi;
            linein>>numVertici;
            i++;
        } else
        {
            linein >> arco;
            linein >> vertice;

            Vertice<int> *v1 = new Vertice<int>(arco);
            Vertice<int> *v2 = new Vertice<int>(vertice);

            sorgente = vertice;
            if(grafo.searchAddress(v1) == -1)
                grafo.addNodo(v1);
            if(grafo.searchAddress(v2) == -1)
                grafo.addNodo(v2);
            grafo.addEdge(v1, v2);
        }
    }
        
        input.close();
        grafo.bfs(grafo.getIndirizzoVertice(sorgente));
        
        cout << grafo << endl;
        output << grafo << endl;

        output.close();

    return 0;
}