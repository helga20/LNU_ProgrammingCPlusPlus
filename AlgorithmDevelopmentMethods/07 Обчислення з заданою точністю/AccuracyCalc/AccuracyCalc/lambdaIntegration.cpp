#include "calcProcedures.h"

void lambdaIntegration()
{
	cout << "\n *Обчислення інтегралів з використанням лямбда-виразів*\n\n";
	// обчислимо одновимірний інтеграл
	cout << "Integral(sin,0,Pi) = " << leftRect(0., M_PI, sin) << '\n';
	// а тепер - серію S(t)
	static double t;           // параметр підінтегральної функції
	cout << "\n   t     S(t)\n-----------------\n";
	for (int i = 0; i <= 6; ++i)
	{
		t = i*0.5;
		cout << "  " << t << '\t' << leftRect(-1., 1., [](double x) {return pow(x * t, 2) + 1; }, 1e-5) << '\n';
	}
	// і нарешті - подвійний
	static double X;           // другий аргумент підінтегральної функції
	cout << "\n Подвійний інтеграл повторним числовим інтегруванням\n";
	double I = leftRect(0., 1., [](double x) { X = x; return leftRect(0., x, [](double y) { return pow(X + 2.*y, 2); }, 0.0001); }, 0.0001);
	cout << "Double integral = " << I << '\n';
	return;
}