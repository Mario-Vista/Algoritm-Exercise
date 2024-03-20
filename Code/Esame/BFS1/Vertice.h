#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <vector>
#include <limits>
#include <string>
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
        Vertice<T> *predecessore;
        Color color;
        int distanza;
    public:
        Vertice(T value): value{value}, predecessore{nullptr}, color{Color::WHITE}, distanza{UINT16_MAX} { };
        
        T getValue(){return this->value;}
        void setValue(T value){this->value = value;}
        Vertice<T>* getPredecessore(){return this->predecessore;}
        void setPredecessore(Vertice<T>* pred){this->predecessore = pred;}
        Color getColor(){return this->Color;}
        void setColor(Color col){this->color = col;}
        int getDistanza(){return this->distanza;}
        void setDistanza(int dis){this->distanza = dis;}

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
            out << "Value -> " << obj.value << " Color-> " << c;
            return out;
        }

        friend bool operator==(const Vertice<T> &a, const Vertice<T> &b)
        {
            return a.value==b.value;
        }
};



#endif //VERTICE_H