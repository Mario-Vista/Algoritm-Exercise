#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <string>
#include <limits>

using namespace std;

enum class Color{
white, grey, black
};

template <class T>
class Vertice{
	private:
		T value;
		Color color;
		Vertice<T>* predecessore;
		int inizioV;
		int fineV;

	public:
		Vertice(T value);

		//setter
		void setValue(T value) {this->value = value;}
		void setColor(Color color) {this->color = color;}
		void setPredecessore(Vertice<T>* predecessore){this->predecessore = predecessore;}
		void setInizioV(int inizioV){this->inizioV = inizioV;}
		void setFineV(int fineV){this->fineV = fineV;}

		//getter
		T getValue(){return this->value;}
		Color getColor(){return this->color;}
		Vertice<T>* getPredecessore(){return this->predecessore;}
		int getInizioV(){return this->inizioV;}
		int getFineV(){return this->fineV;}


		friend bool operator==(const Vertice<T>&a, const Vertice<T>&b)
		{
			return a.value == b.value;
		}
};

template <class T>
Vertice<T> :: Vertice(T value)
{
	this->value = value;
	this->color = Color::white;
	this->predecessore = nullptr;
	this->inizioV = UINT16_MAX;
	this->fineV = UINT16_MAX;
}




#endif //VERTICE_H
