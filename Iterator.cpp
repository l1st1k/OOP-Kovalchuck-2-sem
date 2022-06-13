#include "Iterator.h"


template<class T>
Iterator<T>& Iterator<T>::operator =(Node<T>* node)
{
	iter_node = node;
	return *this;
}

template<class T>
Iterator<T>& Iterator<T>::operator++()
{
	if (iter_node) iter_node = iter_node->next;
	return *this;
}

template<class T>
Iterator<T>& Iterator<T>::operator++(int)
{
	Iterator<T> it = *this;
	++* this;
	return it;
}

template<class T>
Iterator<T>& Iterator<T>::operator--()
{
	if (iter_node) iter_node = iter_node->prev;
	return *this;
}

template<class T>
Iterator<T>& Iterator<T>::operator--(int)
{
	Iterator<T> it = *this;
	--* this;
	return it;
}

template<class T>
bool Iterator<T>::operator != (const Iterator& iterator)
{
	return iter_node != iterator.iter_node;
}

template<class T>
bool Iterator<T>::operator==(const Iterator& iterator)
{
	return iter_node == iterator.iter_node;
}

template<class T>
T& Iterator<T>::operator *()
{
	return iter_node->data;
}