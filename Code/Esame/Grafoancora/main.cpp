#include "Vertice.h"
#include "Nodo.h"
#include "Grafo.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>

int main()
{
	Grafo<int> grafo;

	ifstream file;
	string input = "input.txt";

	ofstream output;
	string ex = "output.txt";

	file.open(input);
	output.open(ex);

	int i = 0, numArco = 0,numVertice = 0, arco, vertice;
	string line;

	while(getline(file, line))
	{
		stringstream linein(line);
		if(i == 0)
		{
			linein>>numArco;
			linein>>numVertice;
			i++;
		}
		else
		{
			linein>>arco;
			linein>>vertice;
			Vertice<int>* v1 = new Vertice<int>(vertice);
			Vertice<int>* v2 = new Vertice<int>(arco);
			if(grafo.searchVertice(v1) == -1)
				grafo.addNodo(v1);
			if(grafo.searchVertice(v2) == -1)
				grafo.addNodo(v2);
			grafo.addArco(v1,v2);
		}
	}
	file.close();
	cout << "prima della dfs" << endl;
	cout << grafo << endl;

	cout << "dopo dfs" << endl;
	cout << grafo << endl;

	queue<int> q = grafo.getQueue();

	while(!q.empty())
	{
		output << q.front() << endl;
		q.pop();
	}
	output.close();
	return 0;
}