#include <iostream>
#include "Shape.h"
using namespace std;

int main()
{
	FlatShape* M[] = { new Rect(), new Rect(3, 7), new Square(4.5), new Circle(), new Circle(2.5) };
	const int n = 5;
	for (int i = 0; i < n; ++i) cout << *M[i] << "  S = " << M[i]->area() << '\n';
	int m = 0;
	for (int i = 1; i < n; ++i)
		if (*M[i] > *M[m]) m = i;
	cout << "Largest shape is " << *M[m] << '\n';
	system("pause");
	return 0;
}