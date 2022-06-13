#pragma once
//#include "algho.h"
#include "Auto.h"


Auto::Auto(string name, string kpp, string fuel, int year, int probeg)
{
	this->kpp = kpp;
	this->name = name;
	this->year = year;
	this->fuel = fuel;
	this->probeg = probeg;
}

Auto::Auto(const Auto& obj) : Auto(obj.name, obj.kpp, obj.fuel, obj.year, obj.probeg) {}

void Auto::setKpp() {
	cout << "�������� ��� ��� ����������\n1) ����\n2) ����\n";
	int ch = inputNumber(1, 2);
	if (ch == 1) this->kpp = AKPP;
	else this->kpp = MKPP;
}

void Auto::setFuel() {
	cout << "�������� ��� ������� ����������\n1) ������\n2) ������\n";
	int ch = inputNumber(1, 2);
	if (ch == 1) this->fuel = BENZ;
	else this->fuel = DT;
}

void Auto::setName() {
	cout << "������� ����� �������� ������:\n";
	cin >> this->name;// = string_input(cin);
}

void Auto::setProbeg() {
	cout << "������� ������ ���������� (� ��):\n";
	this->probeg = inputNumber(0, 1500000);
}

void Auto::setYear() {
	cout << "������� ��� ������� ����������:\n";
	this->year = inputNumber(1950,2022);
}

void Auto::show() {
	cout << name << "\t" << year << "\t" << fuel << "\t" << kpp << "\t" << probeg << " km\t"  << endl;
}

void Auto::edit() {
	bool flag = true;
	while (flag){
		cout << "��������\t\t���\t�������\t���\t������\n";
		this->show();
		cout << "\n�������� �������� (������� 0 ��� ������ �� ���� ��������������)\n1) ��������\n2) ��� �������\n3) ��� �������\n4) ��� ������� ������������ �������\n5) ������ (� ��)\n";
		int user_choice = inputNumber(0, 5);
		switch (user_choice)
		{
		case 0:
			flag = false;
			break;
		case 1:
			this->setName();
			break;
		case 2:
			this->setYear();
			break;
		case 3:
			this->setFuel();
			break;
		case 4:
			this->setKpp();
			break;
		case 5:
			this->setProbeg();
			break;
		}
		system("cls");
	}
}

string Auto::getName() {
	return name;
}

string Auto::getKpp() {
	return kpp;
}

string Auto::getFuel() {
	return fuel;
}

int Auto::getProbeg() {
	return probeg;
}

int Auto::getYear() {
	return year;
}

fstream& operator>>(std::fstream& f, Auto& obj)
{
	char buf[40]{};

	f.read(reinterpret_cast<char*>(&buf), sizeof(buf));
	//std::string ss = std::string(buf);
	//obj.name = ss;
	obj.name = buf;

	f.read(reinterpret_cast<char*>(&buf), sizeof(buf));
	std::string ss = std::string(buf);
	obj.fuel = ss;

	f.read(reinterpret_cast<char*>(&buf), sizeof(buf));
	ss = std::string(buf);
	obj.kpp = ss;

	f.read(reinterpret_cast<char*>(&obj.year), sizeof(obj.year));
	f.read(reinterpret_cast<char*>(&obj.probeg), sizeof(obj.probeg));
	return f;
}

fstream& operator<<(fstream& f, Auto& obj)
{
	char buf[40];

	strcpy_s(buf, obj.name.length() + 1, obj.name.c_str());
	f.write(reinterpret_cast<char*>(&buf), sizeof(buf));

	strcpy_s(buf, obj.fuel.length() + 1, obj.fuel.c_str());
	f.write(reinterpret_cast<char*>(&buf), sizeof(buf));

	strcpy_s(buf, obj.kpp.length() + 1, obj.kpp.c_str());
	f.write(reinterpret_cast<char*>(&buf), sizeof(buf));

	f.write(reinterpret_cast<char*>(&obj.year), sizeof(obj.year));
	f.write(reinterpret_cast<char*>(&obj.probeg), sizeof(obj.probeg));

	return f;
}

ifstream& operator>>(ifstream& f, Auto& obj)
{
	f >> obj.name >> obj.fuel >> obj.kpp >> obj.year >> obj.probeg;
	return f;
}

ofstream& operator<<(ofstream& f, Auto& obj)
{
	f << obj.name << " " << obj.fuel << " " << obj.kpp << " " << obj.year << " " << obj.probeg << " ";
	return f;
}
