#include "stepProcedures.h"
#define _USE_MATH_DEFINES   // приєднуємо визначення математичних констант,
#include <math.h>           // оголошення стандартних матеамтичних функцій
#include <iomanip>          // та маніпуляторів форматами виведення

using std::setw;
using std::setprecision;

void table()
{
	cout << "\n *Таблиця значень тригонометричних функцій на проміжку [0;Pi]*\n\n";
	const int n = 12;
	// друкуємо шапку таблиці
	cout << "  x     sin x    cos x\n------------------------\n";
	double h = M_PI / n; // крок зміни аргумента досить порахувати один раз
	for ( int i = 0; i <= n; ++i) // обчислюємо і друкуємо рядки таблиці
	{
		double x = h * i;
		double s = sin(x);
		double c = cos(x);
		cout << std::showpoint << std::fixed
			<< setw(5) << setprecision(2) << x
			<< setw(9) << setprecision(5) << s
			<< setw(9) << setprecision(5) << c << '\n';
	}
	return;
}