#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <string>
#include <limits>
#include <cstdint>

using namespace std;

//creo una classe enum per il colore dei vertici
enum class Color{
    WHITE, GREY, BLACK
};

template <class T>
class Vertice
{
    private:
        T value;                    //valore del vertice
        Color color;                //colore del nodo
        Vertice<T> *predecessore;   //puntatore al nodo predecessore
        int distanza;               //distanza per BFS
        int tempoD;                 //per DFS
        int fineVisitaF;            //fine visita per DFS

    public:
        Vertice(T value);

        //metodi getter
        T getValue(){return this->value;}
        Color getColor(){return this->color;}
        int getDistanza(){return this->distanza;}
        int getTempoD(){return this->tempoD;}
        int getFineVisitaF(){return this->fineVisitaF;}

        //metodi setter
        void setValue(T newVal){this->value = newVal;}
        void setColor(Color newCol){this->color=newCol;}
        void setPredecessore(Vertice<T> *predecessore){this->predecessore=predecessore;}
        void setDistanza(int newDis){this->distanza=newDis;}
        void setTempoD(int newTime){this->tempoD=newTime;}
        void setFineVisitaF(int newEnd){this->fineVisitaF=newEnd;}

        //overload dell'operatore << in modo da avere una stampa personalizzata dei vertici
        friend ostream& operator<<(ostream& out, const Vertice<T>& obj)
        {
            string c;
            switch (obj.color)
            {
            case Color :: WHITE: 
                c = "White";
                break;
            case Color :: GREY: 
                c = "Grey";
                break;
            case Color :: BLACK: 
                c = "Black";
                break;            
            default:
                break;
            }
            out << "Value: " << obj.value << " Color: " << c;
            return out;
        }
        friend bool operator==(const Vertice<T>& a, const Vertice<T>& b){return a.value=b.value;}
};


template <class T>
Vertice<T> :: Vertice(T value)
{
    this->value = value;
    this->color = Color ::WHITE;
    this->predecessore= nullptr;
    this->distanza=UINT16_MAX;
    this->tempoD = 0;
    this->fineVisitaF = 0;
}


#endif //VERTICE_H