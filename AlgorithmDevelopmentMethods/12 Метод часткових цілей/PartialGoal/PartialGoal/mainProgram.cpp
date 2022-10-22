#include <Windows.h>
#include "Procedures.h"

int main()
{
	// Алгоритми методу часткових цілей

	SetConsoleOutputCP(1251); // налаштуємо виведення кирилицею
	int answer;
	do
	{
		system("cls");
		cout << "Виберіть алгоритм для виконання:\n\n 1 - Перетворення найпростіших арифметичних виразів\n"
			<< " 2 - Перетворення виразів з дужками\n 3 - Перетворення виразів з багатоцифровими операндами\n"
			<< " 4 - Обчислення значення арифметичного виразу\n 5 - Завершення роботи\n>>>> ";
		cin >> answer; cin.get();
		system("cls");
		switch (answer)
		{
		case 1: postfixLight(); break;
		case 2: postfix(); break;
		case 3: postfixExt(); break;
		case 4: translateAndCalculate(); break;
		default: cout << "Допобачення!\n";
		}
		system("pause");
	}
	while (answer > 0 && answer < 5);
	return 0;
}