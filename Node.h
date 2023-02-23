#pragma once
#ifndef NODE_H
#define NODE_H
template <class T>
class Node
{
    private:
        Node<T> *Prev;
        Node<T> *Next;
        T data;

    public:
        Node();
        ~Node();
        Node<T> *getNext();
        Node<T> *getPrev();
        T getData();
        void setNext(Node<T> *);
        void setPrev(Node<T> *);
        void setData(T);
};

template <class T>
Node<T>::Node()
{
    this->Next = NULL;
    this->Prev = NULL;
}
template <class T>
Node<T>::~Node()
{
}
template <class T>
Node<T> *Node<T>::getNext()
{
    return this->Next;
}

template <class T>
Node<T> *Node<T>::getPrev()
{
    return this->Prev;
}

template <class T>
void Node<T>::setNext(Node *Next)
{
    this->Next = Next;
}

template <class T>
void Node<T>::setPrev(Node *Prev)
{
    this->Prev = Prev;
}

template <class T>
T Node<T>::getData()
{
    return this->data;
}
template <class T>
void Node<T>::setData(T data)
{
    this->data = data;
}
#endif
