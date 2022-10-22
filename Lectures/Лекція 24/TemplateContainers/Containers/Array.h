#pragma once
#include <iostream>
#include <iterator>

template <typename T>
class Array
{
private:
	size_t allocated;
	size_t used;
	T* mem;
	void reallocate()
	{
		T* newMem = new T[allocated *= 2];
		for (size_t i = 0; i < used; ++i) newMem[i] = mem[i];
		delete[] mem;
		mem = newMem;
	}
	void checkIndex(size_t i) const
	{
		if (i >= used) throw std::range_error("Bad index");
	}

public:
	typedef T ValueType;
	Array() :allocated(1), used(0), mem(new T[allocated]) {}
	explicit Array(size_t n, T x = 0) :allocated(n), used(n), mem(new T[allocated])
	{
		for (size_t i = 0; i < used; ++i) mem[i] = x;
	}
	Array(T* a, size_t n) :allocated(n), used(n), mem(new T[allocated])
	{
		for (size_t i = 0; i < used; ++i) mem[i] = a[i];
	}
	Array(const Array& A) :allocated(A.used), used(A.used), mem(new T[allocated])
	{
		for (size_t i = 0; i < used; ++i) mem[i] = A.mem[i];
	}
	~Array() { delete[] mem; }
	Array& operator=(const Array& A)
	{
		if (this != &A)
		{
			delete[] mem;
			allocated = A.allocated;
			used = A.used;
			mem = new T[allocated];
			for (size_t i = 0; i < used; ++i) mem[i] = A.mem[i];
		}
		return *this;
	}
	Array& clear()
	{
		used = 0;
		return *this;
	}
	void resize(size_t n)
	{
		if (n == allocated) return;
		allocated = n;
		T* newMem = new T[allocated];
		if (n < used) used = n;
		for (size_t i = 0; i < used; ++i) newMem[i] = mem[i];
		delete[] mem;
		mem = newMem;
	}
	size_t size() const
	{
		return used;
	}
	T& operator[](size_t i)
	{
		checkIndex(i);
		return mem[i];
	}
	const T& operator[](size_t i) const
	{
		checkIndex(i);
		return mem[i];
	}
	Array& putLast(const T& x)
	{
		if (used == allocated) reallocate();
		mem[used++] = x;
		return *this;
	}
	Array& put(const T& x, size_t i)
	{
		checkIndex(i);
		if (used == allocated) reallocate();
		for (size_t j = used; j > i; --j) mem[j] = mem[j - 1];
		mem[i] = x;
		++used;
		return *this;
	}
	T getLast()
	{
		if (used == 0) throw std::exception("Empty array");
		else return mem[--used];
	}
	T get(size_t i)
	{
		checkIndex(i);
		T x = mem[i];
		for (size_t j = i + 1; j < used; ++j) mem[j - 1] = mem[j];
		--used;
		return x;
	}
	T& front()
	{
		if (used == 0) throw std::range_error("Empty Array");
		else return mem[0];
	}
	T& back()
	{
		if (used == 0) throw std::range_error("Empty Array");
		else return mem[used - 1];
	}
	void showOn(std::ostream& os) const
	{
		if (used == 0)
		{
			os << "<Empty Array>\n";
		}
		else
		{
			for (size_t i = 0; i < used; ++i) os << '\t' << mem[i];
			os << '\n';
		}
	}
};
