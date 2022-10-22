#include <Windows.h>
#include "intProcedures.h"

int main()
{
	// Задачі цілочислової арифметики
	//
	SetConsoleOutputCP(1251); // налаштуємо виведення кирилицею
	int answer;
	do
	{
		system("cls");
		cout << "Виберіть програму для запуску:\n\n 1 - Середнє арифметичне цифр числа\n"
			<< " 2 - Чи є число паліндромом?\n 3 - Перевірка гіпотези Безу\n"
			<< " 4 - Переведення до (2) і (16) систем числення\n 5 - Розклад числа на прості множники\n"
			<< " 6 - Завершення роботи\n >>>> ";
		cin >> answer;
		system("cls");
		switch (answer)
		{
		case 1: digitsAverage(); break;
		case 2: isPolyndrome(); break;
		case 3: BezuHypothesis(); break;
		case 4: binaryForm(); binaryFormStr();
			hexaFormStr(); break;
		case 5: decomposition1(); decomposition2();
			Decomposition(); Factors(); break;
		default: cout << "Допобачення!\n";
		}
		system("pause");
	}
	while (answer > 0 && answer < 6);
	return 0;
}