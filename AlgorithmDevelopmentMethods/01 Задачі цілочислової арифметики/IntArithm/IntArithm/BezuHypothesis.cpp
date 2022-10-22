#include "intProcedures.h"

void BezuHypothesis()
{
	cout << "\n *Перевірка гіпотези Безу*\n\n";
	unsigned a, b, l;
	cout << "Введіть дані a,b,l: ";
	cin >> a >> b >> l;
	// параметр циклу перебиратиме числа заданого діапазону
	for (unsigned n = a; n <= b; ++n)
	{
		unsigned k = 0;  // лічильник внутрішнього циклу
		long long m = n; // на першому кроці циклу - копія n,
						 // на наступних - сума прямого і оберненого запису
		long long s = 0; // обернений запис числа m
		do
		{
			m += s;
			s = reverse(m);
			++k;
		}
		while (s != m && k <= l);
		// результати перевірки
		std::cout << "Для числа " << n << " за " << k - 1 << " крок(и) ";
		if (k > l) cout << "гіпотеза не виконується\n";
		else cout << "отримано паліндром " << s << '\n';
	}
	return;
}

// функція побудови зворотнього запису числа
long long reverse(long long m)
{
	long long s = 0;
	while (m > 0)
	{
		s = s * 10 + m % 10;
		m /= 10;
	}
	return s;
}