#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	// замінити у заданому рядку всі символи '+' на рядок "plus"
	char a[] = "One + Two * ++Three";
	cout << a << endl;
	size_t la = strlen(a);
	// обчислимо кількість '+', щоб оцінити довжину рядка-результату
	size_t countPlus = 0;
	for (size_t i = 0; i < la; ++i)
		if (a[i] == '+') ++countPlus;
	// виділимо пам'ять, сам рядок спочатку порожній
	char * b = new char[la + countPlus * 3 + 1];
	b[0] = '\0';
	// запам'ятаємо початок пошуку
	char * prevPos = a;
	// і знайдемо перший '+'
	char * pos = strchr(a, '+');
	while (pos != nullptr)
	{
		// перенесемо в результат все, що було перед '+'
		strncat(b, prevPos, pos - prevPos);
		// виконаємо заміну
		strcat(b, "plus");

		// запам'ятаємо початок нового пошуку
		prevPos = ++pos;
		// знайдемо наступний '+'
		pos = strchr(pos, '+');
	}
	// допишемо "хвіст"
	strcat(b, prevPos);
	// дивимось на результат
	cout << b << endl;
	delete[] b;
	system("pause");

	// замінити в заданому рядку всі підрядки "minus" на символ '-'
	const char * c = " 5 minus (minus2) = 7";
	cout << c << endl;
	size_t lc = strlen(c + 1);
	// місце під новий рядок виділимо з запасом - зате зекономимо на обчисленнях
	b = new char[lc];
	b[0] = '\0';
	const char * m = "minus";
	size_t lm = strlen(m);
	// запам'ятаємо початок пошуку
	const char * r = c;
	// знайдемо перший "minus"
	const char * p = strstr(c, m);
	while (p != nullptr)
	{
		// перенесемо в результат все, що було перед "minus"
		strncat(b, r, p - r);
		strcat(b, "-");
		// запам'ятаємо початок нового пошуку
		r = p += lm;
		//знайдемо наступний "minus"
		p = strstr(p, m);
	}
	strcat(b, r);
	cout << b << endl;
	system("pause");

	return 0;
}