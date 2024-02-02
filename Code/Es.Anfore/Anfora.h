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
    int capacity;       //attributo per la capienza massima dell'anfora
    bool isPiena();     //metodo per verificare se l'anfora è piena
    bool isVuota();     //metodo per verificare se l'anfora è vuota

    public:
    //costruttore della classe figlia
    Anfora(int cap):capacity(cap), Contenitore() {}

    void riempi();                                  //metodo per riempire l'anfora
    void svuota();                                  //metodo per svuotare l'anfora
    int getCapacity(){return this->capacity;}       //metodo getter per la capacità
    void spostaContenuto(Anfora &);                 //metodo che sposta il contenuto da un'anfora all'altra

};

//implementazione dei metodi

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
}

void Anfora::spostaContenuto(Anfora &anf)
{
    //se c'è più qt nell'anfora di partenza rispetto allo spazio rimanente in quella di destinazione 
    if(this->getQt() > anf.getCapacity() - anf.getQt())
    {
        this->togli(anf.getCapacity() - anf.getQt());
        anf.riempi();     
    } else if(this->getQt() <= anf.getCapacity() - anf.getQt())
    {
        anf.versa(this->getQt());
        this->svuota(); 
    }
}


#endif //Anfora_h