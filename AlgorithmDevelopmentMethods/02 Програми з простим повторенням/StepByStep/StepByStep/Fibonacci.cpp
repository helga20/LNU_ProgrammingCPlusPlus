#include "stepProcedures.h"

void Fibonacci()
{
	cout << "\n *Побудова послідовності чисел Фібоначчі*\n\n";
	unsigned k;
	cout << "Введіть номер (>=2) останнього числа: "; cin >> k;
	k = (k > 2) ? k : 2;
	long long a;
	long long b = 1; // задали початок послідовності
	long long c = 1;
	cout << "f(0)=" << b << "\nf(1)=" << c << '\n';
	for (unsigned i = 2; i <= k; ++i)
	{
		a = b; b = c; // значення b і c "постаріли"
		c = a + b;    // обчислили новий член послідовності
		cout << "f(" << i << ")=" << c << '\n';
	}
	return;
}