// Відомо, що Р(х) = х^3 + 2.7 x^2 - 13.5 x +9.75
// Потрібно обчислити Р(2.31)

#include <iostream>
#include <complex>
using std::cin;
using std::cout;
typedef std::complex<double> Complex;

#include "Header.h"
// явне створення екземпляра шаблона функції
template int Value<int>(int x, int a[], int n);

// Продемонструємо різні способи розв'язання поставленої задачі
// з різними рівнями загальності
int main()
{
	// 1. Дуже конкретний розв'язок
	cout << "P(2.31) = " << ((2.31 + 2.7)*2.31 - 13.5)*2.31 + 9.75 << '\n';
	system("pause");
	// 2. Узагальнення для довільного значення x
	double x;
	cout << "Input x: ";
	cin >> x;
	cout << "P(" << x << ") = " << ((x + 2.7)*x - 13.5)*x + 9.75 << '\n';
	system("pause");
	// 3. Узагальнення для довільних коефіцієнтів
	double a[] = { 1, 2.7, -13.5, 9.75 };
	const int n = sizeof a / sizeof *a;
	double P = a[0];
	for (int i = 1; i < n; ++i) P = P * x + a[i];
	cout << " - Calculation for the array of coefficients\n";
	cout << "P(" << x << ") = " << P << '\n';
	system("pause");
	// 4. Узагальнення до окремого алгоритму
	cout << " - Calculation by the function\n";
	cout << "P(" << x << ") = " << value(x, a, n) << '\n';
	cout << "P(" << x-1 << ") = " << value(x-1, a, n) << '\n';
	system("pause");
	// 5. Узагальнення типу коефіцієнтів
	int b[] = { 1, 3, -14, 10 };
	const int m = sizeof b / sizeof *b;
	Complex c[] = { Complex(1.5,0.5),Complex(2.0,-1.5),Complex(-4.0,0.0) };
	const int k = sizeof c / sizeof *c;
	Complex z(1, 0);
	cout << " - Calculation by the template of function\n";
	cout << "P(" << x << ") = " << Value<double>(x, a, n) << '\n';
	cout << "P(" << x - 1 << ") = " << Value(x - 1, a, n) << '\n';
	cout << "Q(" << 2 << ") = " << Value<int>(2, b, m) << '\n';
	cout << "Q(" << 1 << ") = " << Value(1, b, m) << '\n';
	cout << "R(" << z << ") = " << Value(z, c, k) << '\n';
	system("pause");
	// друкування поліномів
	Print(a, n);
	Print(b, m);
	Print(c, k);
	system("pause");
	return 0;
}