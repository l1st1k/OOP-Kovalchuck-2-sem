#include "Samosval.h"



istream& operator >> (istream& in, Samosval &ob) {
	cout << "Введите данные самосвала: \n";
	ob.setName();
	ob.setYear();
	ob.setFuel();
	ob.setProbeg();
	ob.setKpp();
	ob.setLift();
	ob.setHeight();
	system("cls");
	return in;
}

ostream& operator << (ostream& out, Samosval& ob) {
	cout << ob.name << "\t" << ob.year << "\t" << ob.fuel << "\t" << ob.kpp << "\t" << ob.probeg << " km\t\t" << ob.lift << " kg.\t" << ob.height << " m." << endl;
	return out;
}

void Samosval::show() {
	cout << name << "\t" << year << "\t" << fuel << "\t" << kpp << "\t" << probeg << " km\t\t" << lift << " kg.\t" << height << " m." << endl;
}

void Samosval::setHeight() {
	cout << "Введите высоту автомобиля (в метрах):\n";
	this->height = inputNumber(2, 6);
}

int Samosval::getHeight()const  {
	return height;
}

void Samosval::edit() {
	bool flag = true;
	while (flag) {
		cout << "Название\t\tГод\tТопливо\tКПП\tПробег\t\tДополнительные сведения\n";
		this->show();
		cout << "\nВыберите параметр (введите 0 для выхода из меню редактирования)\n1) Название\n2) Год выпуска\n3) Тип топлива\n4) Тип коробки переключения передач\n5) Пробег (в км)\n6) Грузоподъемность\n7) Высота\n";
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
			this->setLift();
			break;
		case 7:
			this->setHeight();
			break;
		}
		system("cls");
	}
}

fstream& operator>>(std::fstream& f, Samosval& obj)
{
	f >> dynamic_cast<Heavy&>(obj);

	f.read(reinterpret_cast<char*>(&obj.height), sizeof(obj.height));
	return f;
}

fstream& operator<<(fstream& f, Samosval& obj)
{
	f << dynamic_cast<Heavy&>(obj);

	f.write(reinterpret_cast<char*>(&obj.height), sizeof(obj.height));
	return f;
}

ifstream& operator>>(ifstream& f, Samosval& obj)
{
	f >> dynamic_cast<Heavy&>(obj)
		>> obj.height;
	return f;
}

ofstream& operator<<(ofstream& f, Samosval& obj)
{
	f << dynamic_cast<Heavy&>(obj)
		<< obj.height << endl;
	return f;
}