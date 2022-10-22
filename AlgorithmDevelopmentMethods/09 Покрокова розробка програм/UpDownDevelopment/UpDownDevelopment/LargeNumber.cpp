#include "LargeNumber.h"

// процедура подвоєння великого числа
void multByTwo(largeNumber& x)
{
	char calc;                        // результат проміжних обчислень
	char transfer = 0;                // перенесення до старшого розряду
	for (int i = 0; i <= x.last; ++i) // переглядаємо всі цифри великого числа
	{
		calc = x.digits[i] * 2 + transfer;
		x.digits[i] = calc % 10;      // молодшу цифру добутку записуємо
		transfer = calc / 10;         // старшу - переносимо
	}
	if (transfer > 0)                 // запис числа стає довшим
		x.digits[++x.last] = transfer;
}

// процедура виведення великого числа
void print(const largeNumber& x)
{
	for (int i = x.last; i >= 0; --i) cout << (int)x.digits[i];
	cout << '\n';
}

// програма піднесення 2 до степеня n, 1<=n<=1000
void powerLast()
{
	cout << "* Обчислення великого степеня числа 2 *\n\n";
	int n;
	cout << "Введіть n (n<=1000): "; cin >> n;
	largeNumber x; // велике число х
	// обчислити 2^n в змінній x
	//     велике_число_x = 1;
	x.last = 0;
	x.digits[0] = 1;  // x = 2^0

	for (int k = 1; k <= n; ++k)
	{
		// подвоїти_велике_число(x);
		multByTwo(x); // x = 2^k
	}
	// x = 2^n
	cout << "2 в степені " << n << " = ";
	//надрукувати_велике_число(x);
	print(x);
}

/* ==================================================================================== */

// процедура звільнення динамічної пам'яті
void eraseList(NumNode*& x)
{
	while (x != nullptr)
	{
		NumNode* victim = x;
		x = x->link;
		delete victim;
	}
}
// процедура подвоєння великого числа
void multByTwo(NumNode* x)
{
	unsigned short calc;
	unsigned short transfer = 0;
	x = new NumNode(0, x);       // заголовна ланка потрібна для правильного адресування
	NumNode* curr = x;
	while (curr->link != nullptr)
	{
		calc = curr->link->num * 2 + transfer;
		if (calc < 10000)
		{                        // всі 4 цифри поміщаються в одній ланці
			transfer = 0;
			curr->link->num = calc;
		}
		else
		{                        // є перенесення в наступну ланку
			transfer = 1;
			curr->link->num = calc % 10000;
		}
		curr = curr->link;
	}
	// Нова ланка, якщо число стало довшим
	if (transfer > 0) curr->link = new NumNode(1);
	// Заголовна ланка більше не потібна
	delete x;
}
// процедура виведення великого числа
void print(const NumNode* x)
{
	// Перед виведенням список треба обернути
	NumNode* reverse = nullptr;
	while (x != nullptr)
	{
		reverse = new NumNode(x->num, reverse);
		x = x->link;
	}
	x = reverse;
	cout << x->num; // друк старшої "цифри" без ведучих нулів
	x = x->link;
	char empt = cout.fill('0');
	while (x != nullptr) // решту "цифр" друкуємо по чотири і з нулями
	{
		cout.width(4);
		cout << x->num;
		x = x->link;
	}
	cout << '\n';
	cout.fill(empt); // повертаємо заповнювач за замовчуванням
	eraseList(reverse); // обернутий список більше не потрібен
}
// програма піднесення 2 до степеня n
void powerList()
{
	cout << "* Обчислення великого степеня числа 2 *\n\n";
	int n;
	cout << "Введіть n: "; cin >> n;
	NumNode* x; // велике число х
	// обчислити 2^n в змінній x
	//     велике_число_x = 1;
	x = new NumNode(1);  // x = 2^0

	for (int k = 1; k <= n; ++k)
	{
		// подвоїти_велике_число(x);
		multByTwo(x); // x = 2^k
	}
	// x = 2^n
	cout << "2 в степені " << n << " = ";
	//надрукувати_велике_число(x);
	print(x);
	eraseList(x);
}

/* ==================================================================================== */

LargePositiveInteger& LargePositiveInteger::operator=(unsigned n)
{
	digits.clear();
	if (n == 0)	digits.push_back(0);
	else
	{
		while (n > 0)
		{
			digits.push_back(n % 10);
			n /= 10;
		}
	}
	return *this;
}
LargePositiveInteger& LargePositiveInteger::multByTwo()
{
	char calc;
	char transfer = 0;
	for (int i = 0; i < digits.size(); ++i)
	{
		calc = digits[i] * 2 + transfer;
		digits[i] = calc % 10;
		transfer = calc / 10;
	}
	if (transfer > 0) digits.push_back(transfer);
	return *this;
}
LargePositiveInteger& LargePositiveInteger::operator*=(unsigned n)
{
	if (n == 0) return *this = 0;
	unsigned calc;
	unsigned transfer = 0;
	for (int i = 0; i < digits.size(); ++i)
	{
		calc = digits[i] * n + transfer;
		digits[i] = calc % 10;
		transfer = calc / 10;
	}
	while (transfer > 0)
	{
		digits.push_back(transfer % 10);
		transfer /= 10;
	}
	return *this;
}
ostream& operator<<(ostream& os, const LargePositiveInteger& L)
{
	for (int i = L.digits.size() - 1; i >= 0; --i) os << (int)L.digits[i];
	os << '\n';
	return os;
}

void powerLastest()
{
	cout << "* Обчислення великого степеня числа 2 *\n\n";
	int n;
	cout << "Введіть n: "; cin >> n;
	LargePositiveInteger x; // велике число х
	// обчислити 2^n в змінній x
	//     велике_число_x = 1;
	x = 1;  // x = 2^0

	for (int k = 1; k <= n; ++k)
	{
		// подвоїти_велике_число(x);
		x *= 2; // x = 2^k
	}
	// x = 2^n
	//надрукувати_велике_число(x);
	cout << "2 в степені " << n << " = " << x;
}
