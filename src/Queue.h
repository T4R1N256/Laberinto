#ifndef COLA_H
#define COLA_H

#include <iostream>
using namespace std;

const int SIZEC = 500;

template <class T> class Queue {
    private:
        int front;
        int tail;
        int numElem;
        T arrQueue[SIZEC];

    public:
        Queue();

        int next(int n);
        bool isEmpty();
        bool isFull();
        bool Insert(T element);
        T Dequeue();
        T Front();
        int Size();
        void Print();
};

#endif