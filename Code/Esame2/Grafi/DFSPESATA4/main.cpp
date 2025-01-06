#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Grafo.h"

using namespace std;

int main()
{
    Grafo<int> grafo;
    ifstream iFile("input.txt");
    ofstream oFile("output.txt");

    string line;
    int i = 0, numVertici = 0, numArco = 0, vertice, arco, peso;
    while(getline(iFile, line))
    {
        stringstream linein(line);
        if(i == 0)
        {
            linein >> numVertici >> numArco;
            i++;
        }
        else{
            linein >> vertice >> arco >> peso;
            auto *v1 = new Vertice<int>(vertice);
            auto *v2 = new Vertice<int>(arco);
            if(grafo.searchIndex(v1) == -1)
                grafo.addNodo(v1);
            if(grafo.searchIndex(v2) == -2)
                grafo.addNodo(v2);
            grafo.addArco(v1, v2, peso);
        }
    }
    iFile.close();

    grafo.dfs();

    return 0;


}