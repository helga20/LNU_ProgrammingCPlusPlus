#pragma once
#include <iostream>
#include <stdexcept>
using std::ostream;

// Клас ArrayDb перетворено на шаблон. Тепер він може зберігати значення довільних типів,
// для яких має сенс обчислення середнього арифметичного. Клас доповнено ітератором
template <typename T>
class Array
{
private:
	unsigned int size;
	T* arr;
public:
	class Iter
	{
	private:
		T * ptr;
	public:
		Iter(T* p = nullptr) :ptr(p){}
		T& operator*() { return *ptr; }
		Iter& operator++()
		{
			++ptr; return *this;
		}
		bool operator!=(const Iter& it) const
		{
			return this->ptr != it.ptr;
		}
 	};

	Array() : arr(0), size(0) {}
	explicit Array(unsigned int n, T val = T());
	Array(const T* pn, unsigned int n);
	Array(const Array& a);
	virtual ~Array() { delete[] arr; }
	unsigned int arSize() const { return size; }
	T average() const
	{
		T sum = T();
		for (size_t i = 0; i < size; i++) sum += arr[i];
		return sum / size;
	}
	T& operator[](int i)
	{
		if (i<0 || i >= size) throw std::out_of_range("Array: index out of range");
		return arr[i];
	}
	const T& operator[](int i) const
	{
		if (i<0 || i >= size) throw std::out_of_range("Array: index out of range");
		return arr[i];
	}
	Array& operator=(const Array& a);
	Iter begin() { return Iter(arr); }
	Iter end() { return Iter(arr + size); }

	template <typename T>
	friend ostream& operator<<(ostream& os, const Array<T>& a);
};

template <typename T> Array<T>::Array(unsigned int n, T val)
{
	arr = new T[n];
	size = n;
	for (size_t i = 0; i<n; i++) arr[i] = val;
}
template <typename T> Array<T>::Array(const T* pn, unsigned int n)
{
	arr = new T[n];
	size = n;
	for (size_t i = 0; i<n; i++) arr[i] = pn[i];
}
template <typename T> Array<T>::Array(const Array<T>& a)
{
	size = a.size;
	arr = new T[size];
	for (size_t i = 0; i<size; i++) arr[i] = a.arr[i];
}
template <typename T> Array<T>& Array<T>::operator=(const Array<T>& a)
{
	if (this == &a) return *this;
	delete[] arr;
	size = a.size;
	arr = new T[size];
	for (size_t i = 0; i<size; i++) arr[i] = a.arr[i];
	return *this;
}

template <typename T>
ostream& operator<<(ostream& os, const Array<T>& a)
{
	for (size_t i = 0; i<a.size; i++)
	{
		os.width(8); os << a.arr[i];
	}
	if (a.size % 10 != 0) os << '\n';
	return os;
}