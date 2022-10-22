#define _USE_MATH_DEFINES
#include "Functions.h"
#include <fstream>
using namespace std;

int main()
{
	cout << " Array section\n--------------------------------------------------\n";
	ifstream fin("data.txt");
	if (fin.is_open())
	{
		// �������� � ����� ����� ������
		size_t n; fin >> n;
		num_type * a = new num_type[n];
		num_type * b = new num_type[n];
		num_type * c = new num_type[n];
		// ����������� � ����� ������
		ReadArrayFromStream(a, n, fin);
		ReadArrayFromStream(b, n, fin);
		ReadArrayFromStream(c, n, fin);
		// �������� ��������� - ���� ����� �������
		fin.close();
		// ��� �������� �������� ������ �� �������
		WriteArray(a, n);
		WriteArray(b, n);
		WriteArray(c, n);
		// ���������� �� ������ ������
		num_type U = (ScalarProduct(a, a, n) > 5) ?
			ScalarProduct(a, c, n) : ScalarProduct(b, c, n);
		cout << " U = " << U << '\n';
		// ��������� ���'��
		delete[] a; delete[] b; delete[] c;
	}
	else cout << "The file 'data.txt' not found\n";
	cin.get();

	cout << " Function section\n--------------------------------------------------\n";
	// ���� ��� ��������� ����������� �������
	ofstream fout("tables.txt");

	// ����������� ���������� ������� �� �������
	cout << "\t\tTable 1. Sin(x)\n";
	TabulateToStream(cout, sin, 0.0, M_PI_2, M_PI_2 / 12);
	cin.get();
	// � ����� - �� �����
	fout << "\t\tTable 1. Sin(x)\n";
	TabulateToStream(fout, sin, 0.0, M_PI_2, M_PI_2 / 12);
	system("pause");
	// ����������� ������ ������� �� �������
	cout << "\t\tTable 2. x^2+2x-3\n";
	TabulateToStream(cout, [](double x) { return (x + 2.) * x - 3.; }, -4.0, 2.5, 0.25);
	cin.get();
	// � ����� - �� �����
	fout << "\t\tTable 2. x^2+2x-3\n";
	TabulateToStream(fout, [](double x) { return (x + 2.) * x - 3.; }, -4.0, 2.5, 0.25);

	// ������ ������ ����� ���������
	fout.close();
	system("pause");
	return 0;
}