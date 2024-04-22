#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Grafo.h"
#include "Vertice.h"
#include "Nodo.h"

using namespace std;

int main()
{

	Grafo<int> grafo;

   string inputFileName = "input.txt";
    string outputFileName = "output.txt";

    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Errore durante l'apertura del file di input." << endl;
        return 1;
    }

    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cerr << "Errore durante l'apertura del file di output." << endl;
        return 1;
    }
	
	string line; //variabile usata per memorizzare le righe lette dal file di input
	int i = 0, arco, vertice, numArchi = 0, numVertici = 0;

	while(getline(inputFile, line))
	{
		stringstream lineIn(line);
		if(i == 0)
		{
			lineIn>>numVertici;
			lineIn>>numArchi;
			i++;
		} else {
			lineIn>>vertice;
			lineIn>>arco;

			auto* v1 = new Vertice<int>(vertice);
			auto* v2 = new Vertice<int>(arco);

			if(grafo.searchIndex(v1) == -1)
				grafo.addNodo(v1);
			if(grafo.searchIndex(v2) == -1)
				grafo.addNodo(v2);
			grafo.addArco(v1, v2);
		}
	}

	inputFile.close();
	grafo.dfs();

	auto u = grafo.getQueue();

	while(!u.empty())
	{
		outputFile << u.front() << endl;
		u.pop();
	}

	outputFile.close();
	return 0;
}
