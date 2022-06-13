#include "Bus.h"



istream& operator >> (istream& in, Bus& ob) {
	cout << "������� ������ ��������: \n";
	ob.setName();
	ob.setYear();
	ob.setFuel();
	ob.setProbeg();
	ob.setKpp();
	ob.setPeopleAmount();
	ob.setNumber();
	system("cls");
	return in;
}

ostream& operator << (ostream& out, Bus& ob) {
	cout << ob.name << "\t" << ob.year << "\t" << ob.fuel << "\t" << ob.kpp << "\t" << ob.probeg << " km\t\t" << ob.pplAmount << " people\t������� �" << ob.number << endl;
	return out;
}

void Bus::show(){
	cout << name << "\t" << year << "\t" << fuel << "\t" << kpp << "\t" << probeg << " km\t\t" << pplAmount << " people\t������� �" << number << endl;
}

void Bus::setNumber() {
	cout << "������� ����� ��������:\n";
	this->number = inputNumber(1, 500);
}

const int Bus::getNumber() {
	return number;
}

void Bus::edit() {
	bool flag = true;
	while (flag) {
		cout << "��������\t\t���\t�������\t���\t������\t\t�������������� ��������\n";
		this->show();
		cout << "\n�������� �������� (������� 0 ��� ������ �� ���� ��������������)\n1) ��������\n2) ��� �������\n3) ��� �������\n4) ��� ������� ������������ �������\n5) ������ (� ��)\n6) ���������� ���������\n7) ����� ��������\n";
		int user_choice = inputNumber(0, 7);
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
		case 6:
			this->setPeopleAmount();
			break;
		case 7:
			this->setNumber();
			break;
		}
		system("cls");
	}
}

fstream& operator>>(std::fstream& f, Bus& obj)
{
	f >> dynamic_cast<Passenger&>(obj);

	f.read(reinterpret_cast<char*>(&obj.number), sizeof(obj.number));
	return f;
}

fstream& operator<<(fstream& f, Bus& obj)
{
	f << dynamic_cast<Passenger&>(obj);

	f.write(reinterpret_cast<char*>(&obj.number), sizeof(obj.number));
	return f;
}

ifstream& operator>>(ifstream& f, Bus& obj)
{
	f >> dynamic_cast<Passenger&>(obj)
		>> obj.number;
	return f;
}

ofstream& operator<<(ofstream& f, Bus& obj)
{
	f << dynamic_cast<Passenger&>(obj)
		<< obj.number << endl;
	return f;
}