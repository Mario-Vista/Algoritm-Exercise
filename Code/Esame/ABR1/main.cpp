#include <iostream>
#include <fstream>
#include "Abr.h"

using namespace std;

int main()
{
	// Creazione dell'albero binario di ricerca
	Abr<int> abr;

	// Lettura dei dati da input.txt
	ifstream inputFile("input.txt");
	int value;

	if(!inputFile.is_open())
	{
		cerr << "Errore nell'apertura del file" << endl;
		return 1;
	}

	while(inputFile >> value)
		abr.insert(value);
	inputFile.close();


	// Controllo sulla presenza di nodi nell'albero
	if (abr.getRoot() == nullptr) {
		cerr << "Nessun nodo presente nell'albero" << endl;
		return 1;
	}

	// Chiamata al metodo di visita e scrittura su file di output
	abr.preOrder();
	cout << "Visita stampata " << endl;

return 0;
}
