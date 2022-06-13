#pragma once
#include "Interface.h"

template<class T>
void Interface<T>::class_menu()
{
	int del_choice = 0, sort_choice = 0, search_choice = 0, temp_year = 0;
	string temp_name;
	bool sorted_by_name = false, sorted_by_year = false, sorted_by_probeg = false;
	List<T> list;
	
	while (true)
	{
		cout << "�������� ��������:\n1) ��������\n2) �������\n3) �����\n4) ����������"
			<< "\n5) ��������\n6) ������� �����\n7) ������ �� �����\n8) ������ � ����\n0) �����" << endl;
		switch (inputNumber(0, 8))
		{
		case 0: return;
		case 1:
		{
			T obj;
			cin >> obj;
			list.pushBack(obj);
			break;
		}
		case 2:
			cout << "������� ����� ���������� ����������:\n";
			del_choice = inputNumber(1, list.size());
			list.delete_by_id(del_choice - 1);
			
			break;
		case 3: // ����� 
			Algorithm<T> aG;
			cout << "�������� �������� ��� ������:\n1) �������� ������\n2) ��� �������\n";
			search_choice = inputNumber(1, 2);
			if (search_choice == 1) {
				cout << "������� �������� ������ ��� ������:\n";
				cin >> temp_name;
				cout << "\n\n��������� ������:\n";
				aG.find<string>(list.begin(), list.end(),
					[](Iterator<T> it, string temp_name) -> bool
					{	
						T obj = *it;
						return obj.getName() == temp_name;
					}, (string)temp_name
						);
			}
			else {
				cout << "������� ��� ������� ������ ��� ������:\n";
				temp_year = inputNumber(1950, 2021);
				cout << "\n\n��������� ������:\n";
				aG.find<int>(list.begin(), list.end(),
					[](Iterator<T> it, int temp_year) -> bool
					{
						T obj = *it;
						return obj.getYear() == temp_year;
					}, (int)temp_year);
			}
			break;
		case 4: // ���������� �� ������� ���� ������� ������
		{
			Algorithm<T> aG;
			cout << "1) ����������� �� ��������\n2) ����������� �� ���� �������\n3) ����������� �� �������\n";
			sort_choice = inputNumber(1, 3);
			switch (sort_choice) {
			case 1:
				if (sorted_by_name) // ���������� � �������� ������� �� ���� �� ���������
				{
					aG.sort(list.begin(),list.end(),
						[](Auto ob1, Auto ob2) -> bool
						{
							return ob1.getName() < ob2.getName();
						});
					sorted_by_name = false;
				}
				else {
					aG.sort(list.begin(),list.end(),
						[](Auto ob1, Auto ob2) -> bool
						{
							return ob1.getName() > ob2.getName();
						});
					sorted_by_name = true;
				}
				sorted_by_probeg = false;
				sorted_by_year = false;
				break;
			case 2:
				if (sorted_by_year) // ���������� � �������� ������� �� ���� �� ���������
				{
					aG.sort(list.begin(),list.end(),
						[](Auto ob1, Auto ob2) -> bool
						{
							return ob1.getYear() < ob2.getYear();
						});
					sorted_by_year = false;
				}
				else {
					aG.sort(list.begin(),list.end(),
						[](Auto ob1, Auto ob2) -> bool
						{
							return ob1.getYear() > ob2.getYear();
						});
					sorted_by_year = true;
				}
				sorted_by_name = false;
				sorted_by_probeg = false;
				break;
			case 3:
				if (sorted_by_probeg) // ���������� � �������� ������� �� ���� �� ���������
				{
					aG.sort(list.begin(),list.end(),
						[](Auto ob1, Auto ob2) -> bool
						{
							return ob1.getProbeg() < ob2.getProbeg();
						});
					sorted_by_probeg = false;
				}
				else {
					aG.sort(list.begin(),list.end(),
						[](Auto ob1, Auto ob2) -> bool
						{
							return ob1.getProbeg() > ob2.getProbeg();
						});
					sorted_by_probeg = true;
				}
				sorted_by_name = false;
				sorted_by_year = false;
				break;
			}
			break;
		}
		case 5:
		{
			system("cls");
			list.show();
			break;
		}
		case 6: system("cls"); break;
		case 7:
			{
				T obj;
				list.clear();
				// TXT File case
				if (this->file_condition == 1) {
					File_txt<T> txt(this->file_name);
					txt.open_txt_in();
					while (!txt.eof_txt_in()) {
						txt.read_txt(obj);
						list.pushBack(obj);
					}
					list.delete_by_id(list.size() - 1);
					txt.close_txt_in();
				}
				// BINARY File case
				else if (this->file_condition == 2) {
					File_bin<T> bin(this->file_name);
					while (1) {
						bin.read_txt(obj);
						if (bin.eof_bin())
							break;
						list.pushBack(obj);
					}
				}
			}
			break;
		case 8:
			{
				if (list) {
					T obj{};
					if (this->file_condition == 1) {
						File_txt<T> txt(this->file_name);
						txt.open_txt_out();
						while (list)
						{
							obj = list.popBack();
							txt.write_txt(obj);
						}
						txt.close_txt_out();
					}
					else if (this->file_condition == 2) {
						File_bin<T> bin(this->file_name);
						while (list) {
							obj = list.popBack();
							bin.write_bin(obj);
						}
					}
				}
				break;
			}
		}
	}
}

template<class T>
void Interface<T>::core()
{
	int file_choice = 0, user_choice = 1;
	string temp_file_name;
	while (user_choice != 0) {

		cout << "�������� ��� ����� ��� ������:\n1) ���������\n2) ��������\n0) �����\n";
		file_choice = inputNumber(0, 2);
		if (file_choice == 0)
			break;
		system("cls");
		cout << "�������� ������ ��� ������:\n1) �������\n2) ����������\n3) ��������\n0) �����\n";
		user_choice = inputNumber(0, 3);
		system("cls");
		switch (user_choice) {
		case 1:
		{
			if (file_choice == 1)
				temp_file_name = "b.txt";
			else if (file_choice == 2)
				temp_file_name = "b_bin.txt";
			else
				break;
			Interface<Bus> objBus(temp_file_name, file_choice);
			objBus.class_menu();
			break;
		}
		case 2:
		{
			if (file_choice == 1)
				temp_file_name = "t.txt";
			else if (file_choice == 2)
				temp_file_name = "t_bin.txt";
			else
				break;
			Interface<Troll> objTrolleybus(temp_file_name, file_choice);
			objTrolleybus.class_menu();
			break;
		}
		case 3:
		{
			if (file_choice == 1)
				temp_file_name = "s.txt";
			else if (file_choice == 2)
				temp_file_name = "s_bin.txt";

			Interface<Samosval> objDumpTruck(temp_file_name, file_choice);
			objDumpTruck.class_menu();
			break;
		}
		default:
			user_choice = 0;
			break;
		}
	}
}
