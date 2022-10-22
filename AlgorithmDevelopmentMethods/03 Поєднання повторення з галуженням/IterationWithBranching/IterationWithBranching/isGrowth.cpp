#include "iterProcedures.h"

void isGrowth()
{
	cout << "\n *Перевірка, чи впорядкована послідовність*\n\n";
	const int n = 5;
	cout << "Введіть " << n << " чисел: ";
	int a[n]; int i;
	for (i = 0; i < n; ++i) cin >> a[i];
	// перевірка
	i = 1;
	while (a[i-1] < a[i] && i < n) ++i;
	if (i == n) cout << "Послідовність зростаюча\n";
	else cout << "Умову впорядкованості порушено перед а[" << i << "]\n";
	return;
}