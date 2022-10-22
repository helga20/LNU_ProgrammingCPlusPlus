#include "calcProcedures.h"

// глобальні змінні
double t;
double X;

// спеціальні підінтегральні функції
double funParam(double x)
{   // для інтеграла, залежного від параметра t
	return pow(x * t, 2) + 1;
}
// для подвійного інтеграла
double twoArg(double y)
{
	return pow(X + 2.*y, 2);
}
double firstInt(double x)
//функція, що обчислює внутрішній інтеграл у повторному
{
	X = x;  // передавання другої змінної через глобальну
	return leftRect(0., x, twoArg, 0.0001);
}

void numIntegration()
{
	cout << "\n *Обчислення інтегралів методом лівих прямокутників*\n\n";
	// обчислимо одновимірний інтеграл
	cout << "Integral(sin,0,Pi) = " << leftRect(0., M_PI, sin) << '\n';
	// а тепер - серію S(t)
	cout << "\n   t     S(t)\n-----------------\n";
	for (int i = 0; i <= 6; ++i)
	{
		t = i*0.5;
		cout << "  " << t << '\t' << leftRect(-1., 1., funParam, 1e-5) << '\n';
	}
	// і нарешті - подвійний
	cout << "\n Подвійний інтеграл повторним числовим інтегруванням\n";
	cout << "Double integral = " << leftRect(0., 1., firstInt, 0.0001) << '\n';
	return;
}