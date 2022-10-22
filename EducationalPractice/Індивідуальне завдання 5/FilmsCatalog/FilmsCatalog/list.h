#pragma once
#include <stdlib.h>
#include <iostream>  
using namespace std;

template <class T>
class List
{
public:
    template <class T>
    struct Node
    {
        T data;
        Node<T>* next;
        Node(T data = T(), Node* next = nullptr)
            : data(data), next(next)
        {}
    };
private:
    Node<T>* top;
    size_t size;

public:
    List();
    List(const List& L);
    ~List();

    size_t getLength();
    bool isEmpty();

    T& Front();
    void push_front(const T& val);
    void pop_front();

    T& Back();
    void push_back(const T& val);
    void pop_back();

    void printList() const;
};

template <class T>
List<T>::List()
    : top(nullptr), size(0)
{}

template <class T>
List<T>::List(const List& L)
    : top(nullptr), size(L.size)
{
    if (L.size > 0)
    {
        top = new Node<T>(L.top->data, nullptr);
        Node<T>* curr = top;
        Node<T>* L_curr = L.top;
        while (L_curr->next)
        {
            curr->next = new Node<T>(L_curr->next->data);
            curr = curr->next;
            L_curr = L_curr->next;
        }
    }
}

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
size_t List<T>::getLength()
{
    cout << "\nLength: " << size << "\n";
    return size;
}

template <class T>
bool List<T>::isEmpty()
{
    if (top == nullptr)
    {
        cout << "\nEmpty List\n";
        return true;;
    }
    else
    {
        cout << "\nNot Empty List\n";
        return false;;
    }
}

template <class T>
T& List<T>::Front()
{
    if (top)
    {
        cout << "\nFront: " << top->data << "\n";
        return top->data;
    }
    else throw std::range_error("Empty list");
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
    if (top == nullptr) throw std::range_error("Empty list");
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
T& List<T>::Back()
{
    if (size == 0) throw std::range_error("Empty list");
    else
    {
        Node<T>* ptr = top;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        cout << "\nBack: " << ptr->data << "\n";
        return ptr->data;
    }
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
            cout << "\nEmpty List\n" << endl;
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

template <class T>
void List<T>::printList() const
{
    if (size == 0) throw std::range_error("Empty list");
    else
    {
        cout << "\n*List*\n\n";
        Node<T>* ptr = top;
        while (ptr != nullptr)
        {
            cout << "\n" << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << "\n";
    }
}


