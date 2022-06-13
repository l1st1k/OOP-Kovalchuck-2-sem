#pragma once
#include <iostream>

using namespace std;

template<class T>
class List;
template<class T>
class Iterator;

template<class T>
class Node
{
    friend class List<T>;   
    friend class Iterator<T>;   
public:
    Node();
    Node(T node);
    T getData() { return data; };
    Node<T>* getNext() { return next; };
    Node<T>* getPrev() { return prev; };
    friend ostream& operator<< (ostream& stream, const Node<T>& node);
private:
    T data;
    Node<T>* next;
    Node<T>* prev;
};
