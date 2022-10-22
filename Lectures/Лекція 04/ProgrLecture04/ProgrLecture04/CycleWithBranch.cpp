#include <iostream>
using namespace std;

int main()
{
	/* Задано десять цілих чисел.
	   Знайдіть значення найбільшого з них.
	   (І його порядковий номер.)
	*/
	const int n = 10;
	cout << "Input " << n << " integers: ";
	int a;
	cin >> a; // введення першого заданого
	// перше припущення: перший - найбільший
	int maxValue = a;
	int maxNum = 0;
	// введення решти заданих
	for (int i = 1; i < n; ++i)
	{
		cin >> a;
		// чи не знайшлося більше?
		if (a > maxValue)
		{
			// запам'ятати знайдене!
			maxValue = a;
			maxNum = i;
		}
	}
	cout << "The maximal value is " << maxValue << endl;
	cout << "Sequence number of the value is " << maxNum << endl;
	system("pause");

	/* Задано десять цілих чисел.
	Скільки з них при діленні на 15 дають в остачі 7?
	*/
	cout << "Input " << n << " integers: ";
	int counter = 0; // шукана кількість
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		// чи введене число "правильне"?
		if (a % 15 == 7) ++counter;
	}
	cout << "The quantity of 15k+7 numbers is " << counter << endl;
	system("pause");

	return 0;
}