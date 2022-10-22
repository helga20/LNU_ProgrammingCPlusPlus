#include <Windows.h>
#include "calcProcedures.h"

int main()
{
	// Обчислення з заданою точністю

	SetConsoleOutputCP(1251); // налаштуємо виведення кирилицею
	int answer;
	do
	{
		system("cls");
		cout << "Виберіть алгоритм для виконання:\n\n 1 - Обчислення суми ряду Тейлора\n"
			<< " 2 - Обчислення суми знакозмінного ряду\n 3 - Метод поділу відрізка навпіл\n"
			<< " 4 - Числове інтегрування\n 5 - Числове інтегрування з лямбда-виразами\n"
			<< " 6 - Завершення роботи\n>>>> ";
		cin >> answer;
		system("cls");
		switch (answer)
		{
		case 1: sinSeriesSum(); break;
		case 2: sumOfSeriesB(); break;
		case 3: dichotomy(); break;
		case 4: numIntegration(); break;
		case 5: lambdaIntegration(); break;
		default: cout << "Допобачення!\n";
		}
		system("pause");
	}
	while (answer > 0 && answer < 6);
	return 0;
}