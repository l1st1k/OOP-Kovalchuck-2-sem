#pragma once

#include <iostream>
#include "node.cpp"

template<class T>
class List;
template<class T>
class Algorithm;

template <class T>
class Iterator
{
	friend class List<T>;
	friend class Algorithm<T>;
public:
	Iterator(Node<T>* node) noexcept : iter_node(node) {}

	Iterator& operator =(Node<T>* node);
	Iterator& operator ++();
	Iterator& operator ++(int);
	Iterator& operator --();
	Iterator& operator --(int);
	bool operator != (const Iterator& iterator);
	bool operator == (const Iterator& iterator);
	T& operator *();
	friend ostream& operator<< (ostream& stream, Iterator& it)
	{
		stream << *it;
		return stream;
	};
private:
	Node<T>* iter_node;
};
