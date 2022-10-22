#include "calcProcedures.h"

void dichotomy()
{
	cout << "\n *Обчислення корення рівняння методом дихотомії*\n\n";
	func par = [](double x) -> double { return (x + 4.)*x - 32.; };
	double x1 = dychotom(par, -8.4, -7.7, 1e-4);
	double x2 = dychotom(par, 3.7, 4.2, 1e-4);
	double x3 = dychotom([](double x){ return exp(2.*x) - 3.; }, 0.5, 1.);
	cout << " Ітеративно:\nкорені параболи   x1 = " << x1 << "   x2 = " << x2 << '\n'
		<< "корінь експоненти   x = " << x3 << '\n';
	x1 = dychotomRec(par, -8.4, -7.7, 1e-4);
	x2 = dychotomRec(par, 3.7, 4.2, 1e-4);
	x3 = dychotomRec([](double x){ return exp(2.*x) - 3.; }, 0.5, 1.);
	cout << "\n Рекурсивно:\nкорені параболи   x1 = " << x1 << "   x2 = " << x2 << '\n'
		<< "корінь експоненти   x = " << x3 << '\n';
	return;
}