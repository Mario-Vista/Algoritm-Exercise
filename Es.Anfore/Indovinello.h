/**
* Risolve l'indovinello: ha due attributi anfora una da 3 lt ed una
* da 5 lt ed un metodo risolvi() che risolve l'indovinello mostrando
* a video il contenuto delle due anfore ad ogni passo della
* risoluzione.
*/

#ifndef Indovinello_h
#define Indovinello_h

#include <iostream>
#include <unistd.h>
#include "Anfora.h"

using namespace std;

class Indovinello
{

    private:
    //dichiaro due anfore di 3 e 5 litri
    Anfora tre;
    Anfora cinque;

    public:
    Indovinello() : tre(3), cinque(5) {}

    void risolvi();
    
};


void Indovinello::risolvi()
{
    //riempi tanica da 5 litri

    cinque.riempi();

    cout << "Tre: " << tre.getQt()<< endl;
    cout << "cinque: " << cinque.getQt()<< endl;

    sleep(2);



    //usa tanica da 5 litri per riempire tanica 3 litri
    cinque.spostaContenuto(tre);
    cout << "Tre: " << tre.getQt()<< endl;
    cout << "cinque: " << cinque.getQt()<< endl;
    sleep(2);

    //svuota tanica da 3 litri
    tre.svuota();
    cout << "Tre: " << tre.getQt()<< endl;
    cout << "cinque: " << cinque.getQt()<< endl;
    sleep(2);

    //sposta tanica 5 in tanica 3
    cinque.spostaContenuto(tre);
    cout << "Tre: " << tre.getQt()<< endl;
    cout << "cinque: " << cinque.getQt()<< endl;
    sleep(2);
    
    //riempi tanica 5
    cinque.riempi();
    cout << "Tre: " << tre.getQt()<< endl;
    cout << "cinque: " << cinque.getQt()<< endl;
    sleep(2);
    
    //sposta tanica 5 in 3
    cinque.spostaContenuto(tre);
    cout << "Tre: " << tre.getQt()<< endl;
    cout << "cinque: " << cinque.getQt()<< endl;
    sleep(2);

}

#endif //Indovinello_h