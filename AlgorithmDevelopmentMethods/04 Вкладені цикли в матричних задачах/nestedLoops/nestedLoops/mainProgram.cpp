#include <Windows.h>
#include "loopsProcedures.h"

int main()
{
	// Вкладені цикли в матричних задачах

	SetConsoleOutputCP(1251); // налаштуємо виведення кирилицею
	int answer;
	do
	{
		system("cls");
		cout << "Виберіть програму для запуску:\n\n 1 - Побудова одиничної матриці заданого розміру\n"
			<< " 2 - Побудова трикутної матриці заданого розміру\n 3 - Таблиця, заповнена змійкою\n"
			<< " 4 - Матриця з сум елементів іншої матриці\n 5 - Переміщення max-елемента переставлянням рядків і стовпців\n"
			<< " 6 - Відшукання сідлового елементаматриці\n 7 - Завершення роботи\n >>>> ";
		cin >> answer;
		system("cls");
		switch (answer)
		{
		case 1: unitaryMatrix(); symmetricBuildMatrix(); break;
		case 2: triangleMatrix(); break;
		case 3: matrixFromSequence(); sequenceToMatrix(); break;
		case 4: regionsSumming(); economySumming(); break;
		case 5: moveMax(); break;
		case 6: saddleElement(); break;
		default: cout << "Допобачення!\n";
		}
		system("pause");
	}
	while (answer > 0 && answer < 7);
	return 0;
}