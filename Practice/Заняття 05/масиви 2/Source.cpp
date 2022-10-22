#include <iostream>
using namespace std;

int main()
{
	//int n; cin >> n; // n > 1
	//int* arr = new int[n]; // оголошення динамічного масиву n цілих чисел
	//cout << "Enter array of " << n << " elements\n";
	//for (int i = 0; i < n; ++i)
	//{
	//	cin >> arr[i];
	//}

	//cout << "Array: ";
	//for (int i = 0; i < n; ++i)
	//{
	//	cout << arr[i] << ' ';
	//}
	//cout << endl;

	//// difference arr[0] & arr
	//cout << "arr[0] = " << arr[0] << " arr = " << arr << endl;

	//// array of doubles
	//double* drr = new double[n];

	//delete arr;
	//arr = new int[5];
	//for (int i = 0; i < 5; ++i)
	//{
	//	arr[i] = 1;
	//}
	//for (int i = 0; i < 5; ++i)
	//{
	//	cout << arr[i] << ' ';
	//}
	//delete arr;
	//delete drr;


	//// Завдання 1
	//int n = 10;
	//int* a = new int[n];
	//cout << "Enter " << n << " integers\n";
	//cout << "0: ";  cin >> a[0];
	//int maxA = a[0];
	//for (int i = 0; i < n; ++i)
	//{
	//	cout << i << ": ";  cin >> a[i];
	//	if (a[i] > maxA)
	//	{
	//		maxA = a[i];
	//	}
	//}
	//cout << "Array: ";
	//for (int i = 1; i < n; ++i)
	//{
	//	cout << a[i] << ' ';
	//}
	//cout << "\nMax: " << maxA << endl;

	// Завдання 2
	int n; cin >> n;
	cout << "Enter " << n << " integers\n";
	int* a = new int[n];
	int* b = new int[n];
	int j = 0;
	int f;
	int i; cin >> i;
	int aplusb; cin >> aplusb;
	int* array = new int[aplusb];
	for (int i = 0; j = n - 1; (i < n) && (j >= 0); ++i, j--)
	{
		aplusb *= (a[i] + b[i]);
		f *= (a[i] + b[i]);
	}
	cout << "\nProd of sum(a)= " << aplusb << endl;
	cout << "\nProd of sum(b)= " << aplusb << endl;

	//// Ств новий масив
	//int m = n - countMax;
	//int* b = new int[m];
	//int j = 0; // для ітерування по b
	//for (int i = 0; i < n; ++i) // loop over a
	//{
	//	if (a[i] != maxA)
	//	{
	//		b[j] = a[i];
	//		++j;
	//	}
	//}
	//cout << "New array: ";
	//for (int i = 0; i < m; ++i)
	//{
	//	cout << b[i] << ' ';
	//}
	//cout << endl;

	return 0;
}