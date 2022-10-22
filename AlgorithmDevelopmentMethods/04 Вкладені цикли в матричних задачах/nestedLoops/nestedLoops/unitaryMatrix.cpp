#include "loopsProcedures.h"

void unitaryMatrix()
{
	cout << "\n *Побудова одиничної матриці заданого розміру (з перевірками)*\n\n"
		<<"Введіть розмір матриці: ";
	unsigned n; cin >> n;
	// виділення пам'яті для динамічної матриці
	int ** a = createMatrix(n);
	// заповнення матриці значеннями
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			a[i][j] = (i == j) ? 1 : 0;
	// виведення результатів
	printMatrix(a, n);
	eraseMatrix(a);
	return;
}

void symmetricBuildMatrix()
{
	cout << "\n *Побудова одиничної матриці заданого розміру (за структурою)*\n\n"
		<<"Введіть розмір матриці: ";
	unsigned n; cin >> n;
	// виділення пам'яті для динамічної матриці
	int ** a = createMatrix(n);
	// заповнення матриці значеннями:
	//   головна діагональ
	for (int i = 0; i < n; ++i) a[i][i] = 1;
	//   трикутники над і під діагоналлю
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
			a[i][j] = a[j][i] = 0;
	// виведення результатів
	printMatrix(a, n);
	eraseMatrix(a);
	return;
}