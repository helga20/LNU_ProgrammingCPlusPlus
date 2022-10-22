// Завдання 3 б
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n; cin >> n;
	int m = n;
	int** a = new int* [n];
	int count = 1;
	for (int i = 0; i < n; ++i)
	{
		a[i] = new int[m];
		for (int j = 0; j < m; ++j)
		{
			a[i][j] = count;
			++count;
		}
	}
	int k = 1;
	cout << "Task 3 b. Enter n\n";
	int n3; cin >> n3;
	double* x = new double[n3];
	cout << "Enter array\n";
	for (int i = 0; i < n3; ++i)
	{
		cout << i << ": ";
		cin >> x[i];
	}

	double** MX = new double* [n3];
	for (int i = 0; i < n3; ++i)
	{
		MX[i] = new double[n3];
		for (int j = 0; j < n3; ++j)
		{
			MX[i][j] = k * x[i];
		}
		k = k + 1;
	}
	cout << "Task 3 b. Matrix\n";
	for (int i = 0; i < n3; ++i)
	{
		for (int j = 0; j < n3; ++j)
		{
			cout << MX[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < n3; ++i)
	{
		delete MX[i];

	}
	delete[] MX;
	system("pause");
	return 0;
}
