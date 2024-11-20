#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <limits>
#include <cstdint>
#include <string>

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
	Vertice<T>* p;
	int inizioV;
	int fineV;

public:
	Vertice(T value):value(value), color(Color::white), p(nullptr), inizioV(UINT16_MAX), fineV(UINT16_MAX) {};

	//getter
	T getValue(){return this->value;}
	Color getColor(){return this->color;}
	Vertice<T>* getP(){return this->p;}
	int getInizioV(){return this->inizioV;}
	int getFineV(){return this->fineV;}

	//setter
	void setValue(T val){this->value = val;}
	void setColor(Color col){this->color = col;}
	void setP(Vertice<T>* ver){this->p = ver;}
	void setInizioV(int in){this->inizioV = in;}
	void setFineV(int fi){this->fineV = fi;}

	friend bool operator==(const Vertice<T>&a,const Vertice<T>&b)
	{
		return a.value == b.value;
	}

	friend ostream& operator<<(ostream& out, const Vertice<T>& obj)
	{
		string c;
		switch(obj.color)
		{
		case Color::white:c = "white";break;
		case Color::grey:c = "grey";break;
		case Color::black:c = "black";break;
		default:break;
		}
		out << "Value-> " << obj.value << " Color-> " << c;
		return out;
	}

};

#endif //VERTICE_H