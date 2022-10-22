#include <Windows.h>
#include "dataProcedures.h"

int main()
{
	// Сортування структур даних

	SetConsoleOutputCP(1251); // налаштуємо виведення кирилицею
	int answer;
	do
	{
		system("cls");
		cout << "Виберіть алгоритм для виконання:\n\n 1 - Впорядкування кожного рядка матриці\n"
			<< " 2 - Сортування рядків матриці\n 3 - Сортування рядків матриці за сумами модулів\n"
			<< " 4 - Впорядкування файла за допомогою списку\n 5 - Впорядкування файла бінарним деревом\n"
			<< " 6 - Впорядкування файла злиттям\n 7 - Завершення роботи\n>>>> ";
		cin >> answer;
		system("cls");
		switch (answer)
		{
		case 1: sortEachRow(); break;
		case 2: sortMatrix(); break;
		case 3: sortMatrixSum(); break;
		case 4: sortByChain(); break;
		case 5: sortByTree(); break;
		case 6: sortByMerge(); break;
		default: cout << "Допобачення!\n";
		}
		system("pause");
	}
	while (answer > 0 && answer < 7);
	return 0;
}