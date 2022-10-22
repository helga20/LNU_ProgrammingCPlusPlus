// Завдання 2 а
#include <iostream>
#include <cmath>
using namespace std;
int main()
{	int n;
	cout << "Enter n: "; cin >> n;
	double** A = new double* [n];
	for (int i = 0; i < n; ++i)
	{
		A[i] = new double[n];
		for (int j = 0; j < n; ++j)
		{
			double arg = double(i) + double(j / 2);
			A[i][j] = sin(arg);
		}
	}
	int counter = 0;
	cout << "Matrix A\n";
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << A[i][j] << '\t';
			if (A[i][j] > 0)
			{
				++counter;
			}
		}
		cout << endl;
	}
	cout << endl;
	cout << "Number of positive: " << counter << endl;
	for (int i = 0; i < n; ++i)
	{
		delete A[i];
	}
	delete[]A;
	system("pause");
	return 0;
}


//// Завдання 2 б
//#include <iostream>
//#include <cmath>
//using namespace std;
//int main()
//{
//	int n2;
//	cout << "Enter n: "; cin >> n2;
//	double** B = new double* [n2];
//	for (int i = 0; i < n2; ++i)
//	{
//		B[i] = new double[n2];
//		for (int j = 0; j < n2; ++j)
//		{
//			double arg = double(i*i) + (double)n2;
//			B[i][j] =cos(arg);
//		}
//	}
//	int counter = 0;
//	cout << "Matrix A\n";
//	for (int i = 0; i < n2; ++i)
//	{
//		for (int j = 0; j < n2; ++j)
//		{
//			cout << B[i][j] << '\t';
//			if (B[i][j] > 0)
//			{
//				++counter;
//			}
//		}
//		cout << endl;
//	}
//	cout << endl;
//	cout << "Number of positive: " << counter << endl;
//	for (int i = 0; i < n2; ++i)
//	{
//		delete B[i];
//	}
//	delete[]B;
//	system("pause");
//	return 0;
//}

