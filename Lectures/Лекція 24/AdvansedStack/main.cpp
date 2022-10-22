#include <iostream>
using std::cout;
#include "eStackPtn.h"
#include "stackHPtn.h"

int main()
{
	// шаблон, унасл≥дуваний в≥д шаблона
	ExtStack<int> s;
	s.push(1); s.push(2);
	cout << "peek result is " << s.peek() << '\n';
	int x = s.pop();
	cout << "pop result is " << x << '\n';
	cout << "peek result is " << s.peek() << '\n';

	// звичайний клас, унасл≥дуваний в≥д конкретизованого шаблона
	StackDbl d;
	d.push(1.23); d.push(4.56); d.push(7.89);
	d.print();
	cout << "  Results of pops:\n";
	while (!d.isEmpty()) cout << '\t' << d.pop();
	cout << '\n';
	d.print();

	// шаблон, що м≥стить екземпл€р ≥ншого шаблона
	int a[] = { 1,2,3,4,5,6,7 };
	HStack<int> h(5);
	int i = 0;
	while (true)
	{
		try
		{
			h.push(a[i]); ++i;
		}
		catch (std::out_of_range& ex)
		{
			cout << ex.what() << '\n';
			cout << "The stack is full at i = " << i << '\n';
			break;
		}
	}
	while (!h.isEmpty()) cout << '\t' << h.pop();
	cout << '\n';
	system("pause");

	// Ўаблон може бути аргументом ≥ншого шаблона
	Array<Array<int>> matr(3, Array<int>(4, 1));
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j) cout << '\t' << matr[i][j];
		cout << '\n';
	}

	Array<Stack<int>> staks(5, Stack<int>());
	for (int i = 0; i < 40; ++i) staks[i % 5].push(i);
	cout << staks[1].pop() << ' ' << staks[4].pop() << '\n';
	Stack<Array<int>> arrays;
	arrays.push(Array<int>(2));
	arrays.push(Array<int>(3, 5));
	cout << arrays.pop()[0] << ' ' << arrays.pop()[0] << '\n';
	system("pause")	;
	return 0;
}