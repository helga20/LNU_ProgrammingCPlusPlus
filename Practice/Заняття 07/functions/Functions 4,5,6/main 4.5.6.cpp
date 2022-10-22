////Завдання 3
//#include <iostream>
//#include "functions 3,4,5,6.h"
//using namespace std;
//
//int main()
//{
//	printInfo(05, 11, 2020);
//
//	system("pause");
//	return 0;
//}


#include <iostream>
#include "functions 3,4,5,6.h"
using namespace std;
int main()
{
	double x, y, z, r, k;
	const double e = 1;

	cout << "Enter x: "; cin >> x;
	cout << "Enter y: "; cin >> y;
	cout << "(4)difference: " << difference(x, y) << "\n";
	cout << "(4)product: " << product(x, y) << "\n";

	cout << "\nEnter square\n";
	cout << "Side: "; cin >> x;
	double p = perimOfSquare(x);
	double s = squareOfSquare(x);
	cout << "(5)Perimeter: " << p << "\n(5)Square: " << s << "\n";

	cout << "\nEnter triangle\n";
	cout << "Side 1: "; cin >> x;
	cout << "Side 2: "; cin >> y;
	cout << "Side 3: "; cin >> z;
	double p3 = perimOfTrianglee(x, y, z);
	double s3 = squareOfTriangle(x, y, z);
	cout << "(5)Perimeter: " << p3 << "\n(5)Square: " << s3 << "\n";

	cout << "\nEnter circle\n";
	cout << "r: "; cin >> r;
	double s4 = squareOfCircle(r);
	cout << "(5)Circle: " << s4 << "\n";

	
	cout << "\nEnter pentagon\n";
	cout << "a: "; cin >> x;
	cout << "b: "; cin >> y;
	cout << "c: "; cin >> z;
	cout << "d: "; cin >> k;
	std::cout << e;
	double s5 = squareOfPentagon(x, y, z, k, e);
	cout << "\n(5)Pentagon: " << s5 << "\n";
	system("pause");
	return 0;
}



