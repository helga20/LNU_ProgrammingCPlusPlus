#pragma once
#include "DblList.h"
#include "Array.h"

template <typename T, template <typename T> class Cont = DblList>
class Stack
{
private:
	Cont<T> mem;
public:
	bool isEmpty() const
	{
		return mem.size() == 0;
	}
	void push(const T& x)
	{
		mem.putLast(x);
	}
	T pop()
	{
		return mem.getLast();
	}
	T& peek()
	{
		return mem.back();
	}
};