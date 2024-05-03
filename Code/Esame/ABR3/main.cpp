#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "Abr.h"
#include "Nodo.h"

using namespace std;

int main() {
    Abr<int> myAbr;

    ifstream myFile("input.txt");
    if(!myFile) {
        cerr << "Errore apertura file " << endl;
        return -1;
    }
    int num;
    while(myFile >> num) {
        myAbr.insert(num);
    }
    myFile.close();

    cout << "L'elemento radice è:  " << myAbr.getRoot()->getValue() << endl;
    cout << "L'elemento massimo è:  " << myAbr.maximum() << endl;
    cout << "L'elemento minimo è:  " << myAbr.minimum() << endl;

    cout << "VISITA PRE-ORDER" << endl;
    myAbr.preOrder();

    cout << endl;
    cout << "VISITA IN-ORDER" << endl;
    myAbr.inOrder();

    cout << endl;
    cout << "VISITA POST-ORDER" << endl;
    myAbr.postOrder();

    cout << endl;


    return 0;
}


