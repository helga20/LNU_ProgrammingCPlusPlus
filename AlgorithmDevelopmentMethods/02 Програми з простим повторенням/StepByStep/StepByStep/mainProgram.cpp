#include <Windows.h>
#include "stepProcedures.h"

int main()
{
	// Задачі з покроковим введенням-виведенням даних

	SetConsoleOutputCP(1251); // налаштуємо виведення кирилицею
	int answer;
	do
	{
		system("cls");
		cout << "Виберіть програму для запуску:\n\n 1 - Середнє квадратичне послідовності n чисел\n"
			<< " 2 - Середнє арифметичне послідовності чисел до першого нуля\n 3 - Таблиця значень тригонометричних функцій\n"
			<< " 4 - Виведення числової послідовності\n 5 - Числа Фібоначчі\n 6 - Пов\'язані рекурентні послідовності\n"
			<< " 7 - Завершення роботи\n >>>> ";
		cin >> answer;
		system("cls");
		switch (answer)
		{
		case 1: squareNorm(); break;
		case 2: average(); break;
		case 3: table(); break;
		case 4: succession(); break;
		case 5: Fibonacci(); break;
		case 6: aveVSgeo(); break;
		default: cout << "Допобачення!\n";
		}
		system("pause");
	}
	while (answer > 0 && answer < 7);
	return 0;
}