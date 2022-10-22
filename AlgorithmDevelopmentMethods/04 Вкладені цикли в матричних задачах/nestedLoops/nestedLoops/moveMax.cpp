#include "loopsProcedures.h"
#include <cmath>

void moveMax()
{
	cout << "\n *Переміщення max-елемента переставлянням рядків і стовпців матриці*\n\n";
	// Для спрощення розміри матриці задамо в коді програми
	const unsigned n = 3;
	const unsigned m = 4;
	int a[n][m];
	// Введення заданої матриці
	cout << "Введіть елементи матриці " << n << 'x' << m << '\n';
	for (unsigned i = 0; i < n; ++i)
		for (unsigned j = 0; j < m; ++j) cin >> a[i][j];
	int b = abs(a[0][0]); // початкове значення максимального
	unsigned k = 0;		  // та його координати
	unsigned l = 0;
	// тепер - пошук в матриці
	for (unsigned i = 0; i < n; ++i)
	{
		for (unsigned j = 0; j < m; ++j)
			if (abs(a[i][j]) > b)  // знайшли більше
			{
				b = abs(a[i][j]); // і запам'ятали
				k = i; l = j;
			}
	}
	if (k != 0) // міняємо місцями рядки
		for (unsigned j = 0; j < m; ++j)
		{
			int toSwap = a[0][j];
			a[0][j] = a[k][j];
			a[k][j] = toSwap;
		}
	if (l != 0) // міняємо місцями стовпці
		for (unsigned i = 0; i < n; ++i)
		{
			int toSwap = a[i][0];
			a[i][0] = a[i][l];
			a[i][l] = toSwap;
		}
	// Друкуємо результати
	for (unsigned i = 0; i < n; ++i)
	{
		for (unsigned j = 0; j < m; ++j) cout << '\t' << a[i][j];
		cout << '\n';
	}
	return;
}