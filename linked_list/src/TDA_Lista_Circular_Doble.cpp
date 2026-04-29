#include "TDA_Lista_Circular_Doble.h"
#include <iostream>
#include "Node.h"

template <class T>
TDA_Lista_Circular_Doble<T>::TDA_Lista_Circular_Doble()
{
    head = NULL;
    size = 0;
}

template <class T>
TDA_Lista_Circular_Doble<T>::~TDA_Lista_Circular_Doble()
{
    Node<T> *actual = head;

    do 
    {
        Node<T> *prev;
        prev = actual;
        actual = actual -> getNext();
        delete prev;
    } while (actual != head);

    head = NULL;
}

template <class T>
void TDA_Lista_Circular_Doble<T>::insertLast(T d)
{
    Node<T> *newNode = new Node<T>(d);

    if (head != NULL)
    {
        newNode -> setNext(head -> getNext());
        newNode -> setPrevious(head);

        head -> setNext(newNode);

        newNode -> getNext() -> setPrevious(newNode);
    }

    size++;
    head = newNode;
}

template <class T>
void TDA_Lista_Circular_Doble<T>::insertAfter(Node<T> *n, T d)
{
    Node<T> *newNode = new Node<T>(d);

    if (n == head)
        head = newNode;

    newNode -> setNext(n -> getNext());
    newNode -> setPrevious(n);

    n -> setNext(newNode);

    newNode -> getNext() -> setPrevious(newNode);

    size++;
}

template <class T>
void TDA_Lista_Circular_Doble<T>::insertFirst(T d)
{
    Node<T> *newNode = new Node<T>(d);

    if (!isEmpty())
    {
        newNode -> setPrevious(head);
        newNode -> setNext(head -> getNext());

        newNode -> getNext() -> setPrevious(newNode);

        head -> setNext(newNode);
    }

    size++;
}

template <class T>
Node<T> * TDA_Lista_Circular_Doble<T>::get(int p)
{
    if (p > getSize() && isEmpty())
        return NULL;

    Node<T> *current = head -> getNext();

    for (int i = 0; i < p; i++)
    {
        current = current -> getNext();
    }

    return current;
}

template <class T>
Node<T> * TDA_Lista_Circular_Doble<T>::search(T d)
{
    Node<T> *index = head;
    
    if (!isEmpty())
    {
        do 
        {
            if (d == index -> getData())
                return index;

            index = index -> getNext();
        } while (index != head);
    }

    return NULL;
}

template <class T>
void TDA_Lista_Circular_Doble<T>::deleteNode(T d)
{
    Node<T> *actual = head;
    bool found = false;

    while ((actual -> getNext() != head) && (!found))
    {
        found = (actual -> getNext() -> getData() == d);

        if (!found)
        {
            actual = actual -> getNext();
        }
    }

    found = (actual -> getNext() -> getData() == d);

    if (found)
    {
        Node<T> *nodo_encontrado;
        nodo_encontrado = actual -> getNext();

        if (head == head -> getNext())
            head = NULL;
        else 
        {
            if (nodo_encontrado == head)
                head = actual;

            actual -> setNext(nodo_encontrado -> getNext());

            nodo_encontrado -> getNext() -> setPrevious(nodo_encontrado -> getPrevious());
        }
        size--;
        delete nodo_encontrado;
    }
}

template <class T>
void TDA_Lista_Circular_Doble<T>::deleteList()
{
    if (head == NULL)
        return;

    Node<T> *actual = head;

    do 
    {
        Node<T> *prev;
        prev = actual;
        actual = actual -> getNext();
        delete prev;
    } while (actual != head);

    head = NULL;
}

template <class T>
bool TDA_Lista_Circular_Doble<T>::isEmpty()
{
    return !size;
}

template <class T>
void TDA_Lista_Circular_Doble<T>::printForward()
{
    Node<T> *current;

    if (head == NULL)
        return;

    current = head -> getNext();

    std::cout << "[ ";

    do
    {
        std::cout << current -> getData();

        current = current -> getNext();

        if (current != head -> getNext())
            std::cout << ", ";

    } while (current != head -> getNext());

    std::cout << "]" << std::endl;
}

template <class T>
void TDA_Lista_Circular_Doble<T>::printBackwards()
{
    Node<T> *current;

    if (head == NULL)
        return;

    current = head;

    std::cout << "[ ";

    do
    {
        std::cout << current -> getData();

        current = current -> getPrevious();

        if (current != head)
            std::cout << ", ";

    } while (current != head );

    std::cout << "]" << std::endl;
}

template <class T>
int TDA_Lista_Circular_Doble<T>::getSize()
{
    return size;
}


template class TDA_Lista_Circular_Doble<int>;
template class TDA_Lista_Circular_Doble<float>;
template class TDA_Lista_Circular_Doble<char>;
