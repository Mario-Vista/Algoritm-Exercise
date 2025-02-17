#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <string>
#include <cstdint>
#include <limits>

using namespace std;

enum class Color{
white, grey, black
};

template <class T>
class Vertice
{
  private:
  T value;
  Color color;
  int inizioV;
  int fineV;
  Vertice<T>* p;
  
  public:
  Vertice(T value): value(value), color(Color::white), inizioV(UINT16_MAX), fineV(UINT16_MAX), p(nullptr){};
  T getValue(){return this->value;}
  Color getColor(){return this->color;}
  int getInizioV(){return this->inizioV;}
  int getFineV(){return this->fineV;}
  Vertice<T>* getP(){return this->p;}
  
  void setValue(T val){this->value = val;}
  void setColor(Color col){this->color = col;}
  void setInizioV(int in){this->inizioV = in;}
  void setFineV(int fi){this->fineV = fi;}
  void setP(Vertice<T>* pa){this->p = pa;} 
  
  friend ostream& operator<<(ostream& out, const Vertice<T>& obj)
  {
      string c;
      switch(obj.color)
      {
        case Color::white: c = "white";break;
        case Color::grey: c = "grey";break;
        case Color::black: c = "black";break;
        default: break;
      }
      out << "Value-> " << obj.value << "Color-> " << c;
      return out;
  }
  
  friend bool operator==(const Vertice<T>& a, const Vertice<T>& b)
  {
    return a.value == b.value;
  }
  
};


#endif //VERTICE_H
