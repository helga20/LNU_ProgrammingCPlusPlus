#include <iostream>
#include <cmath>
using namespace std;
int main(){


////Завдання 1
//	/*int n;
//	cin >> n;*/
//	const int n = 20;
//	const int size = 20;
//	int arr3[n];
//	int arrB[n];
//	double arrC[n];
//	int arrD[n];
//	for (int i = 0; i < n; ++i)
//	{
//		arrB[i] = arr3[i] * 2 + 5;
//		arrC[i] = sin(arr3[i]);
//		arrD[i] = arr3[i] * arr3[i];
//	}
//	cout << "All arrays" << endl;
//	for (int i = 0; i < n; ++i)
//	{
//		cout << i << ": ";
//		cout << arr3[i] << " | " << arrB[i] << " | " << arrC[i] << " | " << arrD[i] << endl;
//	}
//	cout << endl;

//	// Завдання 3 
//	const int size = 20;
//	int a[size];
//	a[0] = 1; a[1] = 1;
//	for (int i = 2; i < size; ++i)
//	{
//		a[i] = a[i / 2] + a[i - 2];
//	}
//	cout << "Task 3: ";
//	for (int i = 0; i < size; ++i)
//	{
//		cout << a[i] << ' ';
//	}
//	cout << endl;
//
//	// Завдання 4
//	const int k = 4;
//	int arrN[k];
//	double arrX[k];
//	double numerator = 0.0; // n0*x0 + n1*x1 + ... + n_n-1*x_n-1
//	int denom = 0; // n0 + n1 + ... + n_n-1
//	cout << "\nEnter " << k << " int and double values" << endl;
//	for (int i = 0; i < k; ++i)
//	{
//		cout << "n[" << i << "]: "; cin >> arrN[i];
//		cout << "x[" << i << "]: "; cin >> arrX[i];
//		numerator += (double)arrN[i] * arrX[i];
//		denom += arrN[i];
//	}
//	cout << "Thank you\n";
//	double result = numerator / (double)denom;
//	cout << "Task 4: " << result << endl;
//
//	return 0;
//}
//// Завдання 4
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
//cout << "Task 4: " << result << endl;
//

	/*Завдання 5*/

	 /*Збільшити на 5 всі парні і такі що > 10*/
	cout << "Before: ";
	for (int i = 0; i < n; ++i)
	{
		cout << arr3[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		if (arr3[i] % 2 == 0)
		{
			arr3[i] *= 5;
		}
		else
		{
			if (arr3[i] %2 != 0)
			{
				arr3[i] -= 5;
			}			
		}
	}
	cout << "After: ";
	for (int i = 0; i < n; ++i)
	{
		cout << arr3[i] << ' ';
	}
	cout << endl;

return 0;
}