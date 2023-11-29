/** È un Contenitore: ha un attributo capacita che definisce la
* capienza dell'anfora, un metodo getCapacita() che restituisce
* questo valore, un metodo riempi() per riempirla, un metodo
* svuota() per svuotarla, due metodi isVuota() e isPiena() che
* restituiscono lo stato dell'anfora ed un metodo
* spostaContenuto(Anfora) che sposta l'acqua nell'anfora
* passata come argomento.
*/

#ifndef Anfora_h
#define Anfora_h

#include <iostream>
#include "Contenitore.h"

class Anfora: public Contenitore
{
    private:
    int capacity;
    bool isPiena();
    bool isVuota();

    public:
    Anfora(int cap):Contenitore(){this->capacity = cap;}

    void riempi();
    void svuota();
    int getCapacity(){return this->capacity;}
    void spostaContenuto(Anfora);

};

bool Anfora::isPiena()
{
    if(this->getQt() == this->getCapacity())
        return true;
    return false;
}

bool Anfora::isVuota()
{
    if(this->getQt() == 0)
        return true;
    return false;
}

void Anfora::riempi()
{
    if(this->getQt() < this->capacity)
        this->setQt(capacity);
}

void Anfora::svuota()
{
    this->togli(this->getQt());
    std::cout << "Qt: " << this->getQt() << std::endl;
}

void Anfora::spostaContenuto(Anfora anf)
{
    
}


#endif //Anfora_h