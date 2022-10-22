#include "stepProcedures.h"

void succession()
{
	cout << "\n *Побудова зростаючої числової послідовності*\n\n";
	double m;
	cout << "Введіть граничне значення: "; cin >> m;
	int k = 1;
	double a = 1.0; // задали перший член послідовності
	cout << "a(" << k << ")=" << a << '\n';
	while (a <= m)
	{
		++k;
		a = a / k + 0.2 * k + 0.1; // обчислили наступний
		cout << "a(" << k << ")=" << a << '\n';
	}
	cout << "Знайдений номер = " << k << '\n';
	return;
}