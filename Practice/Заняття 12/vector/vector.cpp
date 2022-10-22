#include "vector.h"

void EmptyVectorException::report() const
{
    cout << "Vector ERROR: vector is empty\n";
}

// ----------------------------------- //

void FullVectorException::report() const
{
    cout << "Vector ERROR: vector is full\n";
}

// ----------------------------------- //

InvalidIndexException::InvalidIndexException(size_t i)
    : index(i)
{}

void InvalidIndexException::report() const
{
    cout << "Vector ERROR: index " << index << " is invalid\n";
}

// ----------------------------------- //

IntVector::IntVector(size_t size)
    : maxSize(size), vectLength(0), vect(new int[size])
{}

IntVector::~IntVector()
{
    delete[] vect;
}

size_t IntVector::getSize() const
{
    return maxSize;
}

size_t IntVector::getLenght() const
{
    return vectLength;
}

void IntVector::pushBack(int elem)
{
    if (vectLength == maxSize)
    {
        throw FullVectorException();
    }

    vect[vectLength] = elem;
    ++vectLength;
}


int IntVector::popBack()
{
    if (vectLength == 0)
    {
        throw EmptyVectorException();
    }

    int popValue = vect[vectLength - 1];
    --vectLength;
    return popValue;
}

int IntVector::at(size_t index) const
{
    if (index < 0 || index >= vectLength)
    {
        throw InvalidIndexException(index);
    }

    return vect[index];
}

void IntVector::pushFront(int elem)
{
    if (vectLength == maxSize)
    {
        throw FullVectorException();
    }
    ++vectLength;
    for (int i = vectLength - 1; i >= 0; i--)
    {
        vect[i] = vect[i - 1];
    }
    vect[0] = elem;
}

int IntVector::popFront()
{
    if (vectLength == 0)
    {
        throw EmptyVectorException();
    }
    for (int i = 0; i < vectLength; i++)
    {
        vect[i] = vect[i + 1];
    }
    --vectLength;
}

