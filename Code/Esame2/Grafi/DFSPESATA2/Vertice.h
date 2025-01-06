#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <cstdint>
#include <limits>
#include <string>

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
    Vertice<T>* p;
    int inizioV;
    int fineV;

    public:
    Vertice(T value):value(value), color(Color::white), p(nullptr), inizioV(UINT16_MAX), fineV(UINT16_MAX){};
    T getValue(){return this->value;}
    Vertice<T>* getP(){return p;}
    Color getColor(){return color;}
    int getInizioV(){return inizioV;}
    int getFineV(){return fineV;}

    void setValue(T val){value = val;}
    void setP(Vertice<T>* pa){p = pa;}
    void setColor(Color c){color = c;}
    void setInizioV(int in){inizioV = in;}
    void setFineV(int fi){fineV = fi;}

    friend ostream& operator<<(ostream& out, const Vertice<T>& obj)
    {
        string c;
        switch(obj.color)
        {
            case Color::white:c = "white";break;
            case Color::grey:c = "grey";break;
            case Color::black:c = "black";break;
            default: break;
        }
        out << "Value->" << obj.value << " Color->" << c;
        return out;
    }

    friend bool operator==(const Vertice<T>&a, const Vertice<T>&b)
    {
        return a.value ==b.value;
    }

};


#endif //VERTICE_H