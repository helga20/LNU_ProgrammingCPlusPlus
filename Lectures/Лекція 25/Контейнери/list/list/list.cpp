#include <iostream>
#include <algorithm>
#include "Windows.h"
#include <list>
#include <functional>
using namespace std;

void print(list<int>& List);

int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);

	const int size = 11;
	int i;

	// ������� ������
	list<int>List;
	list<int>::iterator where;

	// �������� ������ push_back()
	for (i = 0; i < size; i++) List.push_back(i);
	// �������� ������ push_front()
	for (i = 0; i < size; i++) List.push_front(100 - i);
	// ������� ������ �� �����
	cout << "�������� ������: \n";
	print(List);
	system("pause");
	cout << "\n";

	// �������� � ������� � ������ ����� 11
	where = find(List.begin(), List.end(), 10);
	if (where != List.end()) List.erase(where);
	else cout << "������ ����� � ������ �� ���� :( \n";
	cout << "ϳ��� ��������� ����� 10: \n";
	print(List);
	system("pause");
	cout << "\n";

	// ������� ����� � ������� ������
	if (!List.empty())List.pop_front();
	cout << "ϳ��� ��������� ����� � ������� ������\n";
	print(List);
	system("pause");
	cout << "\n";

	// ������� ����� � ���� ������
	if (!List.empty())List.pop_back();
	cout << "ϳ��� ��������� ����� � ���� ������\n";
	print(List);
	system("pause");
	cout << "\n";

	// ������� �� �����, �� ��� 3
	List.remove_if(bind2nd(not_equal_to<int>(), 3));
	cout << "ϳ��� ��������� ��� �����, �� ����� 3\n";
	print(List);
	system("pause");
	cout << "\n";

	// ������� �������������� ����� ������
	int ListMaxSize = List.max_size();
	cout << "������������ ����� ������: " << ListMaxSize << endl;
	// ������� ����� ������
	int ListSize = List.size();
	cout << "����� ������: " << ListSize << endl;
	// ������� ������ ������
	int ListCapacity = List.size();
	cout << "������ ������: " << ListCapacity << endl;
	system("pause");
	cout << "\n";

	// �������� � ������� ������ 6 �����
	List.insert(List.begin(), 6, 8);
	cout << "ϳ��� ������� ����� ����� � ������� ������\n";
	print(List);
	system("pause");
	cout << "\n";

	// ���������� ������
	List.sort();
	cout << "ϳ��� ����������: \n";
	print(List);
	system("pause");
	cout << "\n";

	// ������� ������� �������
	cout << "ϳ��� ��������� ���������� ��������\n";
	List.pop_back();
	print(List);
	system("pause");
	cout << "\n";

	// ������� ����� ������, ����� � ����� ���� ������ List
	list<int>newList(List.begin(), List.end());
	cout << "����� ������: \n";
	print(newList);
	system("pause");
	cout << "\n";

	// �������� ����� ������ 5
	newList.insert(newList.begin(), newList.size(), 5);
	cout << "ϳ��� ���������� ������ ������ �'�������\n";
	print(newList);
	system("pause");
	cout << "\n";

	// ������� � ����� ������ ���� ������ List
	newList.assign(List.begin(), List.end());
	cout << "ϳ��� ��������� ������ List: \n";
	print(newList);
	system("pause");
	cout << "\n";

	// ������ ����� ������
	newList.clear();
	cout << "������ ������� ������� ������\n";
	print(newList);
	system("pause");
	cout << "\n";

	// ��������
	for (i = 0; i < size; i++)
	{
		if (i < 5) newList.push_back(40); else newList.push_back(50);
	}
	cout << "������ � ����������: \n";
	print(newList);
	newList.unique();
	cout << "������ ��� ��������: \n";
	print(newList);
	system("pause");
	cout << "\n";

	// ��'������� ������
	newList.merge(List);
	cout << "ϳ��� ��'������� ������: \n";
	print(newList);
	system("pause");
	cout << "\n";

	// ��������� ������
	if (List == newList) cout << "������ == ����� ������\n";
	if (List > newList) cout << "������ > ����� ������\n";
	if (List >= newList) cout << "������ >= ����� ������\n";
	if (List < newList) cout << "������ < ����� ������\n";
	if (List <= newList) cout << "������ <= ����� ������\n";

	system("pause");
	return 0;
}
void print(list<int>& List)
{
	if (List.empty())
	{
		cout << "\n������ �������\n";
		return;
	}

	list<int>::iterator iter;
	for (iter = List.begin(); iter != List.end(); iter++)
		cout << " " << *iter;
	cout << "\n";
}