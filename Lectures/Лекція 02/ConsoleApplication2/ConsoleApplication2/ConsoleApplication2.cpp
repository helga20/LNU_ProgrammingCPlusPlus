#include "pch.h"
#define _USE_MATH_DEFINES  // для використання визначеної константи PI
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// введення заданих величин
	cout << "Input a, b: ";
	double a, b;
	cin >> a >> b;
	cout << "Input gamma: ";
	int gamma;
	cin >> gamma;
	double g = M_PI * gamma / 180.0; // перетворення кута до радіан
	double sin_g = sin(g);           // синус потрібен двічі
	double c = sqrt(a * a + b * b - 2. * a * b * cos(g)); // третя сторона за теоремою синусів
	double S = 0.5 * a * b * sin_g;           // площа
	double P = a + b + c;                     // периметр
	double R = c / (2.*sin_g);                // радіус описаного кола за теоремою синусів
	double r = 2.*S / P;                      // радіус вписаного кола

	// виведення обчислених величин
	cout << "S = " << S << '\n'
		<< "P = " << P << '\n'
		<< "R = " << R << '\n'
		<< "r = " << r << endl;
	system("pause");
	return 0;
}
