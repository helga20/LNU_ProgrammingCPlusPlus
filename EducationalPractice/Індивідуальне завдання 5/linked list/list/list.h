#pragma once
#include <stdlib.h>
#include <iostream>  
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T>* next;
    Node(T data = T(), Node* next = nullptr)
        : data(data), next(next)
    {}
};

template <class T>
class List
{
private:
    Node<T>* top;
    int size;
public:

    List();
    ~List();

    int getLength();
    bool isEmpty();
    void print();

    T Front();
    void push_front(const T& val);
    void pop_front();

    T Back();
    void push_back(const T& val);
    void pop_back();
};

template <class T>
List<T>::List() 
    : top(nullptr), size(0) 
{}

template <class T>
List<T>::~List()
{
    while (top != nullptr)
    {
        Node<T>* victim = top;
        top = top->next;
        delete victim;
    }
}

template <class T>
int List<T>::getLength()
{
    cout << "\nSize: " << size << "\n";
    return size;
}

template <class T>
bool List<T>::isEmpty()
{
    if (top == nullptr)
    {
        cout << "\nList is empty\n";
        return false;
    }
    else
    {
        return true;
    }
}

template <class T>
void List<T>::print()
{
    cout << "\n*List*\n";
    Node<T>* ptr = top;
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

template <class T>
T List<T>::Front()
{
    if (top)
    {
        cout << "\nFront: " << top->data << "\n";
        return top->data;
    }
    else
    {
        cout << "\nList is empty\n" << endl;
    }
}

template <class T>
void List<T>::push_front(const T& val)
{
    if (top == nullptr)
    {
        top = new Node<T>;
        top->next = nullptr;
        top->data = val;
    }
    else
    {
        Node<T>* ptr = new Node<T>;
        ptr->data = val;
        ptr->next = top;
        top = ptr;
    }
    size++;
}

template <class T>
void List<T>::pop_front()
{
    if (top == nullptr)
    {
        cout << "\nList is empty\n" << endl;
        return;
    }
    else
    {
        cout << "\n" << top->data << " - deleted\n" << endl;
        Node<T>* ptr = top;
        top = top->next;
        delete ptr;
    }
    size--;
}

template <class T>
T List<T>::Back()
{
    if (top == nullptr)
    {
        cout << "\nList is empty\n" << endl;
    }
    Node<T>* ptr = top;
    while (ptr->next != nullptr)
    {
        ptr = ptr->next;
    }
    cout << "\nBack: " << ptr->data << "\n";
    return ptr->data;
}

template <class T>
void List<T>::push_back(const T& val)
{
    Node<T>* ptr = new Node<T>;
    ptr->data = val;
    ptr->next = nullptr;
    if (top == nullptr)
    {
        top = ptr;
    }
    else
    {
        Node<T>* temp = top;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
    size++;
}

template <class T>
void List<T>::pop_back()
{
    if (top != nullptr)
    {
        if (top->next == nullptr)
        {
            top = nullptr;
            cout << "\nList is empty\n" << endl;
        }
        else
        {
            Node<T>* temp = top;
            while (temp->next->next != nullptr)
            {
                temp = temp->next;
            }
            Node<T>* lastNode = temp->next;
            cout << "\n" << lastNode->data << " - deleted\n" << endl;

            temp->next = nullptr;
            free(lastNode);
        }
    }
    size--;
}


