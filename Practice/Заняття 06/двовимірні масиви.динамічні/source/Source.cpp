
////Завдання 5 г

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n5, count = 1;
	cout << "Task 5. Enter n: "; cin >> n5;
	int** a5 = new int* [n5];
	for (int i = 0; i < n5; ++i)
	{
		a5[i] = new int[n5];
		
		for (int j = 0; j < n5; ++j) {
			a5[i][j] = 0;
		}
		for (int i = 0; i < n5; ++i) {}
		{for (int j = 0; j < count; ++j)
			a5[i][j] = j + 1; }
		count += 1;
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
	for (int i = 0; i < n5; ++i)
	{
		delete a5[i];
	}
	delete[] a5;


	system("pause");
	return 0;
}





