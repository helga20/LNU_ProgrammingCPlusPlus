//#include <iostream>
//using namespace std;
//
//int main()
//{
//	// Static two-dimensional array
//	//const int n = 3;
//	//const int m = 4;
//	//int A[n][m]; // оголошення 2-вим масиву цілих чисел
//	//// 0-ий рядок
//	//A[0][0] = 1;
//	//A[0][1] = 2;
//	//A[0][2] = 3;
//	//A[0][3] = 4;
//	//// 1-ий рядок
//	//A[1][0] = 3;
//	//A[1][1] = 5;
//	//A[1][2] = 6;
//	//A[1][3] = 8;
//	//// 2-ий рядок
//	//A[2][0] = 2;
//	//A[2][1] = 5;
//	//A[2][2] = 4;
//	//A[2][3] = 7;
//
//	//for (int i = 0; i < n; ++i) // зовнішній цикл перебирає рядки
//	//{
//	//	cout << "Row " << i << ": ";
//	//	for (int j = 0; j < m; ++j) // внутрішній - перебирає стовпчики
//	//	{
//	//		cout << A[i][j] << ' ';
//	//	}
//	//	cout << endl;
//	//}
//	//cout << endl;
//
//	//int B[n][m];
//	//cout << "Enter matrix " << n << " x " << m << "\n";
//	//for (int i = 0; i < n; ++i)
//	//{
//	//	cout << "Row " << i << ": ";
//	//	for (int j = 0; j < m; ++j)
//	//	{
//	//		cout << "B[" << i << "][" << j << "]: ";
//	//		cin >> B[i][j];
//	//	}
//	//}
//	//cout << "Matrix B\n";
//	//for (int i = 0; i < n; ++i) // зовнішній цикл перебирає рядки
//	//{
//	//	for (int j = 0; j < m; ++j) // внутрішній - перебирає стовпчики
//	//	{
//	//		cout << B[i][j] << ' ';
//	//	}
//	//	cout << endl;
//	//}
//	//cout << endl;
//
//	// Sums of rows in marix A
//	//for (int i = 0; i < n; ++i)
//	//{
//	//	int sum = 0;
//	//	for (int j = 0; j < m; ++j)
//	//	{
//	//		sum += A[i][j];
//	//	}
//	//	cout << "Sum of row " << i << ": " << sum << endl;
//	//}
//	//cout << endl;
//
//	//// Sum of columns in matrix A
//	//for (int j = 0; j < m; ++j) // Зовнішній цикл - перебирає стовпчики матриці
//	//{
//	//	int sum = 0;
//	//	for (int i = 0; i < n; ++i) // внутрішні - перебирає елт-ти по рядках в стопчику j
//	//	{
//	//		sum += A[i][j];
//	//	}
//	//	cout << "Sum of column " << j << ": " << sum << endl;
//	//}
//	//cout << endl;
//
//	// Завдання 3
//	const int n = 10;
//	int a[n][n];
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			if (i < j)
//			{
//				a[i][j] = (i + 1) + 2 * (j + 1);
//			}
//			else if (i > j)
//			{
//				a[i][j] = (i + 1);
//			}
//			else
//			{
//				a[i][j] = 10;
//			}
//			
//		}
//	}
//	cout << "Task 3. Matrix a\n";
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			cout << a[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	cout << endl;
//
//	// Завдання 2
//	const int k = 3;
//	int arr[k];
//	int b[k][k];
//
//	cout << "Enter 3 integers: ";
//	cin >> arr[0] >> arr[1] >> arr[2];
//
//	for (int i = 0; i < k; ++i)
//	{
//		for (int j = 0; j < k; ++j)
//		{
//			b[i][j] = arr[i] - 3 * arr[j];
//		}
//	}
//	cout << "Task 2. Matrix b\n";
//	for (int i = 0; i < k; ++i)
//	{
//		for (int j = 0; j < k; ++j)
//		{
//			cout << b[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	cout << endl;
//
//	system("pause");
//	return 0;
//}