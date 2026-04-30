#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"

template <class T> class Linked_List {
private:
  int size;
  Node<T> *head;

public:
  Linked_List();
  ~Linked_List();

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
