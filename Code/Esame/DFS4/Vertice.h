#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <limits>
#include <cstdint>

using namespace std;

enum class Color{
    WHITE,GREY,BLACK
};

template <class T>
class Vertice
{
    private:
        T value;
        Vertice<T>* predecessore;
        Color color;
        int inizioV;
        int fineV;
        int distanza;
    public:
        Vertice(T value): value{value}, predecessore{nullptr}, color{Color::WHITE}, inizioV{0}, fineV{0}, distanza{UINT16_MAX} {};
        T getValue(){return this->value;}
        Vertice<T>* getPredecessore(){return this->predecessore;}
        Color getColor(){return this->color;}
        int getInizioV(){return this->inizioV;}
        int getFineV(){return this->fineV;}
        int getDistanza(){return this->distanza;}

        void setValue(T value){this->value = value;}
        void setPredecessore(Vertice<T>* predecessore) {this->predecessore = predecessore;}
        void setColor(Color color){this->color = color;}
        void setInizioV(int iniz){this->inizioV = iniz;}
        void setFineV(int fine){this->fineV = fine;}
        void setDistanza(int distanza){this->distanza = distanza;}

        friend ostream& operator<<(ostream& out, const Vertice<T>& obj)
        {
            string c;
            switch(obj.color)
            {
                case Color::WHITE: c = "WHITE"; break;
                case Color::GREY: c = "GREY"; break;
                case Color::BLACK: c = "BLACK"; break;
                default: break;
            }
            out << "Value-> " << obj.value << " Color-> " << c;
            return out;
        }

        friend bool operator==(const Vertice<T>& a, const Vertice<T>& b)
        {
            return a.value == b.value;
        }
};


#endif //VERTICE_H