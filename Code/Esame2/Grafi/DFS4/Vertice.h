#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <limits>
#include <cstdint>

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
	Vertice<T>* p;
	Color color;
	int inizioV;
	int fineV;

public:
	Vertice(T value): value(value), color(Color::white), p(nullptr), inizioV(UINT16_MAX), fineV(UINT16_MAX){};
	T getValue(){return this->value;}
	Vertice<T>* getP(){return this->p;}
	Color getColor(){return this->color;}
	int getInizioV(){return this->inizioV;}
	int getFineV(){return this->fineV;}

	void setValue(T val){this->value = val;}
	void setColor(Color col){this->color = col;}
	void setP(Vertice<T>* pa){this->p = pa;}
	void setInizioV(int in){this->inizioV = in;}
	void setFineV(int fi){this->fineV = fi;}

	friend bool operator==(const Vertice<T>&a, const Vertice<T>&b)
	{
		return a.value == b.value;
	}

};



#endif //VERTICE_H

