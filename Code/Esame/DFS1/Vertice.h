#ifndef VERTICE_H
#define VERTICE_H

#include <string>
#include <iostream>
#include <limits>
#include <cstdint>

using namespace std;

enum class Color
{
    WHITE, GREY, BLACK
};

template <class T>
class Vertice
{
    private:
        T value;
        Color color;
        Vertice<T>* predecessore;

        int distanza;
        int inizioV;
        int fineV;
    
    public:
        Vertice(T value):value{value}, color{Color::WHITE}, distanza{UINT16_MAX}, predecessore{nullptr}, inizioV{0}, fineV{0}{};

        void setValue(T value){this->value = value;}
        void setColor(Color color){this->color = color;}
        void setPredecessore(Vertice<T>* predecessore){this->predecessore = predecessore;}
        void setDistanza(int distanza){this->distanza = distanza;}
        void setInizioV(int inizioV){this->inizioV = inizioV;}
        void setFineV(int fineV){this->fineV = fineV;}

        T getValue(){return this->value;}
        Color getColor(){return this->color;}
        Vertice<T>* getPredecessore(){return this->predecessore;}
        int getDistanza(){return this->distanza;}
        int getInizioV(){return this->inizioV;}
        int getFineV(){return this->fineV;}

        friend ostream& operator<<(ostream& out, const Vertice<T> &obj)
        {
            string c;
            switch(obj.color)
            {
                case Color :: WHITE: c = "WHITE"; break;
                case Color::GREY: c = "GREY";break;
                case Color::BLACK: c = "BLACK";break;

                default: break;
            }
            out << "Valore -> " << obj.value << " Colore -> " << c;
            return out;
        }

        friend bool operator==(const Vertice<T> &a, const Vertice<T>&b)
        {
            return a.value == b.value;
        }
};


#endif //VERTICE_H