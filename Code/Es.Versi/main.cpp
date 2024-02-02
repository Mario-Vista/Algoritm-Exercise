/**
 * @file main.cpp
 * @author Mario Vista (mario.vista001@studenti.uniparthenope.it)
 * @brief 
 * @version 0.1
 * @date 2023-11-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

 /**
 * un file Problema.txt contenente diverse istanze del
 * problema (una per ogni riga)
 * un file Soluzione.txt contenente una soluzione per ogni
 * istanza di problema (una per ogni riga)
 * verifichi se ognuna delle soluzione è corretta rispetto al
 * problema e scriva l'esito su un file Esito.txt
 */


#include <iostream>
#include <string>

using namespace std;


int main()
{
    cout << "Esercizio rispetta i versi" << endl;
    
    string prova;

    prova = "fratemo ci serve il mare e il sole";

    cout << prova.at(8) << endl;

    string s2 = prova;

    cout << s2 << endl;

    
    return 0;
}   