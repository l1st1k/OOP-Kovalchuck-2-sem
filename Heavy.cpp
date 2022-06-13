#include "Heavy.h"

void Heavy::setLift() {
	cout << "������� ��������������� ���������� (� ��):\n";
	this->lift = inputNumber(500, 50000);
}

void Heavy::show() {
	cout << name << "\t" << year << "\t" << fuel << "\t" << kpp << "\t" << probeg << " km\t" << lift << " kg." << endl;
}

int Heavy::getLift() {
	return lift;
}

void Heavy::edit() {
	bool flag = true;
	while (flag) {
		cout << "��������\t\t���\t�������\t���\t������\t\t�������������� ��������\n";
		this->show();
		cout << "\n�������� �������� (������� 0 ��� ������ �� ���� ��������������)\n1) ��������\n2) ��� �������\n3) ��� �������\n4) ��� ������� ������������ �������\n5) ������ (� ��)\n6) ����������������\n";
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
			this->setLift();
		}
		system("cls");
	}
}

fstream& operator>>(std::fstream& f, Heavy& obj)
{
	f >> dynamic_cast<Auto&>(obj);

	f.read(reinterpret_cast<char*>(&obj.lift), sizeof(obj.lift));
	return f;
}

fstream& operator<<(fstream& f, Heavy& obj)
{
	f << dynamic_cast<Auto&>(obj);

	f.write(reinterpret_cast<char*>(&obj.lift), sizeof(obj.lift));
	return f;
}

ifstream& operator>>(ifstream& f, Heavy& obj)
{
	f >> dynamic_cast<Auto&>(obj)
		>> obj.lift;
	return f;
}

ofstream& operator<<(ofstream& f, Heavy& obj)
{
	f << dynamic_cast<Auto&>(obj)
		<< obj.lift << " ";
	return f;
}