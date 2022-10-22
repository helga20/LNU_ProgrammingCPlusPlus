#include "processProcedures.h"
#include <string>
#include <sstream>

void stringToNumber()
{
	cout << "\n *Перетворення рядка - масиву літер та рядка-контейнера - на число*\n";

	cout << "\n-Рядок в стилі С-\n";
	const unsigned size = 256;  // потрібно задати розмір масиву літер
	char line[size] = { '\0' }; // масив ініціалізуємо літерами з кодом 0
	cout << "Введіть послідовність літер, що містить цифри:\n";
	cin.getline(line, size);        // введений рядок обмежений розміром масиву

	cout << "\n   Перетворення власною функцією\n";
	int ErrCode;
	int k = recognizeInteger(line, ErrCode);
	if (ErrCode == -1)
		cout << "Введене число: " << k << '\n';
	else
		cout << "Рядок містить помилку в позиції " << ErrCode
		<< " Вдалося прочитати " << k << '\n';

	cout << "\n   Перетворення стандартною функцією\n";
	k = std::atoi(line);
	if (errno == ERANGE) cout << "Error: Сталося переповнення\n";
	cout << "Введене число: " << k << "  Код помилки " << errno << '\n';
	errno = 0;

	cout << "\n   Використання потоку, накладеного на рядок\n";
	std::string Line(line);
	std::istringstream stream(Line);
	stream >> k;                // перетворення виконує оператор введення
	cout << "Введене число: " << k << '\n';
	return;
}

void intSuccession()
{
	cout << "\n *Обчислення суми цілих чисел, записаних у рядку*\n";
	char* succ = "25 -32 777 12 -98 -5 2018";
	cout << "Задана послідовність:\n" << succ << '\n';
	int sum = 0;
	int pos = 0;
	cout << "Члени послідовності:\n";
	do
	{
		int k = recognizeInteger(succ += pos, pos);
		cout << k << '\n';
		sum += k;
	} while (pos != -1);
	cout << " Summ = " << sum << '\n';
}

int recognizeInteger(const char* line, int& Pos)
{
	const int max = INT_MAX / 10;
	const char* curr = line;
	int result = 0;                  // число, яке треба сформувати
	Pos = -1;
	while (*curr == ' ' || *curr == '\t') ++curr;  // пропускаємо пропуски
	bool sign = false;               // sign пам'ятає про наявність мінуса
	if (*curr == '+') ++curr;        // плюс можна пропустити,
	if (*curr == '-')                // а мінус треба запам'ятати
	{
		sign = true;
		++curr;
	}
	while (*curr != '\0')            // переглядаємо весь рядок
	{
		if (*curr >= '0' && *curr <= '9')
		{                            // знайдену цифру перетворюємо на число
			int k = *curr - '0';     // чи не загрожує переповнення?
			if (max < result || max == result && k > 7)
			{                        // якщо так, то перериваємо обчислення
				Pos = curr - line;
				break;
			}
			result = result * 10 + k;// додаємо нову цифру до результату
			++curr;
		}
		else
		{                            // фіксуємо позицію нечислового символа
			Pos = curr - line;
			break;
		}
	}
	return sign ? -result : result;
}