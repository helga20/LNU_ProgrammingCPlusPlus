#include <iostream>
#include <cmath>

#include "Header.h"

using namespace std;

int main()
{
	const int N = 5;
	Point Vertex[N] = { { 1, 1 }, { 1, 5 }, { 7, 5 }, { 0, 9 }, { 0, -3 } };
	for (int i = 0; i < N; ++i)
		cout << Vertex[i] << '\n';
	double Length = 0.0;
	for (int i = 1; i < N; ++i) 
		Length += Dist(Vertex[i - 1], Vertex[i]);
	cout << "Length = " << Length << "\n";
	system("pause");
	cout << "\n\n\n";
	Point * D = new Point();
	Point * E = new Point(-1, -5);
	cout << *D << "      " << *E << endl;
	cout << (*D).x << " - " << (*D).y << '\n';
	cout << E->x << " - " << E->y << '\n';
	system("pause");
	return 0;
}