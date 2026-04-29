#ifndef NODE_H
#define NODE_H

template <class T> class Node 
{
private:
    T data;
    Node<T> *next;
    Node<T> *previous;

public:
    Node(T d);

    T getData();
    void setData(T d);

    Node<T> *getNext();
    void setNext(Node<T> *n);

    Node<T> *getPrevious();
    void setPrevious(Node<T> *n);
};

#endif
