#pragma once

#include <iostream>
#include <string>
#include "validation.h"
#include "Auto.h"
using namespace std;


class Heavy : public Auto {
public:
	Heavy() {

	};
	
	Heavy(int lift,string name, string kpp, string fuel, int year, int probeg) : Auto( name,  kpp,  fuel,  year,  probeg) {
		this->lift = lift;
	};
	Heavy(const Heavy& obj) : Heavy(obj.lift, obj.name, obj.kpp, obj.fuel, obj.year, obj.probeg) {};
	~Heavy() {

	};

	Heavy& operator =(Heavy obj)
	{
		probeg = obj.probeg;
		year = obj.year;
		kpp = obj.kpp;
		name = obj.name;
		fuel = obj.fuel;
		lift = obj.lift;

		return *this;
	}
	void setLift();
	void show();
	void edit();
	int getLift();
	friend fstream& operator>> (fstream& f, Heavy& obj);
	friend fstream& operator<< (fstream& f, Heavy& obj);

	friend ifstream& operator>> (ifstream& f, Heavy& obj);
	friend ofstream& operator<< (ofstream& f, Heavy& obj);
protected:
	int lift = 1500;
};
