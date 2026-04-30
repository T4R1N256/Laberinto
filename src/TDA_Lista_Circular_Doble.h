#ifndef TDA_LISTA_CIRCULAR_DOBLE_H
#define TDA_LISTA_CIRCULAR_DOBLE_H

#include "Node.h"

template <class T> class TDA_Lista_Circular_Doble
{
private:
    int size;
    Node<T> *head;

public:
    TDA_Lista_Circular_Doble();
    ~TDA_Lista_Circular_Doble();

    void insertLast(T d);
    void insertAfter(Node<T> *n, T d);
    void insertFirst(T d);

    Node<T> *get(int p);
    Node<T> *search(T d);

    void deleteNode(T d);
    void deleteList();

    bool isEmpty();

    int getSize();

    void printForward();
    void printBackwards();
};

#endif // !TDA_LISTA_CIRCULAR_DOBLE_H
