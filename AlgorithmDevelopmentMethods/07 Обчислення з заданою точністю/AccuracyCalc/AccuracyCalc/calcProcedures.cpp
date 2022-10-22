#include "calcProcedures.h"

double dychotom(func f, double a, double b, double eps)
// Ітеративна реалізація методу дихотомії
{
	double fa = f(a);
	while (b - a > eps)
	{
		double c = (a + b)*0.5; // середина проміжку
		double fc = f(c);
		if (fa*fc < 0) b = c;   // корінь – у лівій половині проміжку
		else                    // корінь – праворуч
		{
			a = c; fa = fc;
		}
	}
	return (a + b)*0.5;
}

double dychotomRec(func f, double a, double b, double eps)
// Рекурсивна реалізація методу дихотомії
{
	double c = (a + b)*0.5;
	if (b - a <= eps)     // проміжок достатньо малий
		return c;
	if (f(a)*f(c) < 0)    // шукати корінь на лівій половині
		return dychotomRec(f, a, c, eps);
	else                  // шукати корінь на правій половині
		return dychotomRec(f, c, b, eps);
}

double leftRect(double a, double b, func f, double eps)
// інтеграл від f на проміжку [a;b] методом лівих прямокутників
// p - значення I(2n); q - значення I(n); s - використовується
// для постійного накопичення суми значень f(i)
// дозволено не більше 12 подвоєнь сітки інтегрування
{
	int n = 10;
	double h = (b - a) / n;
	double s = 0.;
	for (int i = 0; i < n; ++i) s += f(a + i*h);
	double p = s*h;  // перше значення інтеграла
	double q = 0.;   // наступне значення
	int k = 0;       // кількість подвоєнь вузлів інтегрування
	while (abs(p - q) / 3.>eps && k < 13)
	{
		++k; q = p;            // запам’ятали попереднє I(n)
		double h2 = h * 0.5;
		double a2 = a + h2;
		for (int i = 0; i < n; ++i)
			s += f(a2 + i*h);  // доповнили суму
		p = s * h2;            // отримали нове значення I(2n)
		h = h2; n += n;        // подвоїли кількість доданків
	}
	if (k > 12) cout << "leftRec::WARNING: Accuracy loss is possible\n";
	return p;
}