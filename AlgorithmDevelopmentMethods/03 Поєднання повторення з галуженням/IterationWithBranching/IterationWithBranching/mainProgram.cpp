#include <Windows.h>
#include "iterProcedures.h"

int main()
{
	// Задачі, що поєднують повторення з галуженням

	SetConsoleOutputCP(1251); // налаштуємо виведення кирилицею
	int answer;
	do
	{
		system("cls");
		cout << "Виберіть програму для запуску:\n\n 1 - Скільки членів послідовності задовольняють умову\n"
			<< " 2 - Скільки точок належать кругові\n 3 - Найбільшого - на початок послідовності\n"
			<< " 4 - Перевірка впорядкованості числової послідовності\n 5 - Вставка числа у впорядковану послідовність\n"
			<< " 6 - Завершення роботи\n >>>> ";
		cin >> answer;
		system("cls");
		switch (answer)
		{
		case 1: countProper(); break;
		case 2: inCircle(); break;
		case 3: exchange(); break;
		case 4: isGrowth(); break;
		case 5: forwardInsert(); simpleInsert(); binaryInsert(); break;
		default: cout << "Допобачення!\n";
		}
		system("pause");
	}
	while (answer > 0 && answer < 6);
	return 0;
}