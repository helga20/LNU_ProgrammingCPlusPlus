#include "ListTools.h"
#include <iostream>
using std::cin;
using std::cout;

namespace ListTools
{
	List_t readList()
	{
		// ����� ��������� ����� ���������� � ����� ������
		List_t L = nullptr;
		cout << "Input a succession of integers terminated by 'stop':\n";
		int x;
		cin >> x;
		// ����� ����� ��������, �� �� �� ����� ������ ������
		// �� ��������� ������
		L = new Node(x);
		// ��������� �������� �� ������� �����
		Node* p = L;
		// ���� ��� ����� ����� � �����
		while (cin >> x)
		{
			p->link = new Node(x);
			p = p->link;
		}
		// ���������� ����� ������ ��������
		cin.clear();
		while (cin.get() != '\n') continue;
		return L;
	}

	void writeList(List_t L)
	{
		if (L == nullptr)
		{
			cout << "The list is empty\n";
			return;
		}
		// �������� ����� L �������� �� ����� ������
		while (L != nullptr)
		{
			cout << '\t' << L->value;
			L = L->link;
		}
		cout << '\n';
	}
	List_t shortList()
	{
		// "����������" ������ � ����� �����
		return new Node(32, new Node(45, new Node(95)));
	}
	List_t reverseReadList()
	{
		// ����� ����� ������������ �� ������� ������
		cout << "Input a succession of integers terminated by 'stop':\n";
		int x;
		List_t L = nullptr;
		while (cin >> x)
		{
			L = new Node(x, L);
		}
		cin.clear();
		while (cin.get() != '\n') continue;
		return L;
	}
	// ���������� ��������� ������������ ����� � ���������� ������� �� ������
	// ��� ��������� ������ ����� �������� L = nullptr;
	void recursiveReadList(List_t& L)
	{
		int x;
		if (cin >> x) L = new Node(x, L);
		else
		{
			cin.clear();
			while (cin.get() != '\n') continue;
			return;
		}
	}

	int delFirst(List_t& L)
	{
		// ������ � ������ ����� �����, ������� ��������, ��� � �� ����������
		int x = L->value;
		Node* victim = L;
		L = L->link;
		delete victim;
		return x;
	}
	void removeList(List_t& List)
	{
		// ������ � �������� ���'�� ���� ������
		while (List != nullptr)
			delFirst(List);
	}
	List_t readSortedList()
	{
		// ��������� ��������� �����
		List_t L = new Node(0);
		// ���� �������� �����
		cout << "Input a succession of integers terminated by 'stop':\n";
		int x;
		while (cin >> x)
		{
			// ����� ���� �������
			Node* place = L;
			while (place->link != nullptr && place->link->value < x) place = place->link;
			// ������� ������ ��������
			place->link = new Node(x, place->link);
		}
		// ��������� ��������� �����
		delFirst(L);
		// ���������� � �������� ������ ��������
		cin.clear();
		while (cin.get() != '\n') continue;
		return L;
	}
	List_t readSortedLst()
	{
		// ����� - ������ ������
		Node L(0);
		// ���� �������� �����
		cout << "Input a succession of integers terminated by 'stop':\n";
		int x;
		while (cin >> x)
		{
			// ����� ���� �������
			Node* place = &L;
			while (place->link != nullptr && place->link->value < x) place = place->link;
			// ������� ������ ��������
			place->link = new Node(x, place->link);
		}
		// ���������� � �������� ������ ��������
		cin.clear();
		while (cin.get() != '\n') continue;
		return L.link;
	}

	List_t merge(List_t a, List_t b)
	{
		// �������� �����, ��� ����� ����� ���������� �� ���� "���������"
		Node phantom(0);
		List_t r = &phantom;
		while (a != nullptr && b != nullptr)
		{
			// �� ������������� ������ ������ ��������� ������
			if (a->value < b->value)
			{
				r->link = new Node(a->value);
				a = a->link;
			}
			else
			{
				r->link = new Node(b->value);
				b = b->link;
			}
			r = r->link;
		}
		// �������� "������"
		while (a != nullptr)
		{
			r->link = new Node(a->value);
			a = a->link;
			r = r->link;
		}
		while (b != nullptr)
		{
			r->link = new Node(b->value);
			b = b->link;
			r = r->link;
		}
		return phantom.link;
	}
}

void ListTools::insert(int x, List_t& L)
{
	Node phantom(0, L);
	// ����� ������ ������ ������ �������� �� ����
	// ����� ���������� ���� ��������� �� ����, �� ����� ����� �� � 
	List_t place = &phantom;
	// ���� � ����� �������� � �������� � �� ������
	while (place->link != nullptr && place->link->value < x)
		// ����� �� �������� �����
		place = place->link;
	// ������� ������ ��������
	place->link = new Node(x, place->link);
	place = nullptr;
	L = phantom.link;
}
