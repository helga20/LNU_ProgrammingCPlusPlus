#ifndef _SIMPLEGENERS_H
#define _SIMPLEGENERS_H

#include <iostream>
#include <utility>

template<typename T> class IncrGen
{
	T i;
public:
	IncrGen(T ii) : i(ii) {}
	T operator()() { return i++; }
};

template<typename T1, typename T2>
class PairGen
{
	T1 i; T2 j;
public:
	PairGen(T1 ii, T2 jj) : i(ii), j(jj) {}
	std::pair<T1,T2> operator()()
	{
		return std::pair<T1,T2>(i++,j++);
	}
};
namespace std
{
	template<typename F, typename S>
	ostream& operator<<(ostream& os, const pair<F,S>& p)
	{
		return os << p.first << " : " << p.second << '\n';
	}
}

#endif