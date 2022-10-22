#include "Functions.h"

std::pair<Complex, Complex> SolveSqrEq(Complex a, Complex b, Complex c)
{
	Complex D = b*b - 4.*a*c;
	Complex d = sqrt(D);
	Complex x1 = (-b - d) / (2.*a);
	Complex x2 = (-b + d) / (2.*a);
	return std::make_pair(x1, x2);
}

Complex CalcSqr(Complex a, Complex b, Complex c, Complex x)
{
	return (a*x + b)*x + c;
}

void ComplexRoots(Complex C, size_t power, std::vector<Complex>& Roots)
{
	Complex r = pow(C, 1. / power);
	double ro = abs(r);
	double phi = arg(r) / power;
	double step = 2. * 3.14159265358979323846 / power;
	Roots.resize(power);
	Roots[0] = r;
	for (size_t i = 1; i < power; ++i)
		Roots[i] = std::polar(ro, phi + i*step);
}
