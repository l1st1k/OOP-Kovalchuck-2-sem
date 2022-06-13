#pragma once
#include <functional>
#include "ListError.h"
#include "List.cpp"

template <class T>
class Algorithm
{
public:
	template<typename Attribute>
	static void find(Iterator<T> beg, Iterator<T> end, function<bool(Iterator<T> t, Attribute attr)> equalFunc, Attribute atrtiibute);
	static void sort(Iterator<T> beg, Iterator<T> end, function<bool(T obj1, T obj2)> comp);
};

