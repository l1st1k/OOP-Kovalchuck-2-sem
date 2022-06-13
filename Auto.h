#pragma once

#include <iostream>
#include <string>
#include "File.h"
#include "validation.h"
using namespace std;

const string AKPP = "ÀÊÏÏ";
const string MKPP = "ÌÊÏÏ";
const string DT = "Äèçåëü";
const string BENZ = "Áåíçèí";

class Auto {
protected:
	string name = "temp_name";
	int probeg = 0;
	int year = 2021;
	string fuel = BENZ;
	string kpp = AKPP;
public:
	Auto () {
		
	}
	
	Auto& operator = (Auto obj)
	{
		probeg = obj.probeg;
		year = obj.year;
		kpp = obj.kpp;
		name = obj.name;
		fuel = obj.fuel;

		return *this;
	}

	Auto(string name, string kpp, string fuel, int year, int probeg);
	Auto(const Auto& obj);

	~Auto() {

	}
	void setFuel();
	void setName();
	void setProbeg();
	void setYear();
	void setKpp();
	string getName();
	string getFuel();
	int getProbeg();
	int getYear();
	string getKpp();
	virtual void show();
	virtual void edit();

	friend fstream& operator >> (std::fstream& f, Auto& obj);
	friend fstream& operator << (fstream& f, Auto& obj);

	friend ifstream& operator >> (ifstream& f, Auto& obj);
	friend ofstream& operator << (ofstream& f, Auto& obj);
};