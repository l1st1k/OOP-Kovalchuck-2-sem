#include "Algorithm.h"

template <class T>
template <typename Attribute>
void Algorithm<T>::find(Iterator<T> beg, Iterator<T> end, function<bool(Iterator<T> t, Attribute attr)> equalFunc, Attribute attribute) {
	if (beg == end) throw ListError("Невозможно осуществить поиск в пустом списке!");
	bool flag = false;
	while (beg != end)
	{
		if (equalFunc(beg, attribute)) {
			if (!flag)
				cout << "Название\tГод\tТопливо\tКПП\tПробег\t\tДополнительные сведения\n";
			flag = true;
			cout << beg;
		}
		beg++;
	}
	cout << endl;
	if (!flag)
		cout << "----- Ничего не найдено! -----\n\n";
}

template <class T>
void Algorithm<T>::sort(Iterator<T> beg, Iterator<T> end, function<bool(T obj1, T obj2)> lambda_f) {
	for (Iterator<T> i = beg; i != end; ++i)
	{

		for (Iterator<T> j = ++i; j != end; ++j)
		{
			i--;
			if (lambda_f(*i, *j)) swap(*i, *j);
			i++;
		}
		i--;
	}
}