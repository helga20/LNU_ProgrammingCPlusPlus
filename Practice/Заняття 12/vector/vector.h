#pragma once
#include <iostream>
using namespace std;

class EmptyVectorException
{
public:
    void report() const;
};

class FullVectorException
{
public:
    void report() const;
};

class InvalidIndexException
{
private:
    size_t index;
public:
    InvalidIndexException(size_t i);
    void report() const;
};

class IntVector
{
private:
    int* vect;
    size_t maxSize;
    size_t vectLength;

public:
    IntVector(size_t size);
    ~IntVector();

    size_t getSize() const;
    size_t getLenght() const;

    void pushBack(int elem);
    int popBack();
    void pushFront(int elem);
    int popFront();
    int at(size_t index) const;
};

