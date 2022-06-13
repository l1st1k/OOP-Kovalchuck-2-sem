#pragma once

#include <iostream>
#include <string>
#include "validation.h"
#include "Auto.h"
#include "Passenger.h"
using namespace std;

class Troll : public Passenger {
public:
	Troll() {

	};

	
	Troll(int capacity,int pplAmount, string name, string kpp, string fuel, int year, int probeg) : Passenger(pplAmount, name, kpp, fuel, year, probeg) {
		this->capacity = capacity;
	};
	Troll(const Troll& obj) : Troll(obj.capacity, obj.pplAmount,obj.name, obj.kpp, obj.fuel, obj.year, obj.probeg  ) {}

	Troll& operator =(Troll obj)
	{
		probeg = obj.probeg;
		year = obj.year;
		kpp = obj.kpp;
		name = obj.name;
		fuel = obj.fuel;
		pplAmount = obj.pplAmount;
		capacity = obj.capacity;
		return *this;
	}

	~Troll() {

	};
	friend  istream& operator >> (istream& in, Troll& ob);
	friend ostream& operator << (ostream& out, Troll& ob);
	void setCapacity();
	void show();
	void edit();
	const int getCapacity();
	friend fstream& operator>> (fstream& f, Troll& obj);
	friend fstream& operator<< (fstream& f, Troll& obj);

	friend ifstream& operator>> (ifstream& f, Troll& obj);
	friend ofstream& operator<< (ofstream& f, Troll& obj);
protected:
	int capacity = 1500;
};