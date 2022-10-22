#include "iterProcedures.h"

void exchange()
{
	cout << "\n *ќбм≥н першого з найб≥льшим*\n\n";
	const int n = 5;
	cout << "¬вед≥ть " << n << " чисел: ";
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	// пошук найб≥льшого
	double b = a[0];
	int k = 0;
	for (int i = 1; i < n; ++i)
	{
		if (a[i] > b)
		{
			b = a[i]; k = i;
		}
	}
	// переставл€нн€ елемент≥в
	a[k] = a[0]; a[0] = b;
	cout << "«м≥нена посл≥довн≥сть:\n";
	for (int i = 0; i < n; ++i) cout << a[i] << ' ';
	cout << '\n';
	return;
}