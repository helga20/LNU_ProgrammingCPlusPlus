#include <iostream>
#include "functionsArrays.h"
using namespace std;

int main()
{
	//int myArr[10];
	//readStaticArray10(myArr);
	//printStaticArray10(myArr);
	//cout << "\n";
	//const int N = 5;
	//int myArr2[N];
	//readArray(myArr2, N);
	//printArray(myArr2, N);
	//int sum = sumArray(myArr2, N);
	//cout << "Sum: " << sum << "\n";
	//int min = minElement(myArr2, N);
	//cout << "Min: " << min << "\n";
	//

	//cout << "\nDynamic array: ";
	//int n; cin >> n;
	//int* b = new int[n];
	//readArray(b, n);
	//printArray(b, n);
	//cout << "\n";
	//sum = sumArray(b, n);
	//cout << "Sum: " << sum << "\n";
	//min = minElement(b, n);
	//cout << "Min: " << min << "\n";

	double coef[7] = {1.0, 2.0, 1.5, 2.1, 0.5, 1.0, 2.5};
	task11(coef);

	cout << "Task 12\n";
	double s,t;
	cout << "Enter s: "; cin >> s;
	cout << "Enter t: "; cin >> t;
	double P12 = task12(coef, s, t);
	cout << "Result: " << P12 << "\n";


	system("pause");
	return 0;
}