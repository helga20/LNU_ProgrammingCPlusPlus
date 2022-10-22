#include <iostream>
#include "functions.h"
using namespace std;
int main()
{
	double x; int y;
	cout << "Enter a: "; cin >> x;
	cout << "Enter k: "; cin >> y;
	cout << "b = " << expression(x, y) << "\n";
	cout << "\n";


	cout << "Enter n: ";
	int n; cin >> n;
	cout << "Square matrix\n";
	matrix(n);
	cout << "\n";


	int mtrxA[5][6];
	crMatrixA(mtrxA);
	cout << "\nMatrix A(5x6): ";
	wrMatrixA(mtrxA);
	int arr[5];
	vecrorB(arr, mtrxA);
	cout << "Vector b: ";
	printvecrorB(arr);
	cout << "Index: " << indexMin(arr) << endl;
	cout << "\n";


	system("pause");
	return 0;
}


