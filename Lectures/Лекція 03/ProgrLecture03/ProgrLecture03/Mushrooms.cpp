#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	// Встановимо правильне кодування для виведення кирилиці
	SetConsoleOutputCP(1251);
	/* Задано ціле k з проміжку [0; 99].
	   Надрукувати фразу "Ми знайшли k грибів", узгоджуючи закінчення слів
	*/
	cout << "Уведіть ціле число з [0; 99]: ";
	int k;
	cin >> k;
	cout << "\n *** За допомогою if\n\n";
	// 1, 21, 31, ..., 91 гриб
	// 2, 3, 4, 22, 23, 24, ..., 94 гриби
	// 5, 6, ..., 20, 25, 26, ..., 30, 35, ..., 99 грибів
	if (k == 0) cout << "Ми не знайшли грибів\n";
	else
	{
		cout << "Ми знайшли " << k;
		if (k >= 5 && k <= 20) cout << "грибів\n";
		else
		{
			int d = k % 10;
			if (d == 1) cout << " гриб\n";
			else if (d >= 2 && d <= 4) cout << " гриби\n";
			else cout << " грибів\n";
		}
	}
	system("pause");

	cout << "\n *** За допомогою switch\n\n";
	switch (k)
	{
	case 0:
		cout << "Ми не знайшли грибів\n"; break;
	case 11: case 12: case 13: case 14: case 15:
	case 16: case 17: case 18: case 19:
		cout << "Ми знайшли " << k << " грибів\n"; break;
	default:
		switch (k % 10)
		{
		case 1: cout << "Ми знайшли " << k << " гриб\n"; break;
		case 2: case 3: case 4:
			cout << "Ми знайшли " << k << " гриби\n"; break;
		case 5: case 6: case 7: case 8: case 9: case 0:
			cout << "Ми знайшли " << k << " грибів\n"; break;
		}
	}
	system("pause");
	return 0;
}