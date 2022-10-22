#include "Funcs.h"
#include <iostream>

int main()
{
	double a, b;
	std::cout << "Input a, b: ";
	std::cin >> a >> b;
	double c = harmony(a, b);
	std::cout << "c = " << c << '\n';
	system("pause");
	return 0;
}