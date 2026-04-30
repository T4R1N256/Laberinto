#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int SIZE = 50;
const int INITIAL_VALUE = 0;

template <class T> class Stack {
private:
  int TOP;
  T arrStack[SIZE];

public:
  Stack();

  bool Push(T elemento);
  bool isEmpty();
  bool isFull();
  T Pop();
  T Top();
  void Empty();
  int Size();
  void Print();
};

#endif
