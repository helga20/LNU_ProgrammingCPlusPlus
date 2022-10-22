#include <iostream>
#include "Array.h"
#include "InOutOperators.h"
#include "DblList.h"
#include "Stack.h"

using namespace std;

void Stacks();

int main()
{
	Stacks();
	system("pause");
	return 0;
}

template <typename Cont>
void printOut(const Cont& C)
{
	for (size_t i = 0; i < C.size(); ++i)
		std::cout << ' ' << C[i];
	std::cout << '\n';
}

void Stacks()
{
	Stack<int> S;
	if (S.isEmpty()) cout << "Stack is empty\n";
	else cout << "Stack contains something\n";
	S.push(5);
	if (S.isEmpty()) cout << "Stack is empty\n";
	else cout << "Stack contains something: " << S.peek() << '\n';
	cin.get();
	const int n = 4;
	int a[n] = { 1, 2, 3 };
	for (int i = 0; i < n; ++i)
	{
		S.push(a[i]);
		cout << '\t' << a[i];
	}
	cout << '\n' << S.peek() << '\n';
	cin.get();
	S.peek() = n;
	while (!S.isEmpty())
		cout << '\t' << S.pop();
	cout << '\n';
	cin.get();

	Stack<int, Array> T;
	if (T.isEmpty()) cout << "Stack is empty\n";
	else cout << "Stack contains something\n";
	T.push(5);
	if (T.isEmpty()) cout << "Stack is empty\n";
	else cout << "Stack contains something: " << T.peek() << '\n';
	cin.get();
	for (int i = 0; i < n; ++i)
	{
		T.push(a[i]);
		cout << '\t' << a[i];
	}
	cout << '\n' << T.peek() << '\n';
	cin.get();
	T.peek() = n;
	while (!T.isEmpty())
		cout << '\t' << T.pop();
	cout << '\n';
	cin.get();
}