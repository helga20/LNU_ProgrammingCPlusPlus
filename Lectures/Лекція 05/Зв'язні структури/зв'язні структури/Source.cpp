#include <iostream>
using std::cin; using std::cout;
struct section // ланка списку
{
	int elem;
	section* link;
};
int main()
{
	// List Ц голова списку, b Ц робоча зм≥нна
	section* List;
	section* b;
	// створенн€ списку List
	int n;
	cout << "Enter n: "; cin >> n;
	List = new section; List->elem = 0; // створили першу ланку
	b = List;
	for (int i = 1; i <= n; i++)
	{
		b->link = new section; // та вс≥ ≥нш≥ ланки
		b = b->link; // дл€ доступу до пол≥в структури
		b->elem = i; // всюди використовуЇмо оператор ->
	}
	b->link = nullptr; // список зак≥нчуЇтьс€ порожн≥м вказ≥вником
	 // виведенн€ елемент≥в списку List
	cout << "List: ";
	b = List; // вказ≥вник b - дл€ перебиранн€ ланок
	while (b) // поки Ї продовженн€
	{
		cout << '\t' << b->elem; // друкуЇмо число
		b = b->link; // беремо наступну ланку
	}
	cout << '\n';
	// знищенн€ ланок списку List
	while (List)
	{
		b = List;
		List = List->link;
		delete b;
	}
	cout << "Done\n";
	system("pause");
	return 0;
}