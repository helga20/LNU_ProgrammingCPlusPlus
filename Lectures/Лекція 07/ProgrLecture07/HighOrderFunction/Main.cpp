#define _USE_MATH_DEFINES
#include <iostream>
#include "Functions.h"

double parabola(double);

int main()
{
	// табулювання стандартної функції
	std::cout << "\t\t\tTable 1. Sin(x)\n";
	Tabulate(sin, 0.0, M_PI_2, M_PI_2 / 12);
	std::cin.get();
	// табулювання власної функції
	std::cout << "\t\t\tTable 2. x^2+2x-3\n";
	Tabulate(parabola, -4.0, 2.5, 0.25);
	std::cin.get();
	// функцію задано лямбда-виразом
	std::cout << "\t\t\tTable 3. Sqrt(1-x^2)\n";
	Tabulate([](double x){return sqrt(1. - x*x); }, -1.0, 1.0, 0.1);
	std::cin.get();
	// Обчислення коренів квадратного рівняння
	double x1 = bisection(parabola, -3.2, -2.9);
	double x2 = bisection(parabola, 0.2, 1.3);
	std::cout << "x1 = " << x1 << "    x2 = " << x2 << '\n';
	system("pause");
	func f = cos;
	func g = &cos;
	std::cout << f(M_PI) << '\t' << g(M_PI) << "\n\n";
	system("pause");
	// Моделювання роботи меню
	proc menu[4] = { CalculateRoots, Integrate, DeelWithArray, [](){ std::cout << "Bye!\n"; } };
	unsigned k = 0;
	do
	{
		std::cout << "Input your choice:\n0 - CalculateRoots\n1 - Integrate\n2 - DeelWithArray\n3 - Exit\n >> ";
		std::cin >> k; k %= 4;
		menu[k]();
	} while (k != 3);
	system("pause");
	return 0;
}

double parabola(double x)
{
	return (x + 2.) * x - 3.;
}