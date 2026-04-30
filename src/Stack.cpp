#include "Stack.h"

template <class T> Stack<T>::Stack() {
    this->TOP = INITIAL_VALUE;
}

template <class T> bool Stack<T>::Push(T element) {
    if (isFull()) {
        return false;
    }

    arrStack[TOP++] = element;
    return true;
}

template <class T> bool Stack<T>::isEmpty() {
    return TOP == INITIAL_VALUE;
}

template <class T> bool Stack<T>::isFull() {
    return TOP == SIZE;
}

template <class T> T Stack<T>::Pop() {
    if (isEmpty()) {
        throw "POP no realizado. Stack vacio";
    }

    return arrStack[--TOP];
}

template <class T> T Stack<T>::Top() {
    if (isEmpty()) {
        throw "Top no realizado. Stack vacio";
    }

    return arrStack[TOP - 1];
}

template <class T> void Stack<T>::Empty() {
    TOP = INITIAL_VALUE;
}

template <class T> int Stack<T>::Size() {
    return TOP;
}

template <class T> void Stack<T>::Print() {
    cout << "[";
    for (int i = 0; i < TOP; i++) {
        cout << "  " << arrStack[i];
    }
    cout << "  ]" << endl;
}

template class Stack<int>;
template class Stack<float>;
template class Stack<char>;