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
	Color color;
	Vertice<T>* predecessore;
	int inizioV;
	int fineV;

public:
	Vertice(T value): value(value), color{Color::white}, predecessore(nullptr), inizioV(UINT16_MAX), fineV(UINT16_MAX){}	;
	T getValue(){return this->value;}
	Color getColor(){return this->color;}
	Vertice<T>* getPredecessore(){return this->predecessore;}
	int getInizioV(){return this->inizioV;}
	int getFineV(){return this->fineV;}

	void setValue(T value){this->value = value;}
	void setColor(Color color){this->color = color;}
	void setPredecessore(Vertice<T>* vertice){this->predecessore = vertice;}
	void setInizioV(int inizio){this->inizioV = inizio;}
	void setFineV(int fine){this->fineV = fine;}

	friend bool operator==(const Vertice<T>& a, const Vertice<T>& b)
	{
		return a.value == b.value;
	}
};

#endif //VERTICE_H