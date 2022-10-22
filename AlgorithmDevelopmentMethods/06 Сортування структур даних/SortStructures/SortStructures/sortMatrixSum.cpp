#include "dataProcedures.h"
#include <cmath>

void sortMatrixSum()
{
	cout << "\n *Сортування рядків матриці за зростанням сум модулів*\n\n";
	// Для спрощення розміри матриці задамо в коді програми
	int a[n][m];
	// Вводимо задану матрицю
	readMatrix(a);
	// ФОРМУВАННЯ МАСИВУ КЛЮЧІВ
	int key[n] = {0};
	for (unsigned i = 0; i < n; ++i)
		for (unsigned j = 0; j < m; ++j) key[i] += abs(a[i][j]);
	// ВПОРЯДКУВАННЯ МАСИВУ КЛЮЧІВ & РЯДКІВ МАТРИЦІ
	for (unsigned j = n; j > 1; --j)
	{
		// знаходимо найбільший елемент невпорядкованої частини
		unsigned k = 0;                  // початковий номер ключа
		for (unsigned i = 1; i < j; ++i) // перевіряємо всі решту
			if (key[i] > key[k]) k = i;
		if (k != j)
		{
			// міняємо місцями ключі і рядки: j-й з k-им
			int toSwap = key[j - 1];
			key[j - 1] = key[k];
			key[k] = toSwap;
			exchange(a[j - 1], a[k], m);
		}
	}
	// Друкуємо результати
	cout << "\nКлючі:\n";
	for (unsigned i = 0; i < n; ++i) cout << '\t' << key[i];
	cout << "\n\nМатриця:\n";
	printMatrix(a);
	return;
}