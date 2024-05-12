#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <string>
#include <limits>

using namespace std;

enum class Color{
    white,grey,black
};  

template <class T>
class Vertice{
    private:
        Color color;
        T value;
        Vertice<T>* predecessore;
        int inizioV;
        int fineV;

    public:
        Vertice(T value): value{value}, color{Color::white},predecessore{nullptr}, inizioV{UINT16_MAX}, fineV{UINT16_MAX} {};
        Color getColor(){return this->color;}
        T getValue(){return this->value;}
        Vertice<T>* getPredecessore(){return this->predecessore;}
        int getInizioV(){return this->inizioV;}
        int getFineV(){return this->fineV;}
        void setColor(Color color){this->color = color;}
        void setValue(T value){this->value = value;}
        void setPredecessore(Vertice<T>* predecessore){this->predecessore = predecessore;}
        void setInizioV(int inizioV){this->inizioV = inizioV;}
        void setFineV(int fineV){this->fineV = fineV;}

        friend ostream& operator<<(ostream& out, const Vertice<T>&obj)
        {
            string c;
            switch(obj.color)
            {
                case Color::white: c = "white";break;
                case Color::grey: c = "grey";break;
                case Color::black: c = "black";break;
                default: break;
            }
            out << "Value -> " << obj.value << " Color -> " << c << endl;
            return out; 
        }

        friend bool operator==(const Vertice<T>&a, const Vertice<T>& b)
        {
            return a.value == b.value;
        }

};


#endif //VERTICE_H