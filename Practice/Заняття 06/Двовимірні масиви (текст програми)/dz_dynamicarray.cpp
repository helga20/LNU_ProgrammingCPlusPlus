//#include <iostream>
//using namespace std;
//
//int main()
//{
//	// Task 2
//	/*
//	int n;
//	cout << "Enter n: "; cin >> n;
//	double* a = new double[n];
//	double* b = new double[n];
//	cout << "Enter arrays a and b\n";
//	for (int i = 0; i < n; ++i)
//	{
//		cout << "a[" << i << "]: "; cin >> a[i];
//		cout << "b[" << i << "]: "; cin >> b[i];
//	}
//
//	cout << "Your arrays\n";
//	cout << "a: ";
//	for (int i = 0; i < n; ++i)
//	{
//		cout << a[i] << ' ';
//	}
//	cout << "\nb: ";
//	for (int i = 0; i < n; ++i)
//	{
//		cout << b[i] << ' ';
//	}
//	cout << endl;
//
//	// Calculate product
//	double prod = 1.0;
//	for (int i = 0; i < n; ++i)
//	{
//		double item = a[i] + b[n - i - 1];
//		cout << i << ": " << item << endl;
//		prod *= item;
//	}
//	cout << "\nProduct: " << prod << endl;
//	*/
//
//	// Task 4
//	int n;
//	cout << "Enter n: "; cin >> n;
//	int* a = new int[n];
//	cout << "Enter array a \n";
//	int countEven = 0; // парні
//	int countOdd = 0; // непарні
//	// countFive
//	for (int i = 0; i < n; ++i)
//	{
//		cout << "a[" << i << "]: ";
//		cin >> a[i];
//		if (a[i] % 2 == 0)
//		{
//			++countEven;
//		}
//		else
//		{
//			++countOdd;
//			if (a[i] % 5 == 0)
//			{
//				// ++countFive
//			}
//		}
//	}
//
//	cout << "Your arrays\n";
//	cout << "a: ";
//	for (int i = 0; i < n; ++i)
//	{
//		cout << a[i] << ' ';
//	}
//	cout << endl;
//
//	int* arrEven = new int[countEven];
//	int indexEven = 0; // індекс для перебору ел-тів масиву arrEven
//	int* arrOdd = new int[countOdd];
//	int indexOdd = 0;
//	// int*arrFive
//	// int indexFive
//	for (int i = 0; i < n; ++i)
//	{
//		if (a[i] % 2 == 0)
//		{
//			// add this element to array of even
//			arrEven[indexEven] = a[i];
//			++indexEven;
//		}
//		else
//		{
//			// add to odd
//			arrOdd[indexOdd] = a[i];
//			++indexOdd;
//			
//			if (a[i] % 5 == 0)
//			{
//				// add to fifth
//				// arrFive[indexFive] = a[i];
//				// ++indexFive
//			}
//		}
//	}
//
//	cout << "Even: ";
//	for (int i = 0; i < countEven; ++i)
//	{
//		cout << arrEven[i] << ' ';
//	}
//	cout << endl;
//
//	cout << "Odd: ";
//	for (int i = 0; i < countOdd; ++i)
//	{
//		cout << arrOdd[i] << ' ';
//	}
//	cout << endl;
//
//
//
//	system("pause");
//	return 0;
//}