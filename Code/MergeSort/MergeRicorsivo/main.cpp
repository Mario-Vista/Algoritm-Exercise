#include <iostream>
#include <stdio.h>
#include "MergeRicorsivo.h"

using namespace std;

int main()
{
    
    int tot_elem;
    cout << "Inserisci numero elementi del vettore:" << endl;
    cin >> tot_elem;

    int *elementi = new int[tot_elem];

    for(int i = 0; i < tot_elem; i++)
    {
        cout << "Inserisci elemento di indice " << i << endl;
        cin >> elementi[i]; 
    }

    MergeRicorsivo<int>::mergeSort(elementi, 0, tot_elem-1);

    cout <<"array ordinato: ";
    for(int i = 0; i < tot_elem; i++)
    {
        cout << elementi[i] << " ";
    }
    return 0;


}