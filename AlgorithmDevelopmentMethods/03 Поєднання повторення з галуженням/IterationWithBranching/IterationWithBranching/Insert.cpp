#include "iterProcedures.h"

void forwardInsert()
{
	cout << "\n *Вставка числа у впорядковану послідовність*\n"
		<< "    пошук від початку\n\n";
	const int n = 6;
	cout << "Введіть " << n - 1 << " чисел: ";
	int a[n]; int i;
	for (i = 0; i < n - 1; ++i) cin >> a[i];
	cout << "Введiть нове число: ";
	double b; cin >> b;
	// шукаємо місце для b
	i = 0;
	while (a[i] < b && i < n - 1) ++i;
	//посуваємо «хвіст»
	for (int j = n - 2; j >= i; --j) a[j + 1] = a[j];
	a[i] = b; // вставляємо b в масив
	for (i = 0; i < n; ++i) cout << a[i] << ' ';
	cout << '\n';
	return;
}

void simpleInsert()
{
	cout << "\n *Вставка числа у впорядковану послідовність*\n"
		<< "    пошук від кінця\n\n";
	const int n = 6;
	cout << "Введіть " << n - 1 << " чисел: ";
	int a[n]; int i;
	for (i = 0; i < n - 1; ++i) cin >> a[i];
	cout << "Введiть нове число: ";
	double b; cin >> b;
	// шукаємо місце для b і посуваємо «хвіст»
	i = n - 2;
	while (a[i] > b && i >= 0)
	{
		a[i + 1] = a[i];
		--i;
	}
	a[i + 1] = b; // вставляємо b в масив
	for (i = 0; i < n; ++i) cout << a[i] << ' ';
	cout << '\n';
	return;
}

void binaryInsert()
{
	cout << "\n *Вставка числа у впорядковану послідовність*\n"
		<< "    двійковий пошук\n\n";
	const int n = 6;
	cout << "Введіть " << n - 1 << " чисел: ";
	int a[n]; int i;
	for (i = 0; i < n - 1; ++i) cin >> a[i];
	cout << "Введiть нове число: ";
	double b; cin >> b;
	// початкові межі пошуку
	int p = 0; int q = n - 1;
	while (p != q)
	{
		int s = (p + q) / 2; // шукаємо середній елемент
		if (a[s] < b) p = s + 1; else q = s; //і порівнюємо з ним
	}
	//посуваємо «хвіст»
	for (int j = n - 2; j >= p; --j) a[j + 1] = a[j];
	a[p] = b; // вставляємо b в масив
	for (i = 0; i < n; ++i) cout << a[i] << ' ';
	cout << '\n';
	return;
}