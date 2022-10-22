#include "iterProcedures.h"

void countProper()
{
	cout << "\n *ќбчисленн€ к≥лькост≥ \"правильних\" член≥в посл≥довност≥*\n\n";
	unsigned n;
	cout << "¬вед≥ть к≥льк≥сть чисел: "; cin >> n;
	long long p = 1; // степ≥нь дв≥йки
	long long f = 1; // фактор≥ал
	unsigned k = 0;  // л≥чильник
	for (unsigned i = 1; i <= n; ++i)
	{
		cout << "¬вед≥ть " << i << "-e числo: ";
		double a; cin >> a;
		p *= 2; f *= i;
		if (p < a && a < f+3) ++k;
	}
	cout << "k = " << k << '\n';
	return;
}