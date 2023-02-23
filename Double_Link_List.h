#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "Node.h"
#include <iostream>
using namespace std;

template <class T>
class DoubleLinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int nodeCount;

public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    Node<T> *getHead();
    Node<T> *getTail();
    void setHead(Node<T> *);
    void setTail(Node<T> *);
    int getNodeCount();
    void setNodeCount(int);
    bool isEmpty();
    int indexOf(const T); //Tim kiem phan tu trung va tra ve vi tri phan tu do
    T findByID(const string &);
    void Prepend(T data); // thêm vào đầu
    void Append(T data);  // thêm vào cuối
    void AppendAt(T data, int p); //Them vao vi tri bat ky
    void RemoveHead(); // xóa phần tử đầu
    void RemoveTail(); // xóa phần tử cuối
    bool removeAt(const int &);

    void Show();
    bool remove(const T); // <- viết
};

template <class T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    this->head = NULL;
    this->tail = NULL;
    this->nodeCount = 0;
}
template <class T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    Node<T> *p = this->head;
    while (this->head != this->tail)
    {
        p = this->head;
        this->head = this->head->getNext();
        delete p;
    }
    delete this->tail;
}
template <class T>
Node<T> *DoubleLinkedList<T>::getHead()
{
    return head;
}

template <class T>
Node<T> *DoubleLinkedList<T>::getTail()
{
    return tail;
}
template <class T>
void DoubleLinkedList<T>::setHead(Node<T> *head)
{
    this->head = head;
}
template <class T>
void DoubleLinkedList<T>::setTail(Node<T> *tail)
{
    this->tail = tail;
}

template <class T>
int DoubleLinkedList<T>::getNodeCount()
{
    return this->nodeCount;
}
template <class T>
void DoubleLinkedList<T>::setNodeCount(int count)
{
    this->nodeCount = count;
}
template <class T>
bool DoubleLinkedList<T>::isEmpty()
{
    return this->head == NULL;
}

template <class T>
void DoubleLinkedList<T>::Prepend(T data)   //Them vao dau
{
    if (this->head == NULL)
    {
        Node<T> *NewNode = new Node<T>;
        NewNode->setData(data);
        this->tail = NewNode;
        this->head = NewNode;
        this->nodeCount++;
    }
    else
    {
        Node<T> *NewNode = new Node<T>;
        NewNode->setData(data);
        NewNode->setNext(head);
        this->head->setPrev(NewNode);
        this->head = NewNode;
        this->nodeCount++;
    }
}
template <class T>
void DoubleLinkedList<T>::AppendAt(T data, int p)   
{
    if (this->head == NULL)
    {
        Node<T> *NewNode = new Node<T>;
        NewNode->setData(data);
        this->tail = NewNode;
        this->head = NewNode;
        this->nodeCount++;
    }
    else
    {
        p = p - 2;
        Node<T> *ptr = this->head;
        while (p != 0)
        {
            ptr = ptr->getNext();
            p--;
        }

        Node<T> *middleNode = new Node<T>;
        middleNode->setData(data);
        middleNode->setNext(ptr->getNext());
        ptr->getNext()->setPrev(middleNode);

        ptr->setNext(middleNode);
        middleNode->setPrev(ptr);

        ptr = head;
    }
}
template <class T>
void DoubleLinkedList<T>::Append(T data)    //Them vao cuoi
{
    if (this->head == NULL)
    {
        Node<T> *NewNode = new Node<T>;
        NewNode->setData(data);
        this->tail = NewNode;
        this->head = NewNode;
        this->nodeCount++;
    }
    else
    {
        Node<T> *NewNode = new Node<T>;
        NewNode->setData(data);
        NewNode->setPrev(tail);
        tail->setNext(NewNode);
        tail = NewNode;
        nodeCount++;
    }
}

template <class T>
int DoubleLinkedList<T>::indexOf(const T element)
{
    int index = 0;
    Node<T> *p = this->getHead();
    while (p != NULL)
    {
        if (p->getData() == element)
            return index;
        index++;
        p = p->getNext();
    }
    return -1;
}

template <class T>
void DoubleLinkedList<T>::RemoveHead()  // Xoa dau
{
    Node<T> *p = this->head->getNext();
    delete this->head;
    this->setHead(p);
    this->head->setPrev(NULL);
    this->nodeCount -= 1;
}
template <class T>
void DoubleLinkedList<T>::RemoveTail()
{
    Node<T> *p = this->tail->getPrev();
    delete this->tail;
    this->setTail(p);
    this->tail->setNext(NULL);
    this->nodeCount -= 1;
}

template <class T>
bool DoubleLinkedList<T>::removeAt(const int &index)
{
    if (index < 0 || index >= this->nodeCount)
        return false;
    else
    {
        if (index == 0)
        {
            this->RemoveHead();
            return true;
        }
        if (index == nodeCount - 1)
        {
            this->RemoveTail();
            return true;
        }
        int i = 0;
        Node<T> *p = this->head;
        while (i != index)
        {
            i++;
            p = p->getNext();
        }
        Node<T> *temp = p;
        p->getPrev()->setNext(p->getNext());
        p->getNext()->setPrev(p->getPrev());
        this->nodeCount -= 1;
        delete temp;
        return true;
    }
}
template <class T>
bool DoubleLinkedList<T>::remove(const T element)
{
    int index = this->indexOf(element);
    if (index == -1)
        return false;
    else
    {
        this->removeAt(index);
        return true;
    }
}

template <class T>
void DoubleLinkedList<T>::Show()
{
    Node<T> *ptr = this->head;
    while (ptr != NULL)
    {
        ptr->getData().show();
        ptr = ptr->getNext();
    }
}

template <class T>
T DoubleLinkedList<T>::findByID(const string &ID)
{
    Node<T> *ptr = this->head;
    while (ptr != NULL)
    {
        if (ptr->getData().getId() == ID)
            return ptr->getData();
        ptr = ptr->getNext();
    }
    return T();
}
#endif