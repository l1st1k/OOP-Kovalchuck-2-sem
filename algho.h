#pragma once
#include "Exception_vvod.h"

using namespace std;

string string_input(istream& in) {
	bool first_flag = true;
	int flag;
	string str;
	do {
		try {
			flag = 0;
			cout << "������� ������:\t";
			getline(in,str);
			for (int i = 0; i < str.length(); i++) {
				if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z') && (str[i] != ' '))
					throw Exception_vvod(99, "��������� ������������� �������� ������ ����������� ��������");
			}
			if (str[0] < 'A' || str[0] > 'Z') { // �������� �� ��������� �����
				throw Exception_vvod(100, "������ ����� ������ ���� ���������");
			} 
		}
		catch (Exception_vvod ob)
		{
			rewind(stdin);
			flag = 1;
			ob.show();
		}
		catch (...)
		{
			rewind(stdin);
			flag = 1;
			cout << "����������������� ������\n";
		}
	} while (flag);
	return str;
}


template<typename T>
T input_digit(T left_border, T right_border, bool isNeg = false)
{
	int flag = 0;
	T dig;
	do
		{
			try
			{
				flag = 0;
				cin >> dig;
				//������
				if (isNeg && dig >= 0) throw Exception_vvod(88, "��������� ���� �������������� �����!");
				if (!isNeg && dig < 0) throw Exception_vvod(89, "��������� ���� ���������������� �����!");

				if (!(dig) || cin.get() != '\n')
				{
					string msg = "��� ��������� �������� ������ ���� - " + (string)typeid(dig).name() + "!";
					throw Exception_vvod(87, msg.c_str());
				}

				if (left_border < right_border && !(dig >= left_border && dig <= right_border))
				{
					string message = "��������� ����� ������ ���� � ��������� �� " + to_string(left_border) + " �� " + to_string(right_border) + "!";
					throw Exception_vvod(90, message.c_str());
				}
			}
			catch (Exception_vvod ob)
			{
				cin.clear();
				rewind(stdin);
				flag = 1;
				ob.show();
			}
			catch (...)
			{
				cin.clear();
				rewind(stdin);
				flag = 1;
			}

	} while (flag);
	return dig;
}