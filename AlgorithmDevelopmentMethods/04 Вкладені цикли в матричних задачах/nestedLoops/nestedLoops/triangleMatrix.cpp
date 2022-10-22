#include "loopsProcedures.h"

void triangleMatrix()
{
	cout << "\n *Побудова трикутної матриці заданого розміру*\n\n"
		<<"Введіть розмір матриці: ";
	unsigned n; cin >> n;
	// виділення пам'яті для динамічної матриці
	int ** a = createMatrix(n);
	// заповнення матриці значеннями:
	int n1 = n - 1;
	//   побічна діагональ
	for (int i = 0; i < n; ++i) a[i][n1 - i] = n;
	//   верхній трикутник
	for (int i = 0; i < n1; ++i)
		for (int j = 0; j < n1 - i; ++j)
			a[i][j] = i + j + 1;
	//   нижній трикутник
	for (int i = 1; i < n; ++i)
		for (int j = n - i; j < n; ++j)
			a[i][j] = 0;
	// виведення результатів
	printMatrix(a, n);
	eraseMatrix(a);
	return;
}