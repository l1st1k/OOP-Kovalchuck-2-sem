#include "Passenger.h"


void Passenger::setPeopleAmount() {
	cout << "������� ���������� ���������:\n";
	this->pplAmount = inputNumber(2, 100);
}

void Passenger::show() {
	cout << name << "\t" << year << "\t" << fuel << "\t" << kpp << "\t" << probeg << " km\t" << pplAmount << " people" << endl;
}

int Passenger::getPeopleAmount() {
	return pplAmount;
}

void Passenger::edit() {
	bool flag = true;
	while (flag) {
		cout << "��������\t\t���\t�������\t���\t������\t\t�������������� ��������\n";
		this->show();
		cout << "\n�������� �������� (������� 0 ��� ������ �� ���� ��������������)\n1) ��������\n2) ��� �������\n3) ��� �������\n4) ��� ������� ������������ �������\n5) ������ (� ��)\n6) ���������� ���������\n";
		int user_choice = inputNumber(0, 6);
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
		}
		system("cls");
	}
}

fstream& operator>>(std::fstream& f, Passenger& obj)
{
	f >> dynamic_cast<Auto&>(obj);

	f.read(reinterpret_cast<char*>(&obj.pplAmount), sizeof(obj.pplAmount));
	return f;
}

fstream& operator<<(fstream& f, Passenger& obj)
{
	f << dynamic_cast<Auto&>(obj);

	f.write(reinterpret_cast<char*>(&obj.pplAmount), sizeof(obj.pplAmount));
	return f;
}

ifstream& operator>>(ifstream& f, Passenger& obj)
{
	f >> dynamic_cast<Auto&>(obj)
		>> obj.pplAmount;
	return f;
}

ofstream& operator<<(ofstream& f, Passenger& obj)
{
	f << dynamic_cast<Auto&>(obj)
		<< obj.pplAmount << " ";
	return f;
}