#pragma once

#include <iostream>
#include <string>
#include "validation.h"
#include "Auto.h"
#include "Passenger.h"
using namespace std;


class Bus : public Passenger {
public:
	Bus() {	}

	Bus(int number, int pplAmount, string name, string kpp, string fuel, int year, int probeg) : Passenger(pplAmount, name, kpp, fuel, year, probeg) {
		this->number = number;
	};
	Bus(const Bus& obj) : Bus(obj.number, obj.pplAmount, obj.name, obj.kpp, obj.fuel, obj.year, obj.probeg) {}

	Bus& operator =(Bus obj)
	{
		probeg = obj.probeg;
		year = obj.year;
		kpp = obj.kpp;
		name = obj.name;
		fuel = obj.fuel;
		pplAmount = obj.pplAmount;
		number = obj.number;
		return *this;
	}

	~Bus() {	};
	friend  istream& operator >> (istream& in, Bus& ob);
	friend ostream& operator << (ostream& out, Bus& ob);
	void setNumber();
	void show();
	void edit();
	const int getNumber();
	friend fstream& operator>> (fstream& f, Bus& obj);
	friend fstream& operator<< (fstream& f, Bus& obj);

	friend ifstream& operator>> (ifstream& f, Bus& obj);
	friend ofstream& operator<< (ofstream& f, Bus& obj);
protected:
	int number=0;
};