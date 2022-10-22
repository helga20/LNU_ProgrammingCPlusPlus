#pragma once

// обчисленн€ корен€ п'€того степен€ д≥йсного числа
double ptrt(double);
double Ptrt(double);

// обм≥н м≥сц€ми двох значень р≥зними способами:
// параметри-значенн€
void swapV(int a, int b);

// параметри вказ≥вники
void swapP(int* a, int* b);

// параметри посиланн€
void swapR(int& a, int& b);

// розв'€зуванн€ квадратного р≥вн€нн€
void solve(double a, double b, double c, bool& success, double& x1, double& x2);

struct sqRoots
{
	bool success;
	double x1;
	double x2;
	sqRoots(bool s, double u = 0.0, double v = 0.0)
	{
		success = s;  x1 = u; x2 = v;
	}
};

sqRoots Solve(double a, double b, double c);