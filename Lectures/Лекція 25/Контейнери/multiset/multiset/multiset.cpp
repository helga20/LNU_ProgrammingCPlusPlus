#include <iostream>
#include <set>
#include <Windows.h>
using namespace std;

void print(multiset<int, less<int> >& Multiset);
void reverse_print(multiset<int, less<int> >& Multiset);

int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);

	const int size = 5;
	int i;

	multiset<int, less<int> >::iterator where, newWhere;
	// ������� �������
	multiset<int, less<int> > Multiset, newMultiset;
	// �������� ������� insert()
	for (i = 0; i < size; i++)
	{
		Multiset.insert(i);
		newMultiset.insert(i + 1);
	}
	cout<< "�������: \n";
	print(Multiset);
	cout << "���� �������: \n";
	print(newMultiset);
	system("pause");
	cout << "\n";

	// ������� ������� � ���������� �������
	cout << "������� � ���������� �������: \n";
	reverse_print(Multiset);
	cout << "���� ������� � ���������� �������: \n";
	reverse_print(newMultiset);
	system("pause");
	cout << "\n";

	// ������� ������ ������
	int MultisetSize = Multiset.size();
	cout << "����� �������: \n" << MultisetSize << endl;
	MultisetSize = newMultiset.size();
	cout << "����� ���� �������: \n" << MultisetSize << endl;
	system("pause");
	cout << "\n";

	// ������� ���������� ������ ������
	MultisetSize = Multiset.max_size();
	cout << "������������ ����� �������: \n" << MultisetSize << endl;
	MultisetSize = newMultiset.max_size();
	cout << "������������ ����� ���� �������: \n" << MultisetSize << endl;
	system("pause");
	cout << "\n";

	// ������� ������� �����
	MultisetSize = Multiset.count(3);
	cout << "ʳ������ ����� � ������: \n" << MultisetSize << endl;
	MultisetSize = newMultiset.count(3);
	cout << "ʳ������ ����� � ���� �������: \n" << MultisetSize << endl;
	system("pause");
	cout << "\n";

	// ����� � ������� ����� � ������
	where = Multiset.find(3);
	Multiset.erase(where);
	cout << "������� ���� ��������� �����: \n";
	print(Multiset);
	system("pause");
	cout << "\n";

	// ������� ��� ������ �������� �������
	where = Multiset.find(2);
	Multiset.erase(where, Multiset.end());
	cout << "������� ���� ��������� ���� ������� ��������: \n";
	print(Multiset);
	system("pause");
	cout << "\n";

	// "����" ������� clear()
	Multiset.clear();
	cout << "������ ������� ������� �������\n";
	print(Multiset);
	system("pause");
	cout << "\n";

	// �������� ������� insert()
	for (i = 0; i < size; i++)
	{
		if (i < 2) Multiset.insert(5); else Multiset.insert(10);
	}
	cout << "���� �������: \n";
	print(Multiset);
	system("pause");
	cout << "\n";

	// ������������ ������
	swap(Multiset, newMultiset);
	cout << "������� ���� ������������: \n";
	print(Multiset);
	cout << "���� ������� ���� ������������: \n";
	print(newMultiset);
	system("pause");
	cout << "\n";

	// �������, �� ���������� � �������
	cout << "ĳ������, �� ���������� � �������: \n";
	for (where = newMultiset.lower_bound(10);
		where != newMultiset.end();
		where++)
		cout << " " << *where;
		cout << "\n";
	system("pause");
	cout << "\n";

	// �������, �� ���������� � �'�����
	cout << "ĳ������, �� ���������� � �'�����: \n";
	for (where = newMultiset.begin();
		where != newMultiset.upper_bound(5);
		where++)
		cout << " " << *where;
		cout << "\n";
	system("pause");
	cout << "\n";

	// ��������� ������
	if (Multiset == newMultiset) cout << "������� == ���� �������\n";
	if (Multiset > newMultiset) cout << "������� > ���� �������\n";
	if (Multiset >= newMultiset) cout << "������� >= ���� �������\n";
	if (Multiset < newMultiset) cout << "������� < ���� �������\n";
	if (Multiset <= newMultiset) cout << "������� <= ���� �������\n";

	system("pause");
	return 0;
}

void print(multiset<int, less<int> >& Multiset)
{
	if (Multiset.empty())
	{
		cout << "������� �������\n";	return;
	}
	multiset<int, less<int> >::iterator i;
	for (i = Multiset.begin(); i != Multiset.end(); i++)
	cout << " " << *i;
	cout << "\n";
}
void reverse_print(multiset<int, less<int> >& Multiset)
{
	if (Multiset.empty())
	{
		cout << "������� �������\n";	return;
	}
	multiset<int, less<int> >::reverse_iterator i;
	for (i = Multiset.rbegin(); i != Multiset.rend(); i++)
	cout << " " << *i;
	cout << "\n";
}