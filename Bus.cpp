#include "Bus.h"



istream& operator >> (istream& in, Bus& ob) {
	cout << "Введите данные автобуса: \n";
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
	cout << ob.name << "\t" << ob.year << "\t" << ob.fuel << "\t" << ob.kpp << "\t" << ob.probeg << " km\t\t" << ob.pplAmount << " people\tМаршрут №" << ob.number << endl;
	return out;
}

void Bus::show(){
	cout << name << "\t" << year << "\t" << fuel << "\t" << kpp << "\t" << probeg << " km\t\t" << pplAmount << " people\tМаршрут №" << number << endl;
}

void Bus::setNumber() {
	cout << "Введите номер маршрута:\n";
	this->number = inputNumber(1, 500);
}

const int Bus::getNumber() {
	return number;
}

void Bus::edit() {
	bool flag = true;
	while (flag) {
		cout << "Название\t\tГод\tТопливо\tКПП\tПробег\t\tДополнительные сведения\n";
		this->show();
		cout << "\nВыберите параметр (введите 0 для выхода из меню редактирования)\n1) Название\n2) Год выпуска\n3) Тип топлива\n4) Тип коробки переключения передач\n5) Пробег (в км)\n6) Количество пасажиров\n7) Номер маршрута\n";
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