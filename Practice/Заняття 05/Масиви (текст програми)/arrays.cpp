#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int arr[5]; // оголосили статичний масив
	arr[0] = 4;
	arr[1] = 7;
	arr[2] = 3;
	arr[3] = 1;
	arr[4] = 6;
	cout << "Array: " << arr[0] << ' ' << arr[1] << ' ' << arr[2] << ' ' << arr[3] << ' ' << arr[4] << endl;

	cout << "Array: ";
	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	// ініціалізація списком
	int arr2[5] = {10, 20, 30, 40, 50};
	cout << "Array: ";
	for (int i = 0; i < 5; ++i)
	{
		cout << arr2[i] << ' ';
	}
	cout << endl;

	const int n = 5; // розмір масиву - константа
	int arr3[n];
	// читати з клавіатури
	cout << "Enter array of " << n << " elements" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << i << ": ";
		cin >> arr3[i];
	}
	// вивести на екран
	cout << "Thank you. Your array: ";
	for (int i = 0; i < n; ++i)
	{
		cout << arr3[i] << ' ';
	}
	cout << endl;

	// обчислити суму добуток середнє арифметичне
	int sum = 0;
	int prod = 1;
	for (int i = 0; i < n; ++i)
	{
		sum += arr3[i];
		prod *= arr3[i];
	}
	double avg = (double)sum / (double)n;
	cout << "Sum: " << sum << endl;
	cout << "Prod: " << prod << endl;
	cout << "Avg: " << avg << endl;

	// пошук найбільшого найменшого
	int max = arr3[0];
	int maxIndex = 0;
	int minIndex = 0;
	for (int i = 1; i < n; ++i)
	{
		// max
		if (arr3[i] > max)
		{
			max = arr3[i];
			maxIndex = i;
		}
		// min
		if (arr3[i] < arr3[minIndex])
		{
			minIndex = i;
		}
	}
	cout << "Max: " << max << " index: " << maxIndex << endl;
	cout << "Min: " << arr3[minIndex] << " index: " << minIndex << endl;
	
	// Порахувати к-ть парних ел-тів масиву, к-ть додатніх
	int counterEven = 0;
	int counterPos = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr3[i] % 2 == 0)
		{
			counterEven += 1;
		}

		if (arr3[i] > 0)
		{
			counterPos += 1;
		}
	}
	cout << "Number of even: " << counterEven << endl;
	cout << "Number of positive: " << counterPos << endl;

	// Домножити на 10 всі непарні значення масиву
	// Збільшити на 5 всі парні і такі що > 10
	// Друк до змін
	cout << "Before: ";
	for (int i = 0; i < n; ++i)
	{
		cout << arr3[i] << ' ';
	}
	cout << endl;
	// міняємо ел-ти в масиві
	for (int i = 0; i < n; ++i)
	{
		if (arr3[i] % 2 != 0)
		{
			arr3[i] *= 10;
		}
		else
		{
			if (arr3[i] > 10)
			{
				arr3[i] += 5;
			}			
		}
	}
	// Друк після змін
	cout << "After: ";
	for (int i = 0; i < n; ++i)
	{
		cout << arr3[i] << ' ';
	}
	cout << endl;

	// Створити інштй масив на основі заданого
	// b_i = a_i * 2 + 5;
	// c_i = sin(a_i);
	// d_i = a_i ^ 2;
	int arrB[n];
	double arrC[n];
	int arrD[n];
	for (int i = 0; i < n; ++i)
	{
		arrB[i] = arr3[i] * 2 + 5;
		arrC[i] = sin(arr3[i]);
		arrD[i] = arr3[i] * arr3[i];
	}
	// Print all arrays B
	// <i>: arr3_i | arrB_i | arrC_i | arrD_i
	cout << "All arrays" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << i << ": ";
		cout << arr3[i] << " | " << arrB[i] << " | " << arrC[i] << " | " << arrD[i] << endl ;
	}
	cout << endl;

	// Завдання 3 
	// a[0]= 1, a[1] = 1, a[i]= a[i/2] + a[i-2] 
	const int size = 20;
	int a[size];
	a[0] = 1; a[1] = 1;
	for (int i = 2; i < size; ++i)
	{
		a[i] = a[i / 2] + a[i - 2];
	}
	cout << "Task 3: ";
	for (int i = 0; i < size; ++i)
	{
	cout <<  a[i] << ' ';
	}
	cout << endl;

	// Завдання 4
	const int k = 4;
	int arrN[k];
	double arrX[k];
	double numerator = 0.0; // n0*x0 + n1*x1 + ... + n_n-1*x_n-1
	int denom = 0; // n0 + n1 + ... + n_n-1
	cout << "\nEnter " << k << " int and double values" << endl;
	for (int i = 0; i < k; ++i)
	{
		cout << "n[" << i << "]: "; cin >> arrN[i];
		cout << "x[" << i << "]: "; cin >> arrX[i];
		numerator += (double)arrN[i] * arrX[i];
		denom += arrN[i];
	}
	cout << "Thank you\n";
	double result = numerator / (double)denom;
	cout << "Task 4: " << result << endl;

	return 0;
}