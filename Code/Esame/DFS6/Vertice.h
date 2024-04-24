#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
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
		Vertice<T>* predecessore;
		int inizioV;
		int fineV;
	public:
		Vertice(T value): value{value}, color{Color::white}, predecessore{nullptr}, inizioV{UINT16_MAX}, fineV{UINT16_MAX} {};

		//setter
		void setValue(T value){this->value = value;}
		void setColor(Color color){this->color = color;}
		void setPredecessore(Vertice<T>* predecessore){this->predecessore = predecessore;}
		void setInizioV(int inizio){this->inizioV = inizio;}
		void setFineV(int fine){this->fineV = fine;}

		//getter
		T getValue(){return this->value;}
		Color getColor(){return this->color;}
		Vertice<T>* getPredecessore(){return this->predecessore;}
		int getInizioV(){return this->inizioV;}
		int getFineV(){return this->fineV;}
};


#endif //VERTICE_H
