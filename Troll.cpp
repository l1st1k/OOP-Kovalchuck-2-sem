#include "Troll.h"



istream& operator >> (istream& in, Troll& ob) {
	cout << "������� ������ ����������: \n";
	ob.setName();
	ob.setYear();
	ob.setFuel();
	ob.setProbeg();
	ob.setKpp();
	ob.setPeopleAmount();
	ob.setCapacity();
	system("cls");
	return in;
}

ostream& operator << (ostream& out, Troll& ob) {
	cout << ob.name << "\t\t" << ob.year << "\t" << ob.fuel << "\t" << ob.kpp << "\t" << ob.probeg << " km\t" << ob.pplAmount << " people\t" << ob.capacity << " ���" << endl;
	return out;
}

void Troll::show() {
	cout << name << "\t" << year << "\t" << fuel << "\t" << kpp << "\t" << probeg << " km\t\t" << pplAmount << " people\t" << capacity << " ���"<<endl;
}

void Troll::setCapacity() {
	cout << "������� �������� ������������(500-4000 ���):\n";
	this->capacity = inputNumber(500, 4000);
}
const int Troll::getCapacity() {
	return capacity;
}

void Troll::edit() {
	bool flag = true;
	while (flag) {
		cout << "��������\t\t���\t�������\t���\t������\t\t�������������� ��������\n";
		this->show();
		cout << "\n�������� �������� (������� 0 ��� ������ �� ���� ��������������)\n1) ��������\n2) ��� �������\n3) ��� �������\n4) ��� ������� ������������ �������\n5) ������ (� ��)\n6) ���������� ���������\n7) �������� ������������\n";
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
			this->setCapacity();
			break;
		}
		system("cls");
	}
}

fstream& operator>>(std::fstream& f, Troll& obj)
{
	f >> dynamic_cast<Passenger&>(obj);

	f.read(reinterpret_cast<char*>(&obj.capacity), sizeof(obj.capacity));
	return f;
}

fstream& operator<<(fstream& f, Troll& obj)
{
	f << dynamic_cast<Passenger&>(obj);

	f.write(reinterpret_cast<char*>(&obj.capacity), sizeof(obj.capacity));
	return f;
}

ifstream& operator>>(ifstream& f, Troll& obj)
{
	f >> dynamic_cast<Passenger&>(obj)
		>> obj.capacity;
	return f;
}

ofstream& operator<<(ofstream& f, Troll& obj)
{
	f << dynamic_cast<Passenger&>(obj)
		<< obj.capacity << endl;
	return f;
}