#include <Windows.h>
#include "processProcedures.h"

int main()
{
	// Опрацювання текстової інформації

	SetConsoleOutputCP(1251); // налаштуємо виведення кирилицею
	SetConsoleCP(1251);
	int answer;
	do
	{
		system("cls");
		cout << "Виберіть алгоритм для виконання:\n\n 1 - Обчислення кількості цифр (посимвольно)\n"
			<< " 2 - Обчислення кількості цифр у рядку\n 3 - Перетворення рядка на число\n"
			<< " 4 - Сума послідовності чисел\n 5 - Форматоване виведення цілих чисел\n"
			<< " 6 - Відшукання найдовшого слова\n 7 - Завершення роботи\n>>>> ";
		cin >> answer; cin.get();
		system("cls");
		switch (answer)
		{
		case 1: countCharByChar(); break;
		case 2: countInString(); break;
		case 3: stringToNumber(); break;
		case 4: intSuccession(); break;
		case 5: tryfprint(); break;
		case 6: printLongest(); break;
		default: cout << "Допобачення!\n";
		}
		system("pause");
	}
	while (answer > 0 && answer < 7);
	return 0;
}