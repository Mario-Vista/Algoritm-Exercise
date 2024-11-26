#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <limits>
#include <cstdint>

using namespace std;

enum class Color
{
    white, grey, black
};

template <class T>
class Vertice
{
    private:
        T value;
        Color color;
        int inizioV;
        int fineV
        Vertice<T>* p;

    public:
        Vertice(T value): value(value), color(Color::white), inizioV(UINT16_MAX), fineV(UINT16_MAX){};
        T getValue(){return this->value;}
        Color getColor(){return this->color;}
        Vertice<T>* getP(){return this->p;}
        int getInizioV(){return this->inizioV;}
        int getFineV(){return this->fineV;}

        void setValue(T value){this->value = value;}
        void setColor(Color col){this->color = col;}
        void setInizioV(int in){this->inizioV = in;}
        void setFineV(int fi){this->fineV = fi;}

        friend bool operator==(const Vertice<T>& a, const Vertice<T>&b)
        {
            return a.value == b.value
        }

};


#endif //VERTICE_H