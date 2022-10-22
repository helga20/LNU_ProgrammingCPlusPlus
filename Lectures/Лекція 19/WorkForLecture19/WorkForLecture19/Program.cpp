#include <iostream>
#include "Shape.h"
#include "Cylinders.h"
using namespace std;

int main()
{
	DerivCylinder D(5., 10.);
	cout << D << "\n S = " << D.totalArea() << "\n V = " << D.volume() << "\n\n";
	ComposedCylinder C(5., 10.);
	cout << C << "\n S = " << C.totalArea() << "\n V = " << C.volume() << "\n\n";
	ComposedCylinder R;
	cout << R << "\n\n";
	system("pause");
	return 0;
}