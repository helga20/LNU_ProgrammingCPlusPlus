#include <cmath>
#include <iostream>
#include "Functions.h"

using std::cout;

// обчисленн€ корен€ п'€того степен€ д≥йсного числа
double ptrt(double x)
{
	double res;
	if (x > 0)
		res = exp(0.2 * log(x));
	else if (x == 0)
		res = 0;
	else
		res = -exp(0.2 * log(-x));
	return res;
}

double Ptrt(double x)
{
	double y = 1.0;
	double z = 0.0;
	while (abs(y - z) > 1.e-10)
	{
		z = y;
		double p = z * z;
		y = (x / (p * p) + 4.*z) / 5.;
	}
	return y;
}

// обм≥н м≥сц€ми двох значень р≥зними способами:
// параметри-значенн€
void swapV(int a, int b)
{
	cout << "\n   --- swapV:   -----------------\n"
		<< "     at begining a = " << a << "    b = " << b << '\n';
	int c = a;
	a = b;
	b = c;
	cout << "     at ending   a = " << a << "    b = " << b
		<< "\n   ------------------------------\n";
}

// параметри-вказ≥вники
void swapP(int* a, int* b)
{
	cout << "\n   --- swapP:   -------------------\n"
		<< "     at begining *a = " << *a << "    *b = " << *b << '\n';
	int c = *a;
	*a = *b;
	*b = c;
	cout << "     at ending   *a = " << *a << "    *b = " << *b
		<< "\n   --------------------------------\n";
}

// параметри-посиланн€
void swapR(int& a, int& b)
{
	cout << "\n   --- swapR:   -----------------\n"
		<< "     at begining a = " << a << "    b = " << b << '\n';
	int c = a;
	a = b;
	b = c;
	cout << "     at ending   a = " << a << "    b = " << b
		<< "\n   ------------------------------\n";
}

void solve(double a, double b, double c, bool& success, double& x1, double& x2)
{
	if (a == 0.0)
	{
		success = false;
		return;
	}
	double D = b*b - 4.0*a*c;
	if (D >= 0.0)
	{
		D = sqrt(D);
		b = -b;
		a *= 2.0;
		x1 = (b - D) / a;
		x2 = (b + D) / a;
		success = true;
	}
	else
		success = false;
}

sqRoots Solve(double a, double b, double c)
{
	if (a == 0.0)
		return sqRoots(false);
	double D = b*b - 4.0*a*c;
	if (D >= 0.0)
	{
		D = sqrt(D);
		b = -b;
		a *= 2.0;
		return sqRoots(true, (b - D) / a, (b + D) / a);
	}
	else
		return sqRoots(false);
}