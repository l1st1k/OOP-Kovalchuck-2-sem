#pragma once

#include <iostream>
#include <string>
#include "validation.h"
#include "Auto.h"
using namespace std;


class Passenger : public Auto {
public:
	Passenger() {
		
	}
	Passenger(int pplAmount, string name, string kpp, string fuel, int year, int probeg) : Auto(name, kpp, fuel, year, probeg) {
		this->pplAmount = pplAmount;
	};
	Passenger(const Passenger& obj) : Passenger(obj.pplAmount, obj.name, obj.kpp, obj.fuel, obj.year, obj.probeg) {}
	~Passenger() {

	};

	Passenger& operator =(Passenger obj)
	{
		probeg = obj.probeg;
		year = obj.year;
		kpp = obj.kpp;
		name = obj.name;
		fuel = obj.fuel;
		pplAmount = obj.pplAmount;

		return *this;
	}
	void setPeopleAmount();
	void show();
	void edit();
	int getPeopleAmount();
	friend fstream& operator>> (fstream& f, Passenger& obj);
	friend fstream& operator<< (fstream& f, Passenger& obj);

	friend ifstream& operator>> (ifstream& f, Passenger& obj);
	friend ofstream& operator<< (ofstream& f, Passenger& obj);
protected:
	int pplAmount = 10;
};
