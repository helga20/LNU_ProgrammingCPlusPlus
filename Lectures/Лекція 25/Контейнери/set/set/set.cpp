#include <iostream>
#include <set>
#include <Windows.h>
using namespace std;

void print(set<int, less<int> >& Set);
void reverse_print(set<int, less<int> >& Set);

int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);

	const int size = 5;
	int i;

	set<int, less<int> >::iterator where, newWhere;

	// ������� �������
	set<int, less<int> > Set, newSet;
	// �������� ������� insert()
	for (i = 0; i < size; i++)
	{
		Set.insert(i);
		newSet.insert(i + 1);
	}
	cout << "�������\n";
	print(Set);
	cout << "���� �������\n";
	print(newSet);
	system("pause");
	cout << "\n";

	// ������� ������� � ���������� �������
	cout << "������� � ���������� �������\n";
	reverse_print(Set);
	cout << "���� �������t � ���������� �������\n";
	reverse_print(newSet);
	system("pause");
	cout << "\n";

	// ������� ������ ������
	int SetSize = Set.size();
	cout << "����� �������: " << SetSize << endl;
	SetSize = newSet.size();
	cout << "����� ���� �������: " << SetSize << endl;
	system("pause");
	cout << "\n";

	// ������� ���������� ������ ������
	SetSize = Set.max_size();
	cout << "������������ ����� �������: " << SetSize << endl;
	SetSize = newSet.max_size();
	cout << "������������ ����� ���� �������: " << SetSize << endl;
	system("pause");
	cout << "\n";

	// ������� ������� �����
	SetSize = Set.count(3);
	cout << "ʳ������ ����� � �������: " << SetSize << endl;
	SetSize = newSet.count(5);
	cout << "ʳ������ ����� � ���� �������: " << SetSize << endl;
	system("pause");
	cout << "\n";

	// ����� � ������� ����� � �������
	where = Set.find(3);
	Set.erase(where);
	cout << "������� ���� ��������� �����: \n";
	print(Set);
	system("pause");
	cout << "\n";

	// ������� ��� ������� �������� ������� 
	where = Set.find(2);
	Set.erase(where, Set.end());
	cout << "������� ���� ��������� ���� ������� ��������: \n";
	print(Set);
	system("pause");
	cout << "\n";

	// ������ ������� clear()
	Set.clear();
	cout << "������ ������� ������� �������\n";
	print(Set);
	system("pause");
	cout << "\n";

	// �������� ������� insert().
	for (i = 0; i < size; i++)
	{
		if (i < 2) Set.insert(5); else Set.insert(10);
	}
	cout << "���� �������: \n";
	print(Set);
	system("pause");
	cout << "\n";

	// ������������ ������
	swap(Set, newSet);
	cout << "������� ���� ������������\n";
	print(Set);
	cout << "���� ������� ���� ������������\n";
	print(newSet);
	system("pause");
	cout << "\n";

	// ��������� ������
	if (Set == newSet) cout << "������� == ���� �������\n";
	if (Set > newSet) cout << "������� > ���� �������\n";
	if (Set >= newSet) cout << "������� >= ���� �������\n";
	if (Set < newSet) cout << "������� < ���� �������\n";
	if (Set <= newSet) cout << "������� <= ���� �������\n";

	system("pause");
	return 0;
}
void print(set<int, less<int> >& Set)
{
	if (Set.empty())
	{
		cout << "������� �������\n";	return;
	}
	set<int, less<int> >::iterator i;
	for (i = Set.begin(); i != Set.end(); i++)
	cout << " " << *i;
	cout << "\n";
}
void reverse_print(set<int, less<int> >& Set)
{
	if (Set.empty())
	{
		cout << "������� �������\n";	return;
	}
	set<int, less<int> >::reverse_iterator i;
	for (i = Set.rbegin(); i != Set.rend(); i++)
	cout << " " << *i;
	cout << "\n";
}