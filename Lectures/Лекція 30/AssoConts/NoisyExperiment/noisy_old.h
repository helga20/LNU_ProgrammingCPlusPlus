#ifndef NOISY_H
#define NOISY_H
#include <iostream>
using std::cout;
using std::ostream;
// - - - клас для моделювання елементів контейнера
class Noisy
{	static long create, assign, copy, destroy;
	long id;
public:
	Noisy() : id(create)
	{	cout<<"d["<<id<<"]\n";
		++create;	}
	Noisy(const Noisy& r) : id(r.id)
	{	cout<<"c["<<id<<"]\n";
		++copy;	}
	Noisy& operator=(const Noisy& r)
	{	cout<<'('<<id<<")=["<<r.id<<"]\n";
		id=r.id; ++assign; return *this;	}
	friend bool operator<(const Noisy& a, const Noisy& b)
	{	return a.id<b.id;	}
	friend bool operator==(const Noisy& a, const Noisy& b)
	{	return a.id==b.id;	}
	~Noisy()
	{	cout<<"~["<<id<<"]\n"; ++destroy;	}
	friend ostream& operator<<(ostream& os, const Noisy& r)
	{	return os<<r.id;	}
	friend class NoisyReport;
};
struct NoisyGen
{
	Noisy operator()() { return Noisy(); }
};
// - - - Синглетний клас для автоматичного виведення статистики
class NoisyReport
{	static NoisyReport nr;
	NoisyReport(){}
	NoisyReport(const NoisyReport&);
	NoisyReport& operator=(NoisyReport&);
public:
	~NoisyReport()
	{	cout<<"\n-------------------------------------------\n"
			<<"  Noisy creations: "<<Noisy::create
			<<"\nCopy-Constructions: "<<Noisy::copy
			<<"\nAssigniments: "<<Noisy::assign
			<<"\nDestructions: "<<Noisy::destroy<<'\n';	}
};
#endif