#ifndef Controllo_h
#define Controllo_h

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Controllo
{
    private:
    fstream pro;
    fstream esi;
    fstream sol;

    bool checkNum(string, string);
    bool checkSym(string, string);
    bool checkLog(string, string);

    public:

    Controllo(string, string, string);
    ~Controllo();
};

//Costruttore
Controllo::Controllo(string problema, string esito, string soluzione)
{
    pro.open(problema.c_str(), ios::in);
    esi.open(esito.c_str(), ios::out);
    sol.open(soluzione.c_str(), ios::in);
}

//Distruttore
Controllo::~Controllo()
{
    pro.close();
    esi.close();
    sol.close();
}

bool Controllo::checkNum(string, string)
{}


bool Controllo::checkLog(string, string)
{}


bool Controllo::checkSym(string pr  , string )
{

}



#endif //Controllo_h