#include "Queue.h"
#include "Coord.h"

template <class T> Queue<T>::Queue() {
  this->front = 0;
  this->tail = SIZEC - 1;
  this->numElem = 0;
}

template <class T> int Queue<T>::next(int n) { return (n + 1) % SIZEC; }

template <class T> bool Queue<T>::isEmpty() { return front == next(tail); }

template <class T> bool Queue<T>::isFull() { return front == next(next(tail)); }

template <class T> bool Queue<T>::Insert(T element) {
  if (isFull()) {
    return false;
  }

  tail = next(tail);
  arrQueue[tail] = element;
  numElem++;
  return true;
}

template <class T> T Queue<T>::Dequeue() {
  if (isEmpty()) {
    throw "Dequeue no realizado. Cola vacia";
  }

  T element = arrQueue[front];
  front = next(front);
  numElem--;
  return element;
}

template <class T> T Queue<T>::Front() {
  if (isEmpty()) {
    throw "Frente vacio";
  }

  return arrQueue[front];
}

template <class T> int Queue<T>::Size() { return numElem; }

template <class T> void Queue<T>::Print() {
  cout << "[";
  for (int i = front; i <= tail; i++) {
    cout << "  " << arrQueue[i];
  }
  cout << "  ]" << endl;
}

template class Queue<int>;
template class Queue<float>;
template class Queue<char>;
template class Queue<Coord>;
