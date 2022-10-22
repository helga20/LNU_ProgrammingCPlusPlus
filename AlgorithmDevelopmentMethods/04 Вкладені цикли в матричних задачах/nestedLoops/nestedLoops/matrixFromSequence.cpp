#include "loopsProcedures.h"

void matrixFromSequence()
{
	cout << "\n *Заповнення матриці \"змійкою\" заданими значеннями*\n\n"
		<<"Введіть розмір матриці: ";
	unsigned n; cin >> n;
	// виділення пам'яті для динамічної матриці
	int ** a = createMatrix(n);
	// послідовність значень сконструюємо
	int * b = new int[n * n];
	for (int i = 0; i < n * n; ++i) b[i] = i + 1;
	// заповнення матриці значеннями:
	for (int j = 0; j < n; ++j)
	{
		if (j % 2 == 0) // непарний стовпець
		{
			int l = j * n;
			for (int i = 0; i < n; ++i)
				a[i][j] = b[l + i];
		}
		else // парний стовпець
		{
			int l = (j + 1) * n - 1;
			for (int i = 0; i < n; ++i)
				a[i][j] = b[l - i];
		}
	}
	// виведення результатів
	printMatrix(a, n);
	eraseMatrix(a);
	return;
}

void sequenceToMatrix()
{
	cout << "\n *Вкладення \"змійкою\" послідовності в матрицю*\n\n"
		<<"Введіть розмір матриці: ";
	unsigned n; cin >> n;
	// виділення пам'яті для динамічної матриці
	int ** a = createMatrix(n);
	// послідовність значень сконструюємо
	int * b = new int[n * n];
	for (int i = 0; i < n * n; ++i) b[i] = i + 1;
	// заповнення матриці значеннями:
	int i = 0; int j = 0;   // координати початкового елемента
	int step = 1;           // спочатку напрям руху - додатній
	for (int k = 1; k <= n * n; ++k)
	{					    // вкладаємо всі члени послідовності
		a[i][j] = b[k - 1]; // розташували чергове число
		if (k % n == 0)     // стовпець заповнено
		{
			++j;            // перейшли до нового стовпця
			step = -step;   // і змінили напрям
		}
		else i += step;     // просуваємося стовпцем
	}
	// виведення результатів
	printMatrix(a, n);
	eraseMatrix(a);
	return;
}