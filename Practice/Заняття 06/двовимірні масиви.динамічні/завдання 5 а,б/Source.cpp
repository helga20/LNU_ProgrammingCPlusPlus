
// Завдання 5 а
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	cout << "Task 5 a. Enter n: ";
	int n5; cin >> n5;
	int** a5 = new int* [n5];
	for (int i = 0; i < n5; ++i)
	{
		a5[i] = new int[n5];
		for (int j = 0; j < n5 - i; ++j)
		{
			a5[i][j] = j;
		}
		for (int j = n5 - i; j < n5; ++j)
		{
			a5[i][j] = 0;
		}

		for (int j = 0; j < n5; ++j)
		{
			a5[i][j] = 0;
		}
		a5[i][i] = 1;
	}
	cout << "Task 5. Matrix a\n";
	for (int i = 0; i < n5; ++i)
	{
		for (int j = 0; j < n5; ++j)
		{
			cout << a5[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < n5; ++i)
	{
		delete a5[i];
	}
	delete[] a5;
	

	system("pause");
	return 0;
}

// /*Завдання 5 б/
//#include <iostream>
//#include <cmath>
//using namespace std;
//int main()
//{
//	cout << "Task 5 b. Enter n: ";
//	int n5; cin >> n5;
//	int** a5 = new int* [n5];
//	for (int i = 0; i < n5; ++i)
//	{
//		a5[i] = new int[n5];
//		for (int j = 0; j < n5 - i; ++j)
//		{
//			a5[i][j] = j;
//		}
//		for (int j = n5 - i; j < n5; ++j)
//		{
//			a5[i][j] = 0;
//		}
//
//		for (int j = 0; j < n5; ++j)
//		{
//			a5[i][j] = 0;
//		}
//		a5[i][i] = 1+i;
//	}
//	cout << "Task 5. Matrix b\n";
//	for (int i = 0; i < n5; ++i)
//	{
//		for (int j = 0; j < n5; ++j)
//		{
//			cout << a5[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	cout << endl;
//	for (int i = 0; i < n5; ++i)
//	{
//		delete a5[i];
//	}
//	delete[] a5;
//	
//
//	system("pause");
//	return 0;
//}