#include <iostream>
#include <ctime>
#include "functions.h"

using namespace std;

int main()

{                                     // First task
	double x;
	cout << "Please, input x: ";
	cin >> x;
	cout << "Expression = " << sqrt(pow(funcX(x - 1), 2) + 3) - 4 * pow(funcX(x), 3) + 8 << endl;

                                      // Second task
	int n;
tryAgain:
	cout << "\nPlease, input n > 0: ";
	cin >> n;
	if (n < 1) {
		cout << "\nPlease, try again.\n";
		goto tryAgain;
	}
	int** matrix = new int* [n];
	createMatrix(matrix, n);
	cout << "\nMatrix n*n\n";
	writeMatrix(matrix, n);
	for (int i = 0; i < n; ++i) {
		delete matrix[i];
	}
	delete[] matrix;
	                                  // Third task
	int mxC[5][6];
	createMXC(mxC);
	cout << "\nMatrix C";
	writeMXC(mxC);
	int arr[5];
	vectorA(arr, mxC);
	cout << "Vector a: ";
	printVectorA(arr);
	cout << "Index of min element of vector a : " << indexOFmin(arr) << endl;
	system("pause");
	return 0;
}
