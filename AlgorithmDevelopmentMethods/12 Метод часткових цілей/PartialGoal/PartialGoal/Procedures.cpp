#include "Procedures.h"
#include <string>
#include <stack>
#include <stdexcept>
#include <sstream>

using std::string;
using std::stack;

// Перетворює прості арифметичні вирази з інфіксної форми до постфіксної
// операндами можуть бути одноцифрові натуральні числа
// операціями - бінарні + - * /
void postfixLight()
{
	stack<char> Stack;
	string source, dest;
	cout << "Операндами можуть бути одноцифрові цілі, операції - бінарні.\n"
		<< "Задайте арифметичний вираз без дужок: ";
	getline(cin, source);
	if (source.empty()) return;
	for (int i = 0; i < source.length(); ++i)
	{ // аналізуємо кожну літеру заданого рядка
		switch (source[i])
		{
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			dest += source[i]; break; // операнд -> результуючий рядок
		case '+': case '-':
			while (!Stack.empty())    // усі знаки операцій зі стека -> в dest
			{
				dest += Stack.top();
				Stack.pop();
			}
			Stack.push(source[i]); break; // новий знак в стек
		case '*': case '/':     // зі стека в dest операції рівного пріоритету
			while (!Stack.empty() && (Stack.top() == '*' || Stack.top() == '/'))
			{
				dest += Stack.top();
				Stack.pop();
			}
			Stack.push(source[i]); break; // новий знак в стек
		default:
			throw std::invalid_argument("Illegal symbol in the source");
		}
	}
	while (!Stack.empty()) // решта операцій до результуючого рядка
	{
		dest += Stack.top();
		Stack.pop();
	}
	cout << "Польський запис: " << dest << '\n';
}

// обчислення пріоритету операцій
int priority(char c)
{
	switch (c)
	{
	case '*': case '/': return 2;
	case '+': case '-': return 1;
	case '#': case '(': case ')': return 0;
	default: return 10;
	}
}

string toPostfix(string source)
{
	string dest;
	stack<char> Stack; Stack.push('#');
	for (char c : source)
	{   // аналізуємо кожну літеру заданого рядка
		if (isdigit(c))
			dest += c; // операнд -> результуючий рядок
		else
		{
			int p = priority(c);
			switch (c)
			{
			case '+': case '-': case '*': case '/':
				while (priority(Stack.top()) >= p)
				{            // старші операції полишають стек
					dest += Stack.top();
					Stack.pop();
				}
				Stack.push(c); break;
			case '(':        // початок пріоритетної частини
				Stack.push(c); break;
			case ')':        // закінчення пріоритетної частини
				while (Stack.top() != '(')
				{
					dest += Stack.top();
					Stack.pop();
				}            // дужку теж треба забрати
				Stack.pop(); break;
			} /* switch */
		} /* if */
	} /* for */
	while (Stack.top() != '#')
	{   // решта операцій до результуючого рядка
		dest += Stack.top();
		Stack.pop();
	}
	return dest;
}
// Перетворює арифметичні вирази з дужками. Операнди одноцифрові.
void postfix()
{
	string source;
	cout << "Операндами можуть бути одноцифрові цілі, операції - бінарні.\n"
		<< "Задайте арифметичний вираз з довільним вкладенням дужок дужок:\n";
	getline(cin, source);
	if (source.empty()) return;
	cout << "Польський запис: " << toPostfix(source) << '\n';
}

// перевіряє, чи належить символ до запису числа
bool isDigital(char c)
{
	return '0' <= c && c <= '9' || toupper(c) == 'E' || c == '.';
}
// Перетворює арифметичні вирази з багатоцифровими операндами
string translate(string source)
{
	// перетворимо знаки унарних операцій у рядку source
	//  спочатку - на початку рядка:
	if (source[0] == '-') source = '0' + source;  // мінус став бінарним
	else if (source[0] == '+') source.erase(0, 1);// вилучили унарний плюс
	//  потім - після кожної дужки (; перетворення такі ж
	int i = 1;
	while (i < source.length())
	{
		if (source[i - 1] == '(')
		{
			if (source[i] == '-')
			{
				source.insert(i, "0"); ++i;
			}
			else if (source[i] == '+') source.erase(i, 1);
		}
		++i;
	}
	// приготували місце для перетвореного виразу
	std::ostringstream dest;
	stack<char> Stack; Stack.push('#');
	// аналізуємо кожну літеру заданого рядка
	for (int i = 0; i < source.length(); )
	{
		if (isDigital(source[i]))
		{
			while (i < source.length() && isDigital(source[i])) dest << source[i++];
			dest << ' ';  // завершили операнд
		}
		else
		{
			char c = source[i];
			switch (c)
			{
			case '+': case '-': case '*': case '/':
			{
				int p = priority(c);
				while (priority(Stack.top()) >= p)
				{            // старші операції полишають стек
					dest << Stack.top();
					Stack.pop();
				}
				Stack.push(c); break;
			}
			case '(':        // початок пріоритетної частини
				Stack.push(c); break;
			case ')':        // закінчення пріоритетної частини
				while (Stack.top() != '(')
				{
					dest << Stack.top();
					Stack.pop();
				}            // дужку теж треба забрати
				Stack.pop(); break;
			default:
				throw std::invalid_argument("Illegal symbol in the source");
			} /* switch */
			++i;
		} /* if */
	} /* for */
	while (Stack.top() != '#')
	{   // решта операцій до результуючого рядка
		dest << Stack.top();
		Stack.pop();
	}
	return dest.str();
}

void postfixExt()
{
	string source;
	cout << "Задайте арифметичний вираз: ";
	getline(cin, source);
	if (source.empty()) return;
	try
	{
		cout << "Польський запис: " << translate(source) << '\n';
	}
	catch (std::invalid_argument& exc)
	{
		cout << exc.what() << '\n';
	}
}

int Calculate(string expr)
{
	stack<int> Stack;
	for (char c: expr)
	{
		if (isdigit(c))
		{
			Stack.push(c - '0');
		}
		else
		{
			int right = Stack.top(); Stack.pop();
			int left = Stack.top(); Stack.pop();
			switch (c)
			{
			case '+': Stack.push(left + right); break;
			case '-': Stack.push(left - right); break;
			case '*': Stack.push(left * right); break;
			case '/': Stack.push(left / right); break;
			}
		}
	}
	return Stack.top();
}

// Перетворює і обчислює арифметичні вирази з дужками. Операнди одноцифрові.
void translateAndCalculate()
{
	string source, dest;
	cout << "Операндами можуть бути одноцифрові цілі, операції - бінарні.\n"
		<< "Задайте арифметичний вираз з довільним вкладенням дужок дужок:\n";
	getline(cin, source);
	if (source.empty()) return;
	try
	{
		dest = toPostfix(source);
		cout << "Польський запис: " << dest << '\n';
		cout << "Значення = " << Calculate(dest) << "\n\n";
	}
	catch (std::invalid_argument& exc)
	{
		cout << exc.what() << '\n';
	}
}

