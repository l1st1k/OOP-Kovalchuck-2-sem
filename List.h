#pragma once
#include <iostream>
#include <functional>
#include "ListError.h"
#include "Iterator.cpp"

using namespace std;

template<class T>
class List
{
public:
	List() : head(nullptr) {};
	List(T obj) { head->data = obj; };
	~List() { this->clear(); };
	Iterator<T> begin();
	Iterator<T> end();
	void clear();
	int size();
	void pushBack(T node);
	void addFront(T node);
	T popBack();
	T popFront();
	T delete_by_id(int id);
	List<T>& operator = (const List<T> list);
	T& operator [](int index);
	operator bool() const;
	void show();
private:
	Node<T>* head;
};