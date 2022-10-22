#pragma once
#include <iostream>

// Тип моделює тривалість у годинах і хвилинах
struct Time
{
	unsigned hours;
	unsigned minutes;

	Time() :hours(0), minutes(0) {} // **конструктор за замовчуванням
	Time(unsigned h, unsigned m);   // **конструктор з параметрами
	Time(unsigned t);			    // **конструктор з одним параметром перетворює ціле на Time
};

bool operator>(const Time & a, const Time & b);	// тривалості можна порівнювати
Time operator+(const Time & a, const Time & b); // тривалості можна додавати
Time operator*(const Time & t, unsigned n);     // час можна множити на число
std::ostream & operator<<(std::ostream & os, const Time & t);
