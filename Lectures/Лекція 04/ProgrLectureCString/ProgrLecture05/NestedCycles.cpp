#include <iostream>
using namespace std;

int main()
{
	int num;
	cout << "Input a positive integer: ";
	cin >> num;
	cout << num << " contains:\n";
	for (int digit = 0; digit <= 9; ++digit)
	{
		int cNum = num;
		while (cNum > 0)
		{
			if (cNum % 10 == digit)
			{
				cout << digit << endl;
				break;
			}
			cNum /= 10;
		}
	}
	// перевірка, чи введене число - паліндром
	int digits = 1;  // кількість цифр
	int divider = 1; // дільник для отримання найстаршої цифри
	while (divider * 10 < num)
	{
		++digits;
		divider *= 10;
	}
	int left = num;  // копія для виділення старших цифр (лівої половини)
	int right = num; // копія для виділення молодших цифр (правої половини)
	int step = 1;
	while (step <= digits / 2 && left / divider == right % 10)
	{
		++step;
		left %= divider;
		divider /= 10;
		right /= 10;
	}
	if (step > digits / 2) cout << "Yes, palindrom\n";
	else cout << "No, wrong digit at " << step << endl;
	system("pause");
	return 0;
}