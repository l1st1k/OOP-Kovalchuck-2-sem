#include <iostream>
#include <string>
#include <functional>
#include "validation.h"
using namespace std;

template<class T>
class LinkedList {                        //linkedlist class
private:                             //private data members
	struct node                      //definiton of structure node
	{
		T data;                      //data variable
		node* next;                  //next node pointer
	};
	node* h;                         //pointer pointing to head of linked list
	node* n;                         //pointer pointing to newly created node
	node* t;
	node* createnode(T data);       //function to create new node, pack them with data and return the pointer to the location
	int size_ll;                    //variable to store size of linked list 

public:
	LinkedList();                   //constructor
	void add(T data);               //function prototype to add new node to the linked list
	T& operator[](int location);    //operator overloading to access the contents of linked list just like a array
	void del(int location);         //function to delete the node
	T pop(int location);
	int size();	                    //function to return the size of linked list
	void displayAll();              //displays all the elements of list
	void sort(function<bool(T obj1, T obj2)> comp);
	template<typename Attr>
	T& find(function<bool(T obj, Attr attr)> equalFunc, Attr _attr);

	//added from course/w
	void clean(); // очистка листа
	bool isListEmpty(); // проверка на наличие объектов в листе
};


/////////////////// constructor //////////////////////////////////////
template<class T>
LinkedList<T>::LinkedList()
{
	h = nullptr;                  //intialize the values of the variables
	n = nullptr;
	t = nullptr;
	size_ll = 0;
}
/////////////////////////////////////////////////////////////////////
template<typename T>
bool LinkedList<T>::isListEmpty() {
	if (this->h == NULL) return true;
	else return false;
}

template<typename T>
void LinkedList<T>::clean()
{
	node * p, * q;
	p = h;
	while (p != NULL)
	{
		q = p->next;
		delete p;
		p = q;
	}
	h = NULL;
	n = NULL;
}


///////////////// create node function /////////////////////////////
template<class T>
typename LinkedList<T>::node* LinkedList<T>::createnode(T data)
{
	n = new node;                //create new node
	n->data = data;              //set the data
	n->next = nullptr;

	return n;                    //return the pointer of the new node
}
////////////////////////////////////////////////////////////////////

////////////// add node ///////////////////////////////////////////
template<class T>
void LinkedList<T>::add(T data)
{
	if (h == nullptr)
	{
		h = createnode(data);
		t = h;
		size_ll++;
	}
	else
	{
		t->next = createnode(data);
		t = t->next;
		size_ll++;
	}
}
////////////////////////////////////////////////////////////////////

//////////// operator overloaded function to return the value /////
template<class T>
T& LinkedList<T>::operator[](int location)
{
	int counter = 0;
	node* s = nullptr;
	s = h;
	T* returnval;

	while (s != nullptr)
	{
		counter++;
		if ((counter - 1) == location)
		{
			returnval = &s->data;
		}
		s = s->next;
	}

	return *returnval;
}
//////////////////////////////////////////////////////////////////

///////////// delete node ///////////////////////////////////////
template<class T>
void LinkedList<T>::del(int location)
{
	int counter = 0;
	node* d = nullptr;
	node* d_next = nullptr;
	d = h;

	if (location == 0)
	{
		h = h->next;
		delete d;
		d = nullptr;
	}

	while (d != nullptr)
	{
		counter++;
		if (counter == location)
		{
			d_next = d->next;
			d->next = d_next->next;
			delete d_next;
		}
		d = d->next;
	}
	size_ll--;
}
///////////////////////////////////////////////////////////////////

template<class T>
T LinkedList<T>::pop(int location)
{
	T obj;
	int counter = 0;
	node* d = nullptr;
	node* d_next = nullptr;
	d = h;

	if (location == 0)
	{
		h = h->next;
		obj = d->data;
		delete d;
		d = nullptr;
	}

	while (d != nullptr)
	{
		counter++;
		if (counter == location)
		{
			d_next = d->next;
			d->next = d_next->next;
			obj = d_next->data;
			delete d_next;
		}
		d = d->next;
	}
	size_ll--;
	return obj;
}

///////////// return linked list size /////////////////////////////
template<class T>
int LinkedList<T>::size()
{
	return size_ll;
}


template<class T>
void LinkedList<T>::displayAll() {
	if (h == NULL) {
		cout << "List is empty\n\n";
		return;
	}
	cout  << "Your List:" << endl;
	cout << "№ Название\tГод\tТопливо\tКПП\tПробег\t\tДополнительные сведения\n";
	node* temp = h;
	int num = 1;
	while (temp != NULL) {
		cout <<num <<") ";
		temp->data.show();
		num++;
		temp = temp->next;
	}
	cout << "\n\n";
}

template <class T>
void LinkedList<T>::sort(function<bool(T obj1, T obj2)> comp)
{
	node  * i, * j;

	for (i = this->h; i->next != nullptr; i = i->next)
	{
		for (j = i->next; j != nullptr; j = j->next)
		{
			if (comp(i->data, j->data))
			{
				swap(i->data, j->data);
			}
		}
	}
}


template<class T>
template<typename Attr>
T& LinkedList<T>::find(function<bool(T obj, Attr attr)> equalFunc, Attr _attr)
{
	node* tempNode = h;
	while (tempNode != nullptr)
	{
		if (equalFunc(tempNode->data, _attr)) return tempNode->data;
		tempNode = tempNode->next;
	}
}