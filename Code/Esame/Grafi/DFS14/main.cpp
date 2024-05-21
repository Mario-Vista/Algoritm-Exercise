#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include "Grafo.h"
#include "Nodo.h"
#include "Vertice.h"

using namespace std;

int main()
{
	Grafo<int> grafo;
	ifstream iFile("input.txt");
	ofstream oFile("output.txt");

	string line;
	int i = 0, numVertici = 0, numArchi = 0, vertice, arco;

	while(getline(iFile, line))
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

	iFile.close();

	grafo.dfs();

	auto q = grafo.getQueue();

	while(!q.empty())
	{
		oFile << q.front() << endl;
		q.pop();
	}

	oFile.close();

	return 0;
}