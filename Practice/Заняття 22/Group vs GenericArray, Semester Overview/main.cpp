#include <iostream>
#include <fstream>
#include "triangle.h"
#include "equaltriangle.h"
#include "prism.h"
using namespace std;

void printPrismInfo(const Prism& P)
{
	cout << "Prism info\n";
	cout << P << "\n";
	cout << "Side square: " << P.sideSquare() << "\n";
	cout << "Full square: " << P.fullSquare() << "\n";
	cout << "Volume: " << P.volume() << "\n";
	cout << "\n";
}

int main()
{
	Triangle TBase(3, 4, 5);
	EqualTriangle EBase(6.0);

	Prism TPrism(&TBase, 10.0);
	Prism EPrism(&EBase, 7.5);
	printPrismInfo(TPrism);
	printPrismInfo(EPrism);

	ifstream iFile("prisms.txt");
	Prism P1; iFile >> P1;
	Prism P2; iFile >> P2;
	Prism P3; iFile >> P3;
	iFile.close();

	cout << "*** From File ***\n";
	printPrismInfo(P1);
	printPrismInfo(P2);
	printPrismInfo(P3);
	cout << "\n";


	/*
	Triangle T1;
	Triangle T2(3.2, 4.2, 5.2);
	Triangle T3(T2);

	cout << "Enter Triangle info (sides a, b, c):\n";
	cin >> T1;

	cout << "All Triangles:\n";
	cout << T1 << " P = " << T1.perimeter() << " S = " << T1.square() << "\n";
	cout << T2 << " P = " << T2.perimeter() << " S = " << T2.square() << "\n";
	cout << T3 << " P = " << T3.perimeter() << " S = " << T3.square() << "\n";
	cout << "\n";

	if (T1 < T2)
		cout << "Min Triangle: " << T1 << "  S="<< T1.square() << "\n";
	else
		cout << "Min Triangle: " << T2 << "  S=" << T2.square() << "\n";
	cout << "\n";

	cout << "\n------------------------------------\n";

	EqualTriangle ET1;
	EqualTriangle ET2(3.0);
	EqualTriangle ET3(5.1);

	cout << "Enter Equal Triangle info (sides a): ";
	cin >> ET1;

	cout << "All Triangles:\n";
	cout << ET1 << " P = " << ET1.perimeter() << " S = " << ET1.square() << "\n";
	cout << ET2 << " P = " << ET2.perimeter() << " S = " << ET2.square() << "\n";
	cout << ET3 << " P = " << ET3.perimeter() << " S = " << ET3.square() << "\n";
	cout << "\n";
	*/

	return 0;
}