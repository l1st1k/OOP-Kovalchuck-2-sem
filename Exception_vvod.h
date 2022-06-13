#pragma once
#include "Exception.h"
#include <iostream>
#include <string>

using namespace std;

class Exception_vvod : public Exception
{
	string mes;
public:
	Exception_vvod(int kod, string a) :Exception(kod)
	{
		mes = a;
	}
	void show() {
		cout << "Код ошибки: " << kod << "\nСообщение: " << mes << endl;
	}
};