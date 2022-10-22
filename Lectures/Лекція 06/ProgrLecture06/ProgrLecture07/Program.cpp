#include <iostream>
#include <cmath>
#include "Functions.h"

int main()
{
	using std::cin;
	using std::cout;
	// експеримент з посиланнями
	int var = 5;
	int& ref = var;
	int*const ptr = &var;
	cout << "Experiment with var, ref & pointer\n";
	cout << "  var : " << var << "   " << &var
		<< "\n  ref : " << ref << "   " << &ref 
		<< "\n  ptr : " << *ptr << "   " << ptr << "   " << &ptr << '\n';
	cin.get();
	/* ЗАДАЧА. Задано дійсне x. Обчислити значення
	   y = x^1/5 + (sin^2(x)-x)^1/5.
	   (тут x^1/5 означає корінь п'ятого степеня з x)*/
	cout << "Input x: ";
	double x;  (cin >> x).get();
	double y = ptrt(x) + ptrt(pow(sin(x), 2) - x);
	cout << " x = " << x << " y = " << y << '\n';
	cin.get();
	// Випробуємо альтернативну реалізацію
	cout << "  ptrt(32) = " << Ptrt(32)
		<< "\n  ptrt(-1) = " << Ptrt(-1)
		<< "\n  ptrt(243.5) = " << Ptrt(243.5) << '\n';
	y = Ptrt(x) + Ptrt(pow(sin(x), 2) - x);
	cout << " x = " << x << " y = " << y << '\n';
	cin.get();

	/* Тепер випробуємо різні способи передавання параметрів*/
	int t = 3;
	int s = -7;
	cout << "\n===== Main program pass t = " << t << " and s = " << s << " by value\n";
	swapV(t, s);
	cout << "=====       after swap: t = " << t << " and s = " << s << '\n';
	cout << "\n===== Main program pass t = " << t << " and s = " << s << " by pointer\n";
	swapP(&t, &s);
	cout << "=====       after swap: t = " << t << " and s = " << s << '\n';
	cout << "\n===== Main program pass t = " << t << " and s = " << s << " by reference\n";
	swapR(t, s);
	cout << "=====       after swap: t = " << t << " and s = " << s << '\n';
	cin.get();

	// Розв'язування квадратного рівняння x^2 + 18x - 63 = 0
	double x1, x2;
	bool success;
	solve(1., 18., -63., success, x1, x2);
	if (success)
		cout << "x1 = " << x1 << "   x2 = " << x2 << '\n';
	else
		cout << "Roots could not be found\n";
	sqRoots result = Solve(1., 18., -63.);
	if (result.success)
		cout << "x1 = " << result.x1 << "   x2 = " << result.x2 << '\n';
	else
		cout << "Roots could not be found\n";
	cin.get();
	return 0;
}