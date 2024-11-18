#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <limits>
#include <string>
#include <limits.h>
#include <cstdint>

using namespace std;

enum class Color{
    white, grey, black
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
    Vertice(T value): value(value), color(Color::black), predecessore(nullptr), distanza(UINT16_MAX){};

    //getter
    T getValue(){return this->value;}
    Color getColor(){return this->color;}
    Vertice<T>* getPredecessore(){return this->predecessore;}
    int getDistanza(){return this->distanza;}

    //setter
    void setValue(T newValue){this->value = newValue;}
    void setColor(Color newColor){this->color = newColor;}
    void setPredecessore(Vertice<T>* newPredecessore){this->predecessore = newPredecessore;}
    void setDistanza(int newDistanza){this->distanza = newDistanza;}

    friend ostream& operator<<(ostream& out, const Vertice<T> &obj)
    {
        string c;
        switch(obj.color)
        {
            case Color::white: c = "white";break;
            case Color::grey:c = "grey";break;
            case Color::black:c="black";break;
            default:break;
        }

        out << "Value-> " << obj.value << " Color-> " << c;
        return out;
    }

    friend bool operator==(const Vertice<T>&a, const Vertice<T>&b)
    {
        return a.value == b.value;
    }
    

};


#endif //VERTICE_H