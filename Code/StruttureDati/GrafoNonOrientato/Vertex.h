#ifndef VERTEX_H
#define VERTEX_H

#include <string>
#include <iostream>
#include <limits>
#include <cstdint>

using namespace std;

enum class Color{
    WHITE, GREY, BLACK
};

template <class T>
class Vertex
{
    private:
        T value;
        Color color;
        Vertex<T>* predecessor;
        Vertex<T>* leader;
        const int ID;
        static int currID;

        int key;
        
        int rank;

        int beginVisitTime;
        int endVisitTime;

    public:
        Vertex(T value): value{value},color{Color::WHITE}, predecessor{nullptr}, beginVisitTime{0}, endVisitTime{0}, rank{0}, ID{currID++}, key{UINT16_MAX}{};

        //getter
        T getValue(){return this->value;}
        Color getColor(){return this->color;}
        Vertex<T>* getPredecessor(){return this->predecessor;}
        Vertex<T>* getLeader(){return this->leader;}
        int getID(){return this->ID;}
        int getKey(){return this->key;}
        int getRank(){return this->rank;}
        int getBeginVisitTime(){return this->beginVisitTime;}
        int getEndVisitTime(){return this->endVisitTime;}

        //Setter
        void setValue(T newValue){this->value = newValue;}
        void setColor(Color newColor){this->color = newColor;}
        void setPredecessor(Vertex<T>* newPredecessor){this->predecessor = newPredecessor;}
        void setLeader(Vertex<T>* newLeader){this->leader = newLeader;}
        void setID(int newID){this->ID = newID;}
        void setKey(int newKey){this->key = newKey;}
        void setRank(int newRank){this->rank = newRank;}
        void setBeginVisitTime(int newBeginVisitTime){this->beginVisitTime = newBeginVisitTime;}
        void setEndVisitTime(int newEndVisitTime){this->endVisitTime = newEndVisitTime;}

        friend ostream& operator<<(ostream& out, const Vertex<T>& obj)
        {
            string c;
            switch (obj.color)
            {
                case Color::WHITE:
                    c = "WHITE";
                    break;

                case Color::GREY:
                    c = "GREY";
                    break;

                case Color::BLACK:
                    c = "BLACK";
                    break;
                default: break;
            }
            out << "Value: " << obj.value << " Color: " << c;
            return out;
        }

        friend bool operator==(const Vertex<T>& a, const Vertex<T>& b){return a.value == b.value;}
};

template <class T> int Vertex<T>::currID = 0;

#endif //VERTEX_H