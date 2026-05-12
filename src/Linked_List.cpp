#include "Linked_List.h"
#include "Node.h"
#include "Coord.h"
#include <iostream>

template <class T> Linked_List<T>::Linked_List() {
  head = NULL;
  size = 0;
}

template <class T> Linked_List<T>::~Linked_List() {
  if (head == NULL)
    return;

  Node<T> *actual = head;

  do {
    Node<T> *prev;
    prev = actual;
    actual = actual->getNext();
    delete prev;
  } while (actual != head);

  head = NULL;
}

template <class T> void Linked_List<T>::insertLast(T d) {
  Node<T> *newNode = new Node<T>(d);

  if (head != NULL) {
    newNode->setNext(head->getNext());
    newNode->setPrevious(head);

    head->setNext(newNode);

    newNode->getNext()->setPrevious(newNode);
  }

  size++;
  head = newNode;
}

template <class T> void Linked_List<T>::insertAfter(Node<T> *n, T d) {
  Node<T> *newNode = new Node<T>(d);

  if (n == head)
    head = newNode;

  newNode->setNext(n->getNext());
  newNode->setPrevious(n);

  n->setNext(newNode);

  newNode->getNext()->setPrevious(newNode);

  size++;
}

template <class T> void Linked_List<T>::insertFirst(T d) {
  Node<T> *newNode = new Node<T>(d);

  if (isEmpty()) {
    head = newNode;
  } else {
    newNode->setPrevious(head);
    newNode->setNext(head->getNext());

    newNode->getNext()->setPrevious(newNode);

    head->setNext(newNode);
  }

  size++;
}

template <class T> Node<T> *Linked_List<T>::get(int p) {
  if (p > getSize() && isEmpty())
    return NULL;

  Node<T> *current = head->getNext();

  for (int i = 0; i < p; i++) {
    current = current->getNext();
  }

  return current;
}

template <class T> Node<T> *Linked_List<T>::search(T d) {
  Node<T> *index = head;

  if (!isEmpty()) {
    do {
      if (d == index->getData())
        return index;

      index = index->getNext();
    } while (index != head);
  }

  return NULL;
}

template <class T> void Linked_List<T>::deleteNode(T d) {
  Node<T> *actual = head;
  bool found = false;

  while ((actual->getNext() != head) && (!found)) {
    found = (actual->getNext()->getData() == d);

    if (!found) {
      actual = actual->getNext();
    }
  }

  found = (actual->getNext()->getData() == d);

  if (found) {
    Node<T> *nodo_encontrado;
    nodo_encontrado = actual->getNext();

    if (head == head->getNext())
      head = NULL;
    else {
      if (nodo_encontrado == head)
        head = actual;

      actual->setNext(nodo_encontrado->getNext());

      nodo_encontrado->getNext()->setPrevious(nodo_encontrado->getPrevious());
    }
    size--;
    delete nodo_encontrado;
  }
}

template <class T> void Linked_List<T>::deleteList() {
  if (head == NULL)
    return;

  Node<T> *actual = head;

  do {
    Node<T> *prev;
    prev = actual;
    actual = actual->getNext();
    delete prev;
  } while (actual != head);

  head = NULL;
}

template <class T> bool Linked_List<T>::isEmpty() { return !size; }

template <class T> void Linked_List<T>::printForward() {
  Node<T> *current;

  if (head == NULL)
    return;

  current = head->getNext();

  std::cout << "[ ";

  do {
    std::cout << current->getData();

    current = current->getNext();

    if (current != head->getNext())
      std::cout << ", ";

  } while (current != head->getNext());

  std::cout << " ]" << std::endl;
}

template <class T> void Linked_List<T>::printBackwards() {
  Node<T> *current;

  if (head == NULL)
    return;

  current = head;

  std::cout << "[ ";

  do {
    std::cout << current->getData();

    current = current->getPrevious();

    if (current != head)
      std::cout << ", ";

  } while (current != head);

  std::cout << " ]" << std::endl;
}

template <class T> int Linked_List<T>::getSize() { return size; }

template class Linked_List<int>;
template class Linked_List<int *>;
template class Linked_List<float>;
template class Linked_List<char>;
template class Linked_List<Coord>;
