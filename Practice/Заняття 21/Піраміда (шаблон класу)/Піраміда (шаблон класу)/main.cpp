#include "circle.h"
#include "square.h"
#include "pyramid.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	cout << "\n_______Square_______\n";
	Square S1;
	Square S2(5);
	Square S3(S2);
	cout << "\n";

	S1.printInfo();
	S1.getPerimeter();
	S1.getSquare();
	cout << "\n";

	S2.printInfo();
	S2.getPerimeter();
	S2.getSquare();
	cout << "\n";

	S3.printInfo();
	S3.getPerimeter();
	S3.getSquare();
	cout << "\n";
	system("pause");

	cout << "\n_______Circle_______\n";
	Circle C1;
	Circle C2(4);
	Circle C3(C2);
	cout << "\n";

	C1.printInfo();
	C1.getPerimeter();
	C1.getSquare();
	cout << "\n";

	C2.printInfo();
	C2.getPerimeter();
	C2.getSquare();
	cout << "\n";

	C3.printInfo();
	C3.getPerimeter();
	C3.getSquare();
	cout << "\n";
	system("pause");
	
	cout << "\n_______Pyramid_______\n";
	Square S4 (5.0);
	Circle C4 (4.0);

	Pyramid<Circle> PCircle_default;
	Pyramid<Circle> PCircle_1(1.0, 3.0, 4.0);
	Pyramid<Circle> PCircle_2(6.0, 4.0, 2.0);
	Pyramid<Square> PSquare_3(3.0, 7.0, 8.0);
	Pyramid<Square> PSquare_4(2.0, 1.0, 5.0);
	Pyramid<Square> PSquare_copy(PSquare_3);

	PCircle_default.printPyramid();
	PCircle_1.printPyramid();
	PCircle_2.printPyramid();
	PSquare_3.printPyramid();
	PSquare_4.printPyramid();
	PSquare_copy.printPyramid();
	cout << "\n";
	system("pause");

	cout << "\n1 Pyramid:";
	PCircle_1.printPyramid();
	PCircle_1.getSurfaceArea();
	PCircle_1.getVolume();

	cout << "\n2 Pyramid:";
	PCircle_2.printPyramid();
	PCircle_2.getSurfaceArea();
	PCircle_2.getVolume();

	cout << "\n3 Pyramid:";
	PSquare_3.printPyramid();
	PSquare_3.getSurfaceArea();
	PSquare_3.getVolume();

	cout << "\n4 Pyramid:";
	PSquare_4.printPyramid();
	PSquare_4.getSurfaceArea();
	PSquare_4.getVolume();
	cout << "\n";
	system("pause");

	cout << "*Change of height, apopheme and basis*\n";
	PCircle_default.setHeight(7);
	PCircle_default.setApophema(6);
	PCircle_default.setBase(C2);
	PCircle_default.printPyramid();
	cout << "\n";

	PCircle_default.setHeight(-7);
	PCircle_default.setApophema(0);
	PCircle_default.setBase(C2);
	PCircle_default.printPyramid();
	cout << "\n";
	system("pause");

	Pyramid<Square> PSq_1;
	cout << "\nEnter Pyramid info(height, apophema, base)\n";
	cin >> PSq_1;
	cout << PSq_1;
	cout << "\n\n";

	Pyramid<Square> PSq_2;
	cout << "*ReadFrom/writeTo*\n";
	cout << "Enter Pyramid info(height, apophema, base)\n";
	PSq_2.readPyramid(cin);
	PSq_2.writePyramid(cout);

	cout << "\n\n*Pyramid from file*\n";
	ifstream iFile("pyramid_info.txt");
	int n; iFile >> n;
	for (int i = 0; i < n; ++i)
	{
		char type; iFile >> type;
		if (type == 'S')
		{
			Pyramid<Square> P;
			iFile >> P;
			P.printPyramid();
		}
		else if (type == 'C')
		{
			Pyramid<Circle> P;
			iFile >> P;
			P.printPyramid();
		}
		else
		{
			iFile.ignore(256, '\n');
			continue;
		}
	}
	iFile.close();

	cout << "\n";
	system("pause");
	return 0;
}