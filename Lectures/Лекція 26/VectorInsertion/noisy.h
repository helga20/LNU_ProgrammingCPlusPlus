#ifndef NOISY_H
#define NOISY_H
#include <iostream>
using std::cout;
using std::ostream;

// - - - клас для моделювання елементів контейнера
// Конструктори, деструктор, оператор присвоєння виводять на консоль
// повідомлення про свою роботу для того, щоб користувач міг
// спостерігати за процесом створення/знищення екземплярів контейнера
class Noisy
{	
	static long create, assign, copy, destroy;
	long id;
public:
	Noisy() : id(create)
	{
		cout << "default: [ "<< id << " ]\n";
		++create;	}
	Noisy(int k) : id(k)
	{
		cout << "one par: [ " << id << " ]\n";
		++create;
	}
	Noisy(int a, int b) : id(a * 100 + b)
	{
		cout << "two par: [ " << id << " ]\n";
		++create;
	}
	Noisy(const Noisy& r) : id(r.id)
	{
		cout << "   copy: [ " << id << " ]\n";
		++copy;
	}
	Noisy& operator=(const Noisy& r)
	{
		cout << " assign: ( " << id << " ) = [ " << r.id << " ]\n";
		id = r.id;
		++assign;
		return *this;
	}
	friend bool operator<(const Noisy& a, const Noisy& b)
	{
		return a.id < b.id;
	}
	friend bool operator==(const Noisy& a, const Noisy& b)
	{
		return a.id == b.id;
	}
	~Noisy()
	{
		cout << "destruct~[ " << id << " ]\n";
		++destroy;
	}
	friend ostream& operator<<(ostream& os, const Noisy& r)
	{
		return os << "Noisy_" << r.id;
	}
	friend class NoisyReport;
};

// Тип, до екземпляра якого можна звертатися як до генератора
// екземплярів класу Noisy
struct NoisyGen
{
	Noisy operator()()
	{
		return Noisy();
	}
};

// - - - Синглетний клас для автоматичного виведення статистики
class NoisyReport
{	
	static NoisyReport nr;
	NoisyReport() {}
	NoisyReport(const NoisyReport&);
	NoisyReport& operator=(NoisyReport&);
public:
	~NoisyReport()
	{	
		cout<<"\n-------------------------------------------\n"
			<<"  Noisy creations: "<<Noisy::create
			<<"\nCopy-Constructions: "<<Noisy::copy
			<<"\nAssigniments: "<<Noisy::assign
			<<"\nDestructions: "<<Noisy::destroy<<'\n';
		std::cin.get();
	}
};
#endif