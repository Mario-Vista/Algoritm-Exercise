#include <iostream>
#include "Nodo.h"
#include "Vertice.h"
#include "Grafo.h"
#include <vector>
#include <string>
#include <list>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    Grafo<int> grafo;
//ciao
    ifstream input;
    string myInput = "input.txt";

    ofstream output;
    string myOutput = "output.txt";
    
    input.open(myInput);
    output.open(myOutput);

    string line;
    int i = 0, numVertici = 0, numArchi = 0, vertice, arco;

    while(getline(input, line))
    {
        stringstream lineIn(line);
        if(i == 0)
        {
            lineIn>>numVertici;
            lineIn>>numArchi;
            i++;
        } else
            {
                lineIn >> vertice;
                lineIn >> arco;

                auto *v1 = new Vertice<int>(vertice);
                auto *v2 = new Vertice<int>(arco);

                if(grafo.searchAddress(v1) == -1)
                    grafo.addNodo(v1);
                if(grafo.searchAddress(v2) == -1)
                    grafo.addNodo(v2);
                grafo.addEdge(grafo.searchAddress(v1), v2);
            }
    } 

    input.close();
    cout << "***Prima della DFS***" << endl;
    cout << grafo << endl;
    grafo.dfs();
    cout << "***Dopo Dfs***" <<endl;
    cout << grafo << endl;

    auto u = grafo.getQueue();

    while(!u.empty())
    {
        output << u.front() << endl;
        u.pop();
    }

    output.close();
    return 0;



}