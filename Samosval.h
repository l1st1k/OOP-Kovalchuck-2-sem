#pragma once

#include <iostream>
#include <string>
#include "validation.h"
#include "Auto.h"
#include "Heavy.h"
using namespace std;


class Samosval : public Heavy {
public:
	Samosval() {

	};

	Samosval(int height, int lift, string name, string kpp, string fuel, int year, int probeg) : Heavy(lift, name, kpp, fuel, year, probeg) {
		this->height = height;
	};
	Samosval(const Samosval& obj) : Samosval(obj.height, obj.lift, obj.name, obj.kpp, obj.fuel, obj.year, obj.probeg) {};

	Samosval& operator =(Samosval obj)
	{
		probeg = obj.probeg;
		year = obj.year;
		kpp = obj.kpp;
		name = obj.name;
		fuel = obj.fuel;
		lift = obj.lift;
		height = obj.height;
		return *this;
	}

	~Samosval() {

	};
	friend  istream& operator >> (istream& in, Samosval &ob);
	friend  ostream& operator << (ostream& out, Samosval& ob);
	void setHeight();
	void show();
	void edit();
	int getHeight()const;
	friend fstream& operator>> (fstream& f, Samosval& obj);
	friend fstream& operator<< (fstream& f, Samosval& obj);

	friend ifstream& operator>> (ifstream& f, Samosval& obj);
	friend ofstream& operator<< (ofstream& f, Samosval& obj);
protected:
	int height = 3;
};