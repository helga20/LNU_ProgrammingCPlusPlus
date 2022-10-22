#include <iostream>

using namespace std;

int main()
{
	/* Задано натуральне n і послідовність n додатніх чисел.
	   Обчислити їхню суму.
	*/
	cout << " *** Task 1\n\n";
	cout << "Input size of the succession: ";
	int n;
	cin >> n;
	double S = 0.;
	cout << "Input " << n << " positive numbers: ";
	for (int i = 0; i < n; ++i)
	{
		double a;
		cin >> a;
		S += a;
	}
	cout << "Sum = " << S << endl;
	system("pause");
	/* Задано натуральне n і послідовність n додатніх чисел.
	   Чи впорядковано її за зростанням?
	*/
	cout << "\n *** Task 2\n\n";
	cout << "Input size of the succession: ";
	cin >> n;
	cout << "Input " << n << " numbers: ";
	double a, b; // пара сусідніх членів послідовності
	cin >> b;    // перший член читаємо поза циклом
	int i;       // параметр буде потрібний після циклу
	for (i = 1; i < n; ++i)
	{
		a = b;
		cin >> b; // решта послідовності
		if (a >= b) // умову впорядкованості порушено!
			break;  // ПЕРЕРИВАЄМО виконання циклу!
	}
	if (i == n)
	{   // перевірку пройшли всі пари сусідів
		cout << "The succession is sorted\n";
	}
	else
	{   // цикл завершився достроково через порушення умови впорядкованості
		cout << "The succession is not ordered. Wrong value at the position " << i << endl;
	}
	system("pause");
	/* Задано натуральне n і послідовність n чисел.
	   Надрукуйте лише додатні з них і обчисліть їхню кількість.
	*/
	cout << "\n *** Task 3\n\n";
	cout << "Input size of the succession: ";
	cin >> n;
	cout << "Input " << n << " numbers: ";
	int counter = 0;       // кількість додатніх
	for (int i = 0; i < n; ++i)
	{
		double a;
		cin >> a; // черговий член послідовності
		if (a <= 0)   // нічого робити не потрібно
			continue; // ПРОПУСКАЄМО наступні інструкції
		cout << ' ' << a;
		++counter;
	}
	cout << endl;
	cout << "Count of positive members of the succession is equal to " << counter << endl;
	system("pause");
	return 0;
}