#include "Procedures.h"
#include <string>
#include <stack>
#include <stdexcept>
#include <sstream>

using std::string;
using std::stack;

// ���������� ����� ���������� ������ � �������� ����� �� ����������
// ���������� ������ ���� ���������� ��������� �����
// ���������� - ����� + - * /
void postfixLight()
{
	stack<char> Stack;
	string source, dest;
	cout << "���������� ������ ���� ���������� ���, �������� - �����.\n"
		<< "������� ������������ ����� ��� �����: ";
	getline(cin, source);
	if (source.empty()) return;
	for (int i = 0; i < source.length(); ++i)
	{ // �������� ����� ����� �������� �����
		switch (source[i])
		{
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			dest += source[i]; break; // ������� -> ������������ �����
		case '+': case '-':
			while (!Stack.empty())    // �� ����� �������� � ����� -> � dest
			{
				dest += Stack.top();
				Stack.pop();
			}
			Stack.push(source[i]); break; // ����� ���� � ����
		case '*': case '/':     // � ����� � dest �������� ������ ���������
			while (!Stack.empty() && (Stack.top() == '*' || Stack.top() == '/'))
			{
				dest += Stack.top();
				Stack.pop();
			}
			Stack.push(source[i]); break; // ����� ���� � ����
		default:
			throw std::invalid_argument("Illegal symbol in the source");
		}
	}
	while (!Stack.empty()) // ����� �������� �� ������������� �����
	{
		dest += Stack.top();
		Stack.pop();
	}
	cout << "��������� �����: " << dest << '\n';
}

// ���������� ��������� ��������
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
	{   // �������� ����� ����� �������� �����
		if (isdigit(c))
			dest += c; // ������� -> ������������ �����
		else
		{
			int p = priority(c);
			switch (c)
			{
			case '+': case '-': case '*': case '/':
				while (priority(Stack.top()) >= p)
				{            // ������ �������� ��������� ����
					dest += Stack.top();
					Stack.pop();
				}
				Stack.push(c); break;
			case '(':        // ������� ���������� �������
				Stack.push(c); break;
			case ')':        // ��������� ���������� �������
				while (Stack.top() != '(')
				{
					dest += Stack.top();
					Stack.pop();
				}            // ����� ��� ����� �������
				Stack.pop(); break;
			} /* switch */
		} /* if */
	} /* for */
	while (Stack.top() != '#')
	{   // ����� �������� �� ������������� �����
		dest += Stack.top();
		Stack.pop();
	}
	return dest;
}
// ���������� ���������� ������ � �������. �������� ����������.
void postfix()
{
	string source;
	cout << "���������� ������ ���� ���������� ���, �������� - �����.\n"
		<< "������� ������������ ����� � �������� ���������� ����� �����:\n";
	getline(cin, source);
	if (source.empty()) return;
	cout << "��������� �����: " << toPostfix(source) << '\n';
}

// ��������, �� �������� ������ �� ������ �����
bool isDigital(char c)
{
	return '0' <= c && c <= '9' || toupper(c) == 'E' || c == '.';
}
// ���������� ���������� ������ � ��������������� ����������
string translate(string source)
{
	// ����������� ����� ������� �������� � ����� source
	//  �������� - �� ������� �����:
	if (source[0] == '-') source = '0' + source;  // ���� ���� �������
	else if (source[0] == '+') source.erase(0, 1);// �������� ������� ����
	//  ���� - ���� ����� ����� (; ������������ ��� �
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
	// ����������� ���� ��� ������������� ������
	std::ostringstream dest;
	stack<char> Stack; Stack.push('#');
	// �������� ����� ����� �������� �����
	for (int i = 0; i < source.length(); )
	{
		if (isDigital(source[i]))
		{
			while (i < source.length() && isDigital(source[i])) dest << source[i++];
			dest << ' ';  // ��������� �������
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
				{            // ������ �������� ��������� ����
					dest << Stack.top();
					Stack.pop();
				}
				Stack.push(c); break;
			}
			case '(':        // ������� ���������� �������
				Stack.push(c); break;
			case ')':        // ��������� ���������� �������
				while (Stack.top() != '(')
				{
					dest << Stack.top();
					Stack.pop();
				}            // ����� ��� ����� �������
				Stack.pop(); break;
			default:
				throw std::invalid_argument("Illegal symbol in the source");
			} /* switch */
			++i;
		} /* if */
	} /* for */
	while (Stack.top() != '#')
	{   // ����� �������� �� ������������� �����
		dest << Stack.top();
		Stack.pop();
	}
	return dest.str();
}

void postfixExt()
{
	string source;
	cout << "������� ������������ �����: ";
	getline(cin, source);
	if (source.empty()) return;
	try
	{
		cout << "��������� �����: " << translate(source) << '\n';
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

// ���������� � �������� ���������� ������ � �������. �������� ����������.
void translateAndCalculate()
{
	string source, dest;
	cout << "���������� ������ ���� ���������� ���, �������� - �����.\n"
		<< "������� ������������ ����� � �������� ���������� ����� �����:\n";
	getline(cin, source);
	if (source.empty()) return;
	try
	{
		dest = toPostfix(source);
		cout << "��������� �����: " << dest << '\n';
		cout << "�������� = " << Calculate(dest) << "\n\n";
	}
	catch (std::invalid_argument& exc)
	{
		cout << exc.what() << '\n';
	}
}

