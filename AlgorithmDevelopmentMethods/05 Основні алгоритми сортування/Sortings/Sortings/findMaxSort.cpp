#include "sortProcedures.h"

// ВПОРЯДКУВАННЯ МАСИВУ а ЗА ДОПОМОГОЮ ВИБОРУ НАЙБІЛЬШОГО
void findMaxSort(int * a, unsigned n)
{
	// шукатимемо найбільший елемент невпорядкованої частини
	// і обмінюватимемо його з її останнім елементом.
	// спочатку невпорядкований весь вектор
	for (unsigned j = n - 1; j > 0; --j)
	{
		int maxVal = a[0]; // початкові значення і номер найбільшого
		unsigned maxPos = 0;
		for (unsigned i = 1; i <= j; ++i)
			if (a[i] > maxVal)
			{
				maxVal = a[i];
				maxPos = i;
			}
		if (maxPos != j) // ставимо найбільшого на його місце
		{
			a[maxPos] = a[j];
			a[j] = maxVal;
		}
	}
	return;
}