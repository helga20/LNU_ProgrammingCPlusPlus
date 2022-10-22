#include <iostream>
#include "Functions.h"

// Побудова таблиці значень функції
void Tabulate(func f, double a, double b, double h)
{
	unsigned n = round((b - a) / h);
	// друк шапки таблиці
	std::cout << "\t x\t|\t f(x)\n    ---------------------------------\n";
	// обчислення і друк тіла таблиці
	for (unsigned i = 0; i <= n; ++i)
	{
		double x = a + i*h;
		(std::cout << '\t').precision(4);
		(std::cout << x << "\t|\t").precision(8);
		std::cout << f(x) << '\n';
	}
	std::cout << '\n';
}

// Рекурсивна реалізація методу поділу відрізка навпіл
double bisection(func f, double a, double b, double eps)
{
	double c = (a + b)*0.5;
	if (b - a <= eps)     // проміжок достатньо малий
		return c;
	if (f(a)*f(c) < 0)    // шукати корінь на лівій половині проміжка
		return bisection(f, a, c, eps);
	else                  // шукати корінь на правій половині проміжка
		return bisection(f, c, b, eps);
}

// Процедури, що виконують окремі "розділи" великої програми
void CalculateRoots()
{
	std::cout << "The roots are calculated successfully!\n\n";
}
void Integrate()
{
	std::cout << "Integrate...\n Integrate...\n  Integrated!\n\n";
}
void DeelWithArray()
{
	std::cout << "Read array A\nRead array B\nCalculate F(A,B)\n\n";
}