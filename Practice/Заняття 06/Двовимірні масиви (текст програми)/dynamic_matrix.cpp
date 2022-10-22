#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n; cin >> n;
	int m = n;

//	int**a = new int*[n];
	int count = 1;
	//for (int i = 0; i < n; ++i)
	//{
	//	a[i] = new int[m];
	//	for (int j = 0; j < m; ++j)
	//	{
	//		a[i][j] = count;
	//		++count;
	//	}
	//}
	//// print
	//cout << "a\b";
	//for (int i = 0; i < n; ++i)
	//{
	//	for (int j = 0; j < m; ++j)
	//	{
	//		cout << a[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	//cout << endl;

	//// matrix of doubles
	////double** b = new double*[n];
	////for (int i = 0; i < n; ++i)
	////{
	////	b[i] = new double[m];
	////	for (int j = 0; j < m; ++j)
	////	{
	////		b[i][j] = (double)a[i][j] * 0.1;
	////	}
	////}
	////// print
	////cout << "\nb\b";
	////for (int i = 0; i < n; ++i)
	////{
	////	for (int j = 0; j < m; ++j)
	////	{
	////		cout << b[i][j] << ' ';
	////	}
	////	cout << endl;
	////}
	////cout << endl;


	//// Завдання 1
	//int** B = new int* [n];
	//int** C = new int* [n];
	//for (int i = 0; i < n; ++i)
	//{
	//	B[i] = new int[n];
	//	C[i] = new int[n];
	//	for (int j = 0; j < n; ++j)
	//	{
	//		// init B
	//		if (j >= 1)
	//		{
	//			B[i][j] = a[i][j];
	//		}
	//		else
	//		{
	//			B[i][j] = a[j][i];
	//		}

	//		// init C
	//		if (j < i)
	//		{
	//			C[i][j] = a[i][j];
	//		}
	//		else
	//		{
	//			C[i][j] = -a[i][j];
	//		}
	//	}
	//}
	//// print B
	//cout << "\nB\b";
	//for (int i = 0; i < n; ++i)
	//{
	//	for (int j = 0; j < n; ++j)
	//	{
	//		cout << B[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	//cout << endl;

	//// print C
	//cout << "\nC\b";
	//for (int i = 0; i < n; ++i)
	//{
	//	for (int j = 0; j < n; ++j)
	//	{
	//		cout << C[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	//cout << endl;


	//// Завдання 2 в.
	//int n2;
	//cout << "Enter n: "; cin >> n2;
	//double** A = new double* [n2];
	//for (int i = 0; i < n2; ++i)
	//{
	//	A[i] = new double[n2];
	//	for (int j = 0; j < n2; ++j)
	//	{
	//		double arg = double(i * i - j * j) / (double)n2;
	//		A[i][j] = sin(arg);
	//	}
	//}
	//// print
	//int counter = 0;
	//cout << "Matrix A\n";
	//for (int i = 0; i < n2; ++i)
	//{
	//	for (int j = 0; j < n2; ++j)
	//	{
	//		cout << A[i][j] << '\t';
	//		if (A[i][j] > 0)
	//		{
	//			++counter;
	//		}
	//	}
	//	cout << endl;
	//}
	//cout << endl;
	//cout << "Number of positive: " << counter << endl;


	//// Завдання 3 а
	//cout << "Task 3. Enter n\n";
	//int n3; cin >> n3;
	//double* x = new double[n3];
	//cout << "Enter array\n";
	//for (int i = 0; i < n3; ++i)
	//{
	//	cout << i << ": ";
	//	cin >> x[i];
	//}

	//double** MX = new double* [n3];
	//for (int i = 0; i < n3; ++i)
	//{
	//	MX[i] = new double[n3];
	//	for (int j = 0; j < n3; ++j)
	//	{
	//		MX[i][j] = pow(x[j], (double)(i + 1));
	//	}
	//}
	//// print
	//cout << "Task 3 a. Matrix\n";
	//for (int i = 0; i < n3; ++i)
	//{
	//	for (int j = 0; j < n3; ++j)
	//	{
	//		cout << MX[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	//cout << endl;


	// Завдання 4 b (b_i)
	cout << "Task 4. \nEnter n: ";  cin >> n;
	cout << "Enter m: ";  cin >> m;

	int** a4 = new int* [n];
	count = 1;
	for (int i = 0; i < n; ++i)
	{
		a4[i] = new int[m];
		for (int j = 0; j < m; ++j)
		{
			a4[i][j] = count / (i+1);
			++count;
		}
	}
	// print
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << a4[i][j] << ' ';
		}
		cout << endl;
	}
	// Утворити послідовність n елт-тів, де і-ий ел-т це найбільше знач з і-го рядка
	int* b4 = new int[n];
	for (int i = 0; i < n; ++i)
	{
		int max = a4[i][0];
		// шукаємо найбільше в рядку і
		for (int j = 1; j < m; ++j)
		{
			if (a4[i][j] > max)
			{
				max = a4[i][j];
			}
		}
		b4[i] = max;
	}
	// print b4
	cout << "Max values in rows\n";
	for (int i = 0; i < n; ++i)
	{
		cout << b4[i] << ' ';
	}
	cout << endl;

	// Завдання 4 а (c_j)
	int* c4 = new int[m];
	for (int j = 0; j < m; ++j)
	{
		int prod = 1;
		for (int i = 0; i < n; ++i)
		{
			prod *= a4[i][j];
		}
		c4[j] = prod;
	}
	cout << "Products by columns\n";
	for (int j = 0; j < m; ++j)
	{
		cout << c4[j] << ' ';
	}
	cout << endl;

	// Завдання 5 в
	cout << "Task 5. Enter n: ";
	int n5; cin >> n5;
	int** a5 = new int*[n5];
	for (int i = 0; i < n5; ++i)
	{
		a5[i] = new int[n5];
		for (int j = 0; j < n5 - i; ++j)
		{
			a5[i][j] = j + 1;
		}
		for (int j = n5 - i; j < n5; ++j)
		{
			a5[i][j] = 0;
		}

		//for (int j = 0; j < n5; ++j)
		//{
		//	a5[i][j] = 0;
		//}
		//a5[i][i] = (i + 1) * (i + 2);
	}
	cout << "Task 5. Matrix v)\n";
	for (int i = 0; i < n5; ++i)
	{
		for (int j = 0; j < n5; ++j)
		{
			cout << a5[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;












	//for (int i = 0; i < n; ++i)
	//{
	//	delete a[i];
	//	//delete b[i];
	//	delete B[i];
	//	delete C[i];
	//}
	//delete[] a;
	////delete[] b;
	//delete[] B;
	//delete[] C;

	system("pause");
	return 0;
}