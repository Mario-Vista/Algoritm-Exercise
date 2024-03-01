#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <limits>

using namespace std;

template <class T>
class Vertice
{
    private:
        T value;
        int distanza;
        Vertice<T>* predecessore;
        static int currID;
        const int ID;

    public:
        Vertice(T value): value{value}, distanza{UINT16_MAX}, predecessore(nullptr), ID{currID++}{};

        T getValue(){return this->value;}
        int getDistanza(){return this->distanza;}
        int getID(){return this->ID;}
        Vertice<T>* getPredecessore(){return this->predecessore;}

        void setValue(T value){this->value = value;}
        void setDistanza(int distanza){return this->distanza = distanza;}
        void setID(int ID){this->ID = ID;}
        void setPredecessore(Vertice<T>* predecessore){this->predecessore = predecessore;}

        friend ostream& operator<<(ostream& out, const Vertice<T> &out)
        {
            out << "Value: " << obj.value << " D: " << obj.distanza;
            return out;
        }
};

template <class T> int Vertice<T>::currID = 0;



#endif //VERTICE_H