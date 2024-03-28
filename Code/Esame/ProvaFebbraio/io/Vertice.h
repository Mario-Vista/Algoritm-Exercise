#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <string>
#include <limits>

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
        Vertice(T value): value{value}, color{Color::WHITE}, predecessore{nullptr}, inizioV{UINT16_MAX}, fineV{UINT16_MAX} {};

        //getter
        T getValue(){return this->value;}
        Color getColor(){return this->color;}
        Vertice<T>* getPredecessore(){return this->predecessore;}
        int getInizioV(){return this->inizioV;}
        int getFineV(){return this-> fineV;}

        //setter
        void setValue(T value){this->value = value;}
        void setColor(Color color){this->color = color;}
        void setPredecessore(Vertice<T>* predecessore){this->predecessore = predecessore;}
        void setInizioV(int inizi){this->inizioV = inizi;}
        void setFineV(int fine){this->fineV = fine;}

/*        friend ostream& operator<<(ostream& out, const Vertice<T>& obj)
        {
            string c;
            switch(obj.color)
        }
*/
        friend bool operator==(cons Vertice<T>& a, cons Vertice<T>& b)
        {
            return a.value == b.value;
        }  
};


#endif //VERTICE_H