#include "loopsProcedures.h"

void saddleElement()
{
	cout << "\n *Відшукання сідлового елемента матриці*\n\n";
	// Для спрощення розміри матриці задамо в коді програми
	const unsigned n = 3;
	const unsigned m = 4;
	int a[n][m];
	// Введення заданої матриці
	cout << "Введіть елементи матриці " << n << 'x' << m << '\n';
	for (unsigned i = 0; i < n; ++i)
		for (unsigned j = 0; j < m; ++j) cin >> a[i][j];
	// початковим значенням сідлового елемента є максимальний елемент
	// першого рядка матриці - знайдемо його!
	int saddle = a[0][0]; // початкове значення максимального
	unsigned k = 0;		  // та його координати
	unsigned l = 0;
	// тепер - пошук в рядку
	for (unsigned j = 1; j < m; ++j)
		if (a[k][j] > saddle)  // знайшли більше
		{
			saddle = a[k][j]; // і запам'ятали
			l = j;
		}
	// тепер переглянемо всі інші рядки матриці
	for (unsigned i = 1; i < n; ++i)
	{
		// і знайдемо їхні максимальні елементи
		int currMax = a[i][0];
		unsigned p = 0;
		for (unsigned j = 1; j < m; ++j)
			if (a[i][j] > currMax)
			{
				currMax = a[i][j];
				p = j;
			}
		// та порівняємо їх з поточним значенням сідлового елемента
		if (currMax < saddle)
		{
			saddle = currMax;
			k = i; l = p;
		}
	}
	cout << "Сідловим є елемент a[" << k << "][" << l << "] = " << saddle << '\n';
	return;
}