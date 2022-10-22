#pragma once
#include <functional>
#include <iostream>

// Комплект шаблонів, що спрощують виконання дій з множинами
template <class T, class CMP = std::less<T>, class ALLOC = std::allocator<T> >
std::set<T, CMP, ALLOC> operator * (
	const std::set<T, CMP, ALLOC> &s1, const std::set<T, CMP, ALLOC> &s2)
{
	std::set<T, CMP, ALLOC> s;
	std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
		std::inserter(s, s.begin()));
	return s;
}

template <class T, class CMP = std::less<T>, class ALLOC = std::allocator<T> >
std::set<T, CMP, ALLOC> operator + (
	const std::set<T, CMP, ALLOC> &s1, const std::set<T, CMP, ALLOC> &s2)
{
	std::set<T, CMP, ALLOC> s;
	std::set_union(s1.begin(), s1.end(), s2.begin(), s2.end(),
		std::inserter(s, s.begin()));
	return s;
}

template <class T, class CMP = std::less<T>, class ALLOC = std::allocator<T> >
std::set<T, CMP, ALLOC> operator - (
	const std::set<T, CMP, ALLOC> &s1, const std::set<T, CMP, ALLOC> &s2)
{
	std::set<T, CMP, ALLOC> s;
	std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(),
		std::inserter(s, s.begin()));
	return s;
}

template <class T, class CMP = std::less<T>, class ALLOC = std::allocator<T> >
std::ostream& operator<< (
	std::ostream &os, const std::set<T, CMP, ALLOC> &s)
{
	std::copy(s.begin(), s.end(), std::ostream_iterator<T>(os, " "));
	return os;
}
