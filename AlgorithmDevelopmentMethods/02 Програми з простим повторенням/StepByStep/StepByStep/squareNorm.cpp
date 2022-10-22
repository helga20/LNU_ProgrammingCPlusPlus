#include "stepProcedures.h"
#include <cmath>

void squareNorm()
{
	cout << "\n *Середнє квадратичне заданої кількості дійсних чисел*\n\nВведіть натуральне число: ";
	unsigned n; cin >> n;
	double s = 0.0;
	for (unsigned i = 1; i <= n; ++i)
	{
		cout << "Введіть " << i << "-е число: ";
		double a; cin >> a;
		s += a * a;
	}
	s = std::sqrt(s);
	cout << "Середнє квадратичне = " << s / n << '\n';
	return;
}