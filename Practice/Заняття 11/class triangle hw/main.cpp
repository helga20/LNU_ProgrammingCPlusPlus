#include<iostream>
#include <fstream>
#include "triangle.h"
using namespace std;

int main()
{
	Triangle T1;
	Triangle T2(3, 4, 5);
	Triangle T3(T2);
	cout << "\n";

	cout << "Triangle info\n";
	cout << "a = " << T2.getA() << "\nb = " << T2.getB() << "\nc = " << T2.getC() << "\n";
	T1.printInfo();

	cout << "\nVia getters\n";
	T1.getA() = 6;
	T1.getB() = 8;
	T1.getC() = 10;
	T1.printInfo();
	cout << "\n";

	T3.setA(9);
	T3.setB(12);
	T3.setC(15);
	T3.printInfo();

	double a1;
	cout << "\nPlease, enter 1 new side: ";
	cin >> a1;
	T3.setA(a1);
	T3.printInfo();

	double a2;
	cout << "\nPlease, enter 2 new side: ";
	cin >> a2;
	T3.setA(a2);
	T3.printInfo();

	double a3;
	cout << "\nPlease, enter 3 new side: ";
	cin >> a3;
	T3.setA(a3);
	T3.printInfo();

	Triangle T4;
	cout << "\nPlease, enter triangle info:\n";
	cin >> T4;
	cout << "\nHere is your triangle" << T4 << "\n";

	double p;
	p = T4.getPerimeter();
	cout << "Perimeter = " << p << "\n";

	double s;
	s = T4.getSquare();
	cout << "Square = " << s << "\n";

	const int n = 4;
	Triangle myArray[4] = { T1, T2, T3,T4 };
	printArray(myArray, n);

	ifstream iFile("triangles_info.txt");
	int size; iFile >> size;
	Triangle* fileArray = new Triangle[size];
	for (int i = 0; i < size; ++i)
	{
		iFile >> fileArray[i];
	}
	iFile.close();
	cout << "\nTriangles from file\n";
	printArray(fileArray, size);

	sortByPerimeter(fileArray,size);
	cout << "\nDecreasing parameters: \n";
	printArray(fileArray, size);

	cout << "Total square =  " << totalSquare(fileArray, size) << "\n";

	cout << "\n";
	delete[]fileArray;
	return 0;
}
