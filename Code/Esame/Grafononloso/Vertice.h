#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <limits>
#include <cstdint>
#include <string>

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
        Vertice<T>* predecessore;
        Color color;
        int distanza;
        int inizioV;
        int fineV;

    public:
        Vertice(T value): value{value}, color{Color::WHITE}, distanza{UINT16_MAX}, inizioV{0}, fineV{0} { };

        //getter
        T getValue(){return this->value;}
        Vertice<T>* getPredecessore(){return this->predecessore;}
        Color getColor(){return this->color;}
        int getDistanza(){return this->distanza;}
        int getInizioV(){return this->inizioV;}
        int getFineV(){return this->fineV;}

        //setter
        void setValue(T value){this->value = value;}
        void setPredecessore(Vertice<T>* predecessore){this->predecessore = predecessore;}
        void setColor(Color color){this->color = color;}
        void setDistanza(int distanza){this->distanza = distanza;}
        void setInizioV(int inizio){this->inizioV = inizio;}
        void setFineV(int fine){this->fineV = fine;}

        friend ostream& operator<<(ostream& out, const Vertice<T> &obj)
        {
            string c;
            switch(obj.color)
            {
                case Color::WHITE: c = "WHITE";break;
                case Color::GREY: c = "GREY";break;
                case Color::BLACK: c = "BLACK";break;
                default: break;
            }
            out << "Value -> " << obj.value << " -> " << c;
            return out;

        }
        
        friend bool operator==(const Vertice<T> &a, const Vertice<T> &b)
        {
            return a.value == b.value;
        }
};



#endif //VERTICE_H