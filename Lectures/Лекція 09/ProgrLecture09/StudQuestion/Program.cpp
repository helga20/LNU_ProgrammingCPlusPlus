#include "Header.h"

bool check_num(node* L);

int main()
{
	node * L = new node(1, 'D', 23.5, new node(2, 'A', 51.0,
		new node(3, 'F', 99.5, new node(4, 'C', 80))));
	node * p = L;
	while (p != nullptr)
	{
		std::cout << p->val << '\n';
		p = p->link;
	}
	std::cout << '\n';
	// ����� ������ ���� ������� �������, �������� ���������
	show(find(L, check_num));
	// ����� ������ ������ ������-������� � ���������� ���������
	show(find(L, [](node*q){ return q->val.num == 3; }));
	// ����� ������ ������-�������, �� ����������� �������� �����,
	// ����� ��� ����� ���������� ��� �������� ��� ������
	static int x = 2;
	show(find(L, [](node*q){ return q->val.num == x; }));
	// ������ ��� ������� �� ����� ����
	show(find(L, [](node*q){ return q->val.letter == 'D'; }));
	show(find(L, [](node*q){ return q->val.point > 50.5; }));

	// ������ ��������� �� ������� ����� ����������� ������ function
	// ��� ����� ��������������� ������-������
	int y = x + 2;
	show(find_f(L, [y](node*q){ return q->val.num == y; }));
	system("pause");
	return 0;
}

bool check_num(node* L)
{
	return L->val.num == 13;
}
