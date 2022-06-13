#include "Troll.h"



istream& operator >> (istream& in, Troll& ob) {
	cout << "Введите данные тролейбуса: \n";
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
	cout << ob.name << "\t\t" << ob.year << "\t" << ob.fuel << "\t" << ob.kpp << "\t" << ob.probeg << " km\t" << ob.pplAmount << " people\t" << ob.capacity << " кВт" << endl;
	return out;
}

void Troll::show() {
	cout << name << "\t" << year << "\t" << fuel << "\t" << kpp << "\t" << probeg << " km\t\t" << pplAmount << " people\t" << capacity << " кВт"<<endl;
}

void Troll::setCapacity() {
	cout << "Введите мощность электроблока(500-4000 кВт):\n";
	this->capacity = inputNumber(500, 4000);
}
const int Troll::getCapacity() {
	return capacity;
}

void Troll::edit() {
	bool flag = true;
	while (flag) {
		cout << "Название\t\tГод\tТопливо\tКПП\tПробег\t\tДополнительные сведения\n";
		this->show();
		cout << "\nВыберите параметр (введите 0 для выхода из меню редактирования)\n1) Название\n2) Год выпуска\n3) Тип топлива\n4) Тип коробки переключения передач\n5) Пробег (в км)\n6) Количество пасажиров\n7) Мощность электроблока\n";
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