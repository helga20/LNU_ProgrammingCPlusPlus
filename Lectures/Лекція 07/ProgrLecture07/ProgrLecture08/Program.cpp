/* Задано натуральне n і n-вимірні вектори a, b, c. Обчислити
     / (a, c), якщо ||a||^2 > 5
U = <
     \ (b, c), в іншому випадку
*/
#include <iostream>
#include "ArrProcedures.h"

int main()
{
	using std::cin;
	using std::cout;
	// Розв'яжемо задачу за допомогою статичних масивів при n=10
	Array A, B, C;
	cout << " Vector a\n"; ReadArray(A);
	cout << " Vector b\n"; ReadArray(B);
	cout << " Vector c\n"; ReadArray(C);
	num_type u;
	if (ScalarProduct(A, A) > 5)
		u = ScalarProduct(A, C);
	else
		u = ScalarProduct(B, C);
	cout << "U = " << u << '\n';
	cin.get();

	// А тепер використаємо динамічні масиви
	cout << "Input size of arrays: ";
	size_t n; cin >> n;
	// Створити динамічні масиви і ввести їх
	num_type* a = CreateArray(n);
	num_type* b = CreateArray(n);
	num_type* c = CreateArray(n);
	cout << " Vector a\n"; ReadArray(a, n);
	cout << " Vector b\n"; ReadArray(b, n);
	cout << " Vector c\n"; ReadArray(c, n);
	// Обчислення
	num_type U = (ScalarProduct(a, a, n) > 5) ? ScalarProduct(a, c, n) : ScalarProduct(b, c, n);
	cout << " U = " << U << '\n';
	cin.get();
	// Звільнення пам'яті
	delete[] a;
	delete[] b;
	delete[] c;

	// Експеримент з відшуканням максимального
	double d[] = { 1, -2, 0, 5, 7, 3, 6, -4, 2, 5 };
	size_t k = sizeof d / sizeof d[0];
	cout << "max value is " << maxVal(d, k) << '\n';
	cout << "max value is " << maxVal(d, d + k) << '\n';
	double* ptr = max(d, d + k);
	cout << "max value is " << *ptr << " at index " << ptr - d << '\n';
	if (maxVal(d, k / 2) > maxVal(&d[k / 2], k - k / 2))
		cout << "Max is situated at the first half of the array\n";
	else
		cout << "Max is situated at the second half of the array\n";
	cin.get();
	return 0;
}