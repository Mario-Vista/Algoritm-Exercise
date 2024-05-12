#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "Grafo.h"
#include "Nodo.h"
#include "Vertice.h"

using namespace std;

int main()
{
	Grafo<int> grafo;
	string input = "input.txt";
	string output = "output.txt";
	ifstream inputFile(input);
	if(!inputFile.is_open())
	{
		cerr << "errore nell'apertura di input" << endl;
		return 1;
	}

	ofstream outputFile(output);
	if(!outputFile.is_open())
	{
		cerr << "errore nell'apertura di output" << endl;
		return 1;
	}

	string line;
	int i = 0, arco, vertice, numArchi = 0, numVertici = 0;

	while(getline(inputFile, line))
	{
		stringstream lineIn(line);
		if(i == 0)
		{
			lineIn>>numVertici;
			lineIn>>numArchi;
			i++;
		}
		else
		{
			lineIn >>arco;
			lineIn >>vertice;

			auto *v1 = new Vertice<int>(vertice);
			auto *v2 = new Vertice<int>(arco);

			if(grafo.searchIndex(v1) == -1)
				grafo.addNodo(v1);
			if(grafo.searchIndex(v2) == -1)
				grafo.addNodo(v2);
			grafo.addArco(v1, v2);
		}
	}

	inputFile.close();
	grafo.dfs();

	auto q = grafo.getMyQueue();

	while(!q.empty())
	{
		outputFile << q.front() << endl;
		q.pop();
	}

	outputFile.close();
	return 0;
}
