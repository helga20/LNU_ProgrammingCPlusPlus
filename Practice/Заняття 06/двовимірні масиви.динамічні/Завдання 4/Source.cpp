
//Завдання 4
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

	// Завдання 4 b (c_j)
	cout << "Task 4. \nEnter n: ";  cin >> n;
	cout << "Enter m: ";  cin >> m;

	int** a4 = new int* [m];
	count = 1;
	for (int i = 0; i < n; ++i)
	{
		a4[i] = new int[m];
		for (int j = 0; j < m; ++j)
		{
			a4[i][j] = count / (i + 1);
			++count;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << a4[i][j] << ' ';
		}
		cout << endl;
	}
	int* b4 = new int[n];
	for (int j = 0; j < m; ++j)
	{
		int min = a4[0][j];
		for (int i = 1; i < n; ++i)
		{
			if (a4[i][j] < min)
			{
				min = a4[i][j];
			}
		}
		b4[j] = min;
	}
	cout << "Min values in column\n";
	for (int j = 0; j < m; ++j)
	{
		cout << b4[j] << ' ';
	}
	cout << endl;

	// Завдання 4 а (b_i)
	int* c4 = new int[n];
	for (int i = 0; i < n; ++i)
	{
		int sum = 0;
		for (int j = 0; j < m; ++j)
		{
			sum += a4[i][j];
		}
		c4[i] = sum;
	}
	cout << "Sum by rows\n";
	for (int i = 0; i < n; ++i)
	{
		cout << c4[i] << ' ';
	}
	cout << endl;


	for (int i = 0; i < n; ++i)
	{
		delete a4[i];

	}
	delete[] a4;
	system("pause");
	return 0;
}
