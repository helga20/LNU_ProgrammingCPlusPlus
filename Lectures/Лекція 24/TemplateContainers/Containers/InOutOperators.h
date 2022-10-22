#pragma once
#include <iostream>

template <typename T, template <typename Y> class Cont>
std::ostream& operator<<(std::ostream& os, const Cont<T>& C)
{
	C.showOn(os);
	return os;
}
template <typename T, template <typename Y> class Cont>
std::istream& operator>>(std::istream& is, Cont<T>& C)
{
	size_t n;
	is >> n;
	C.clear().resize(n);
	for (size_t i = 0; i < n; ++i)
	{
		typename Cont<T>::ValueType x;
		is >> x;
		C.putLast(x);
	}
	return is;
}
// copy, accumulate, transform, for_each, find