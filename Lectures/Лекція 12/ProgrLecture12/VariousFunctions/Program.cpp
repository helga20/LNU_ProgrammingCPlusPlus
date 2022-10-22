#include <iostream>
#include "Functions.h"

int main()
{
	double d[] = { 3.5, -1.99, 0.75, 4.3, 2.2 };
	const int n = sizeof d / sizeof d[0];
	double largest = maxVal(d, n);
	std::cout << "largest element of the array is " << largest << '\n';

	int binaryThousand = 1 << 10;
	int biggest = maxVal(1000, binaryThousand, round(pow(3.1, 6)));
	std::cout << "The biggest number is " << biggest << '\n';

	system("pause");

	writeLine();
	writeLine('=');
	writeLine('_', 40);
	/*writeLine(, 40);*/ writeLine('\n', 1);
	writeLine(40);
	std::cout << left("Hello, World", 5) << '\n';
	std::cout << left("Hello") << '\n';
	system("pause");

	double a = 3.5;
	double b = 4.7;
	double c = sqrt(sqr(a - 0.5) + sqr(b - 0.7));
	std::cout << " C = " << c << '\n';
	system("pause");

	writeSum(1, 2, 3, 4, 5, 0);
	writeSum(5, -3, 1, 0, 2);
	writeSum(0);
	PrintVar("fcsi", 32.1, 'a', "Test string", 4);
	ShowVar("fcsi", 32.1, 'a', "Test string", 4);
	system("pause");

	printChars('A', 3);   // counter == 1;
	std::cout << "\nstart\n";
	// р€дки "*****" буде надруковано не б≥льше семи раз≥в,
	// перех≥д на новий р€док Ц не б≥льше шести раз≥в.
	while (printChars('*', 5) < 7) std::cout << '\n';
	std::cout << " the End\n";
	system("pause");

	return 0;
}