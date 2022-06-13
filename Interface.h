#pragma once
#include "Algorithm.cpp"
#include "Bus.h"
#include "Samosval.h"
#include "Troll.h"
#include "File.h"
using namespace std;

template<class T>
class Interface
{
protected:
	int file_condition;
	T obj;
	string file_name;
public:
	Interface() : file_condition(0), file_name("") {};
	Interface(string file_name, int file_condition) : file_name(file_name), file_condition(file_condition) {};
	void class_menu();
	static void core();
};