#include "Passenger.h"


void Passenger::setPeopleAmount() {
	cout << "Введите количество пасажиров:\n";
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
		cout << "Название\t\tГод\tТопливо\tКПП\tПробег\t\tДополнительные сведения\n";
		this->show();
		cout << "\nВыберите параметр (введите 0 для выхода из меню редактирования)\n1) Название\n2) Год выпуска\n3) Тип топлива\n4) Тип коробки переключения передач\n5) Пробег (в км)\n6) Количество пасажиров\n";
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