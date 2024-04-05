#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <limits>
#include <string>

using namespace std;

enum class Color{
    WHITE,GREY,BLACK
};

template <class T>
class Vertice
{
    private:
        T value;
        Color color;
        Vertice<T>* predecessore;
        int inizioV;
        int fineV;

    public:
        Vertice(T value): value{value}, color{Color::WHITE}, predecessore{nullptr}, inizioV{UINT16_MAX}, fineV{UINT16_MAX} { };
        
        //getter
        T getValue(){return this->value;}
        Color getColor(){return this->color;}
        Vertice<T>* getPredecessore(){return this->predecessore;}
        
        //setter
        void setValue(T newVal){this->value = newVal;}
        void setColor(Color newCol){this->color = newCol;}
        void setPredecessore(Vertice<T>* newPrede){this->predecessore = newPrede;}

        friend ostream& operator<<(ostream& out, const Vertice<T>& obj)
        {
            string c;
            switch(obj.color)
            {
                case Color::WHITE: c = "WHITE";break;
                case Color::GREY: c = "GREY";break;
                case Color::BLACK: c = "BLACK";break;
            }
            out << "Value -> " << obj.value << " Color -> " << c;
            return out;
        }

        friend bool operator==(const Vertice<T>&a, const Vertice<T>&b)
        {
            return a.value == b.value;
        }
    

};


#endif //VERTICE_H