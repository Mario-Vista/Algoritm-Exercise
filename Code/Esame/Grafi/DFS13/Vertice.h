#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <limits>
#include <cstdint>

using namespace std;

enum class Color
{
	white,  grey, black
};

template <class T>
class Vertice
{
private:
	T value;
	Color color;
	int inizioV;
	int fineV;
	Vertice<T>* predecessore;

public:
	Vertice(T value): value(value), color(Color::white), inizioV(UINT16_MAX), fineV(UINT16_MAX), predecessore(nullptr){};


	//getter
	T getValue(){return this->value;}
	Color getColor(){return this->color;}
	int getInizioV(){return this->inizioV;}
	int getFineV(){return this->fineV;}
	Vertice<T>* getPredecessore(){return this->predecessore;}

	//setter
	void setValue(T value){this->value = value;}
	void setColor(Color color){this->color = color;}
	void setInizioV(int inizio){this->inizioV = inizio;}
	void setFineV(int fine){this->fineV = fine;}
	void setPredecessore(Vertice<T>* predec){this->predecessore = predec;}

	friend bool operator==(const Vertice<T>& a, const Vertice<T>& b)
	{
		return a.value == b.value;
	}
};


#endif //VERTICE_H