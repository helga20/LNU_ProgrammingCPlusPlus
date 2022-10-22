#include "Functions.h"

// Поелементне введення масиву з потоку
void ReadArrayFromStream(num_type* a, size_t n, std::istream& is)
{
	for (size_t i = 0; i < n; ++i) is >> a[i];
}
// Обчислення скалярного добутку векторів
num_type ScalarProduct(const num_type* a, const num_type* b, size_t n)
{
	num_type s = 0;
	for (size_t i = 0; i < n; ++i) s += a[i] * b[i];
	return s;
}
// Виведення масиву на консоль
void WriteArray(num_type* a, size_t n)
{
	for (size_t i = 0; i < n; ++i) std::cout << '\t' << a[i];
	std::cout << '\n';
}

// Побудова таблиці значень функції
void TabulateToStream(std::ostream& os, func f, double a, double b, double h)
{
	unsigned n = round((b - a) / h);
	// виведення шапки таблиці
	os << "\t x\t|\t f(x)\n    ---------------------------------\n";
	// обчислення і виведення тіла таблиці
	for (unsigned i = 0; i <= n; ++i)
	{
		double x = a + i*h;
		(os << '\t').precision(4);
		(os << x << "\t|\t").precision(8);
		os << f(x) << '\n';
	}
	os << '\n';
}
