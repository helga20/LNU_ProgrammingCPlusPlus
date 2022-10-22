#include "Functions.h"

// ����������� �������� ������ � ������
void ReadArrayFromStream(num_type* a, size_t n, std::istream& is)
{
	for (size_t i = 0; i < n; ++i) is >> a[i];
}
// ���������� ���������� ������� �������
num_type ScalarProduct(const num_type* a, const num_type* b, size_t n)
{
	num_type s = 0;
	for (size_t i = 0; i < n; ++i) s += a[i] * b[i];
	return s;
}
// ��������� ������ �� �������
void WriteArray(num_type* a, size_t n)
{
	for (size_t i = 0; i < n; ++i) std::cout << '\t' << a[i];
	std::cout << '\n';
}

// �������� ������� ������� �������
void TabulateToStream(std::ostream& os, func f, double a, double b, double h)
{
	unsigned n = round((b - a) / h);
	// ��������� ����� �������
	os << "\t x\t|\t f(x)\n    ---------------------------------\n";
	// ���������� � ��������� ��� �������
	for (unsigned i = 0; i <= n; ++i)
	{
		double x = a + i*h;
		(os << '\t').precision(4);
		(os << x << "\t|\t").precision(8);
		os << f(x) << '\n';
	}
	os << '\n';
}
