#include "List.h"

template<class T>
void List<T>::clear()
{
	for (int i = 0; i != this->size(); ++i)
	{
		this->delete_by_id(i);
	}
}

template<class T>
List<T>& List<T>::operator=(List<T> list)
{
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		this->pushBack(*it);
	}
	return *this;
}

template<class T>
void List<T>::pushBack(T node)
{
	Node<T>* newNode = new Node<T>();
	newNode->data = node;

	if (head == nullptr)
	{
		head = newNode;
		return;
	}

	Node<T>* tempNode = head;
	while (tempNode->next != nullptr) tempNode = tempNode->next;

	tempNode->next = newNode;

	newNode->next = nullptr;
	newNode->prev = tempNode;
}

template<class T>
void List<T>::addFront(T node)
{
	Node<T>* newNode = new Node<T>(), * linkPrevHead = head;
	newNode->data = node;

	head = newNode;
	head ->prev = nullptr;
	head->next = linkPrevHead;
}

template<class T>
T List<T>::popBack()
{
	return delete_by_id(size() - 1);
}

template<class T>
T List<T>::popFront()
{
	if (head == nullptr) throw ListError("Невозможно удалить элемент из пустого списка!");

	Node<T>* linkPrevHead = head;
	head = head->next;

	T temp = linkPrevHead->data;
	delete linkPrevHead;

	return temp;
}

template<class T>
T List<T>::delete_by_id(int index)
{
	try {
		if (head == nullptr) throw ListError("Невозможно удалить элемент из пустого списка!");
		else if (index >= size() || index < 0) throw ListError("Выход за пределы списка!");
	}
	catch (ListError ob) {
		ob.show();
	}
	if (index == 0) return popFront();
	else
	{
		Node<T>* tempNode = head;

		for (int i = 0; i < index; ++i) {
			tempNode = tempNode->next;
		}

		tempNode->prev->next = tempNode->next;

		T temp = tempNode->data;
		delete tempNode;

		return temp;
	}
}

template<class T>
int List<T>::size()
{
	if (head == nullptr) return 0;

	Node<T>* temp = head;
	int counter = 0;

	while (temp != nullptr)
	{
		counter++;
		temp = temp->next;
	}

	return counter;
}

template<class T>
T& List<T>::operator[](int index)
{
	if (index > size() || index < 0) throw ListError("Выход за пределы списка!");;

	Node<T>* temp = head;

	for (int i = 0; i < index; ++i) temp = temp->next;

	try
	{
		temp->data.setId(index); 
	}
	catch (const std::exception&)
	{
	}

	return temp->data;
}

template<class T>
List<T>::operator bool() const
{
	return head != nullptr;
}

template<class T>
Iterator<T> List<T>::begin()
{
	return Iterator<T>(head);
}

template<class T>
Iterator<T> List<T>::end()
{
	return Iterator<T>(nullptr);
}

template<class T>
void List<T>::show()
{
	int i = 1;
	if (*this)
	{
		//system("cls");
		cout << "Your List:" << endl;
		cout << "№  Название\tГод\tТопливо\tКПП\tПробег\t\tДополнительные сведения\n";
		for (Iterator<T> it = this->begin(); it != this->end(); ++it)
		{
			cout << i << ") " << it;
			i++;
		}
	}
	else
	{
		cout << "List is empty!" << endl;
	}
}
