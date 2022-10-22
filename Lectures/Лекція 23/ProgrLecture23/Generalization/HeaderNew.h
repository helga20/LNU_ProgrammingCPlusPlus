#pragma once
#include "HeaderOld.h"

void PrintMas(ValueType*, ValueType*);
ValueType* FindValInMas(ValueType, ValueType*, ValueType*);

// спеціальний клас-адаптер для зручного доступу до списку
class Iter
{
private:
	Node* L;
public:
	Iter(Node*ptr = nullptr) :L(ptr){}
	ValueType& operator*()
	{
		return L->data;
	}
	Iter& operator++()
	{
		L = L->next;
		return *this;
	}
	bool operator!=(const Iter& it)
	{
		return this->L != it.L;
	}
};
void PrintList(Node*, Node*);
Iter FindValInList(ValueType, Iter, Iter);