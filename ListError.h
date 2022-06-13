#pragma once
#include <stdexcept>
#include <iostream>
using namespace std;
class ListError : public exception  
{
public:
	ListError(const char* error) : exception(error) { this->error = error; }
	const  char* error_msg() { return error.c_str(); }
	void show() {
		cout <<"Îøèáêà: " <<error << endl;
	}
private:
	string error;
};