#include "node.h"

template <class T>
Node<T>::Node()
{
    data = T();
    next = nullptr;
    prev = nullptr;
}

template<class T>
Node<T>::Node(T node)
{
    data = node;
    next = nullptr;
    prev = nullptr;
}

template <class T>
ostream& operator<< (ostream& stream, const Node<T>& node)
{
    stream << node.data;
    return stream;
}
