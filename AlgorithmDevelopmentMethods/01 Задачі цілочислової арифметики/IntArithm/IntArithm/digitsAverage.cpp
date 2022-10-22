#include "intProcedures.h"

void digitsAverage()
{
	cout << "\n *Обчислення середнього арифметичного цифр*\n\nВведіть натуральне число: ";
	unsigned n, m; cin >> n; m = n;
	// початкові значення суми та лічильника
	unsigned s = 0; unsigned k = 0;
	// перебираємо цифри введеного числа
	while (m > 0)
	{
		unsigned c = m % 10; // отримали наймолодшу цифру
		s += c; ++k;         // врахували її
		m /= 10;             // вилучили її
	}
	// обчислили середнє арифметичне і видрукували його
	double average = s; average /= k;
	cout << "n = " << n << "   average = " << average << '\n';
	return;
}