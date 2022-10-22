#include "intProcedures.h"
#include <cmath>

void binaryForm()
{
	cout << "\n *Переведення числа у двійкову систему*\n\n";
	unsigned n;
	cout << "Введіть натуральне число: "; cin >> n;
	long long s = 0; // двійковий запис спочатку порожній
	long long p = 1; // p=10^0
	while (n > 0)
	{
		s += (n % 2) * p; // остачу помістили в двійковий запис
		n /= 2;			  // частку треба ще перевести
		p *= 10;		  // підготували степінь 10 для наступної цифри
	}
	cout << "Запис у двійковій системі: " << s << '\n';
	return;
}

void binaryFormStr()
{
	using std::log;
	cout << "\n *Побудова запису числа у двійковій системі*\n\n";
	unsigned n;
	cout << "Введіть натуральне число: "; cin >> n;
	// готуємо місце для двійкового запису
	int k = log(double(n)) / log(2.0) + 1;
	char * str = new char[k + 1]; str[k] = '\0';
	while (n > 0)
	{
		--k;
		if (n % 2) str[k] = '1'; // остання двійкова цифра непарного числа - 1
		else str[k] = '0';	     // наприкінці парного - двійковий 0
		n /= 2;
	}
	cout << "Запис у двійковій системі: " << str << '\n';
	delete[] str;
	return;
}

void hexaFormStr()
{
	using std::log;
	cout << "\n *Побудова запису числа у шістнадцятковій системі*\n\n";
	unsigned n, m;
	cout << "Введіть натуральне число: "; cin >> n; m = n;
	// готуємо місце для шістнадцяткового запису
	int k = log(double(n)) / log(16.0) + 1;
	char * str = new char[k + 1]; str[k] = '\0';
	while (n > 0)
	{
		--k;
		unsigned c = n % 16;		  // остання шістадцяткова цифра числа
		if (c < 10) str[k] = '0' + c; // звичайні цифри
		else str[k] = 'A' - 10 + c;   // старші цифри-букви
		n /= 16;
	}
	cout << "Запис " << m << " у шістнадцятковій системі: " << str << '\n';
	delete[] str;
	cout.setf(std::ios_base::hex, std::ios_base::basefield);
	cout << "Те саме засобами компілятора: " << m << '\n';
	return;
}