#include <iostream>
using std::cin; using std::cout;
struct section // ����� ������
{
	int elem;
	section* link;
};
int main()
{
	// List � ������ ������, b � ������ �����
	section* List;
	section* b;
	// ��������� ������ List
	int n;
	cout << "Enter n: "; cin >> n;
	List = new section; List->elem = 0; // �������� ����� �����
	b = List;
	for (int i = 1; i <= n; i++)
	{
		b->link = new section; // �� �� ���� �����
		b = b->link; // ��� ������� �� ���� ���������
		b->elem = i; // ����� ������������� �������� ->
	}
	b->link = nullptr; // ������ ���������� ������� ����������
	 // ��������� �������� ������ List
	cout << "List: ";
	b = List; // �������� b - ��� ����������� �����
	while (b) // ���� � �����������
	{
		cout << '\t' << b->elem; // ������� �����
		b = b->link; // ������ �������� �����
	}
	cout << '\n';
	// �������� ����� ������ List
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