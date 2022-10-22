#include "DeelExpr.h"
#include <stack>

using std::stack;

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}

int ToDecValue(char c)
{
	if (isDigit(c))
		return c - '0';
	else
		return 0;
}

int Calculate(const char* expr)
{
	stack<int> stack;
	int res;
	for (unsigned i = 0; expr[i] != '\0'; ++i)
	{
		if (isDigit(expr[i]))
		{
			stack.push(ToDecValue(expr[i]));
		}
		else
		{
			int rha = stack.top();
			stack.pop();
			switch (expr[i])
			{
			case '+': res = stack.top() + rha; break;
			case '-': res = stack.top() - rha; break;
			case '*': res = stack.top() * rha; break;
			case '/': res = stack.top() / rha; break;
			}
			stack.pop(); stack.push(res);
		}
	}
	res = stack.top(); stack.pop();
	return res;
}

int getPriority(char c)
{
	switch (c)
	{
	case '*': case '/': return 2;
	case '+': case '-': return 1;
	case '#': case '(': case ')': return 0;
	default: return 10;
	}
}
bool isOperation(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}
char* Translate(const char* infixExpr)
{
	unsigned len = strlen(infixExpr);
	char* postfixExpr = new char[len + 1];
	unsigned pos = 0;
	stack<char> Stack; Stack.push('#');
	for (unsigned i = 0; i<len; ++i)
	{
		char c = infixExpr[i];
		if (isDigit(c)) postfixExpr[pos++] = c;
		else if (isOperation(c))
		{
			while (getPriority(Stack.top()) >= getPriority(c))
			{
				postfixExpr[pos++] = Stack.top();
				Stack.pop();
			}
			Stack.push(c);
		}
		else if (c == '(') Stack.push(c);
		else /* c == ')' */
		{
			while (Stack.top() != '(')
			{
				postfixExpr[pos++] = Stack.top();
				Stack.pop();
			}
			Stack.pop();
		}
	}
	while (Stack.top() != '#')
	{
		postfixExpr[pos++] = Stack.top();
		Stack.pop();
	}
	Stack.pop();
	postfixExpr[pos] = '\0';
	return postfixExpr;
}