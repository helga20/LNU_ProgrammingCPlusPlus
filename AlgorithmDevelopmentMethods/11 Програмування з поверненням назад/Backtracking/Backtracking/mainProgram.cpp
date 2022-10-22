#include <Windows.h>
#include "Procedures.h"

int main()
{
	// Алгоритми з поверненнями (рекурсивні та звичайні)

	SetConsoleOutputCP(1251); // налаштуємо виведення кирилицею
	int answer;
	do
	{
		system("cls");
		cout << "Виберіть алгоритм для виконання:\n\n 1 - Тур коня рекурсивною процедурою\n"
			<< " 2 - Тур коня без рекурсії\n 3 - Задача про розташування ферзів\n"
			<< " 4 - Завершення роботи\n>>>> ";
		cin >> answer;
		system("cls");
		switch (answer)
		{
		case 1: tourByRecursion(); break;
		case 2: solveTour(); break;
		case 3: putQueens(); break;
		default: cout << "Допобачення!\n";
		}
		system("pause");
	}
	while (answer > 0 && answer < 4);
	return 0;
}