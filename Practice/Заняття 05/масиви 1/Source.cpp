#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	/*Завдання 1*/
	int arrB[n];
	double arrC[n];
	int arrD[n];
	for (int i = 0; i < n; ++i)
	{
		arrB[i] = arr3[i] * 2 + 5;
		arrC[i] = sin(arr3[i]);
		arrD[i] = arr3[i] * arr3[i];
	}
	cout << "All arrays" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << i << ": ";
		cout << arr3[i] << " | " << arrB[i] << " | " << arrC[i] << " | " << arrD[i] << endl;
	}
	cout << endl;

	//// Завдання 2
	//const int k = 10;
	//int arrY[k];
	//int arrX[k];
	//int sum = 0; 
	//cout << "\nEnter " << k << " values" << endl;
	//for (int i = 1; i < k; ++i)
	//{
	//	cout << "n[" << i << "]: "; cin >> arrY[i];
	//	cout << "x[" << i << "]: "; cin >> arrX[i];
	//	sum += arrX[i]*arrY[i];
	//}
	//cout << "Thank you\n";
	//double result = sum;
	//cout << "Task 4b: " << result << endl;


	//// Завдання 3 
	//// a[0]= 1, a[1] = 1, a[i]= a[i/2] + a[i-2] 
	//const int size = 20;
	//int a[size];
	//a[0] = 1; a[1] = 1;
	//for (int i = 2; i < size; ++i)
	//{
	//	a[i] = a[i / 2] + a[i - 2];
	//}
	//cout << "Task 3: ";
	//for (int i = 0; i < size; ++i)
	//{
	//	cout << a[i] << ' ';
	//}
	//cout << endl;

	//// Завдання 4 а
	//const int k = 10;
	//int arrN[k];
	//int arrX[k];
	//int prod = 1;
	//cout << "\nEnter " << k << " values" << endl;
	//for (int i = 1; i < k; ++i)
	//{
	//	cout << "n[" << i << "]: "; cin >> arrN[i];
	//	cout << "x[" << i << "]: "; cin >> arrX[i];
	//	prod *= arrN[i] + arrX[i];
	//}
	//cout << "Thank you\n";
	//double result = prod;
	//cout << "Task 4a: " << result << endl;


	//// Завдання 4 б
	//const int k = 10;
	//int arrN[k];
	//int arrX[k];
	//int sum = 0; 
	//cout << "\nEnter " << k << " values" << endl;
	//for (int i = 1; i < k; ++i)
	//{
	//	cout << "n[" << i << "]: "; cin >> arrN[i];
	//	cout << "x[" << i << "]: "; cin >> arrX[i];
	//	sum += arrN[i] * arrX[i];
	//}
	//cout << "Thank you\n";
	//double result = sum;
	//cout << "Task 4b: " << result << endl;

	//// Завдання 4 в
	//const int k = 4;
	//int arrN[k];
	//double arrX[k];
	//double numerator = 0.0; // n0*x0 + n1*x1 + ... + n_n-1*x_n-1
	//int denom = 0; // n0 + n1 + ... + n_n-1
	//cout << "\nEnter " << k << " int and double values" << endl;
	//for (int i = 0; i < k; ++i)
	//{
	//	cout << "n[" << i << "]: "; cin >> arrN[i];
	//	cout << "x[" << i << "]: "; cin >> arrX[i];
	//	numerator += (double)arrN[i] * arrX[i];
	//	denom += arrN[i];
	//}
	//cout << "Thank you\n";
	//double result = numerator / (double)denom;
	//cout << "Task 4c: " << result << endl;

	//// Завдання 5
	//const int n = 10; 
	//int arr3[n];
	//cout << "Enter array of " << n << " elements" << endl;
	//for (int i = 0; i < n; ++i)
	//{
	//	cout << i << ": ";
	//	cin >> arr3[i];
	//}
	//cout << "Thank you. Your array: ";
	//for (int i = 0; i < n; ++i)
	//{
	//	cout << arr3[i] << ' ';
	//}
	//cout << endl;

	//cout << "Before: ";
	//for (int i = 0; i < n; ++i)
	//{
	//	cout << arr3[i] << ' ';
	//}
	//cout << endl;
	//for (int i = 0; i < n; ++i)
	//{
	//	if (arr3[i] % 2 == 0)
	//	{
	//		arr3[i] *= 5;
	//	}
	//	else
	//	{
	//		if (arr3[i] % 2 != 0)
	//		{
	//			arr3[i] -= 5;
	//		}			
	//	}
	//}
	//cout << "After: ";
	//for (int i = 0; i < n; ++i)
	//{
	//	cout << arr3[i] << ' ';
	//}
	//cout << endl;;


	return 0;
}