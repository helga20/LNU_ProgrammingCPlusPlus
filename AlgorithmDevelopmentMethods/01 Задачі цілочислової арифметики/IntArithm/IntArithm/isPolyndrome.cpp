#include "intProcedures.h"

void isPolyndrome()
{
	cout << "\n *Перевірка: чи паліндром?*\n\nВведіть натуральне число: ";
	unsigned n; cin >> n;
	// початкове значення нового числа та копія n
	unsigned s = 0; unsigned m = n;
	// перебираємо цифри введеного числа
	while (m > 0)
	{
		unsigned c = m % 10; // отримали наймолодшу цифру
		s = s*10 + c;        // врахували її
		m /= 10;             // і вилучили її
	}
	if (s == n) cout << n << "- паліндром\n";
	else cout << n << "- не паліндром\n";
	return;
}