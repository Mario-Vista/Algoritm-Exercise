#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <cstdint>
#include <string>
#include <limits>

using namespace std;

enum class Color{
    white, grey, black
};

template <class T>
class Vertice
{
    private:
        T value;
        Vertice<T>* p;
        Color color;
        int inizioV;
        int fineV;

    public:
        Vertice(T value): value(value), p(nullptr), color(Color::white), inizioV(UINT16_MAX), fineV(UINT16_MAX){};
        
        T getValue(){return this->value;}
        Vertice<T>* getP(){return this->p;}
        Color getColor(){return this->color;}
        int getInizioV(){return this->inizioV;}
        int getFineV(){return this->fineV;}

        void setValue(T newValue){this->value = value;}
        void setP(Vertice<T>* newP){this->p = newP;}
        void setColor(Color newColor){this->color = newColor;}
        void setInizioV(int newIn){this->inizioV = newIn;}
        void setFineV(int fin){this->fineV = fin;}

        friend bool operator==(const Vertice<T>&a, const Vertice<T>&b)
        {
            return a.value == b.value;
        }

        friend ostream& operator<<(ostream& out, const Vertice&obj)
        {
            string c;
            switch(obj.color)
            {
                case Color::white: c = "white";break;
                case Color::grey: c = "grey";break;
                case Color::black: c = "black";break;
                default: break;
            }
            out << "Value-> " << obj.value << " Color-> " << c;
            return out;
        }
};

#endif //VERTICE_H