/**Classe Contenitore
* Generico contenitore d'acqua: ha un attributo qt che memorizza
* la quantità d'acqua, un metodo versa(lt) per versare acqua, un
* metodo togli(lt) per togliere acqua ed un metodo getQt() che
* restituisce il valore di qt.
*/

#ifndef Contenitore_h
#define Contenitore_h

#include <iostream>

class Contenitore
{
    private:
    int qt;

    public:
    Contenitore();
    void versa(int);
    void togli(int);
    int getQt(){return qt;}
    void setQt(int lt) {this->qt = lt;}


};

Contenitore::Contenitore()
{
    this->qt = 0;
}

void Contenitore::versa(int lt)
{
    this->qt += lt;
}


void Contenitore::togli(int lt)
{
    this->qt -= lt;
}







#endif //Contenitore_h