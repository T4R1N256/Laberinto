#include "Node.h"

template <class T>
Node<T>::Node(T d)
{
    data = d;
    next = previous = this;
}

template <class T>
T Node<T>::getData()
{
    return data;
}

template <class T>
void Node<T>::setData(T d)
{
    data = d;
}

template <class T>
Node<T> * Node<T>::getNext()
{
    return next;
}

template <class T>
void Node<T>::setNext(Node<T> *n)
{
    next = n;
}

template <class T>
Node<T> * Node<T>::getPrevious()
{
    return previous;

}
template <class T>
void Node<T>::setPrevious(Node<T> *n)
{
    previous = n;
}

template class Node<int>;
template class Node<float>;
template class Node<char>;
