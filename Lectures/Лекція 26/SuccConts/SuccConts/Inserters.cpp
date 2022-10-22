#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <iterator>
#include "noisy.h"
#include "Tools.h"
using namespace std;

const int n = 7;

// �������� copy(sourceStart, sourceEnd, destinationStart) ��������������
// ��� ��������� ��������. ��� �� ��������� ��������� � �����������
// ������� ������ � ����� �������� �����, ������� ���������������
// ��������� ����������.
// ������� ������� ������������ ������������ ��������� ���������� ��
// ���������� ����������

// ����������� � ����� ����������� ����������
template<class Cont>
void backInsertion(Noisy* a, Cont& ci, char* name)
{
	cout<<"\n*** BI *** ����������� � ����� "<<name<<" \n";
	//copy(a, a + n, back_inserter(ci));  // ����� ����������� ������ �����
	for (typename Cont::value_type * p = a; p != a + n; ++p)
	{
		ci.push_back(*p);
		cout << "  .................\n";
	}
	cout<<"\n��������:\n";
	copy(ci.begin(), ci.end(), ostream_iterator<typename Cont::value_type>(cout, " "));
	cout<<'\n'; cin.get();
}
// ��������� � ���� ���������� �� ������������ ���������� � ����� ����������
template<class Cont>
void backEmplacing(Noisy* a, Cont& ci, char* name)
{
	cout << "\n*** BE *** ��������� � ���� " << name << " \n";
	cout << " = � ������\n";
	for (int i = 0; i < 3; ++i)
	{
		ci.emplace_back(a[i]);
		cout << "  .................\n";
	}
	cout << " = �� �������������\n";
	for (int i = 3; i < n; ++i)
	{
		ci.emplace_back();
		cout << "  .................\n";
	}
	cout << " = � ����� ����������\n";
	for (int i = 1; i < 4; ++i)
	{
		ci.emplace_back(i + 100);
		cout << "  .................\n";
	}
	cout << " = � ����� �����������\n";
	for (int i = 2; i < 5; ++i)
	{
		ci.emplace_back(i, 7);
		cout << "  .................\n";
	}
	cout << "\n��������:\n";
	copy(ci.begin(), ci.end(), ostream_iterator<typename Cont::value_type>(cout, " "));
	cout << '\n'; cin.get();
}

// ���������� ���������. ������� ���������� ������� �������.
template<class Cont>
void midInsertion(Noisy* a, Cont& ci, char* name)
{
	typename Cont::iterator it = ci.begin();
	++it; ++it; ++it;
	cout << "\n*** MI *** ���������� ��������� " << name << " (���� ��������)\n";
	copy(a, a + n / 2, inserter(ci, it));
	cout << "\n��������:\n";
	copy(ci.begin(), ci.end(), ostream_iterator<typename Cont::value_type>(cout, " "));
	cout << '\n'; cin.get();
}

// ���������� �� ������� ���������� �������� ��� list, deque
template<class Cont>
void frontInsertion(Noisy* a, Cont& ci, char* name)
{
	cout << "\n*** FI *** ���������� �� ������� " << name << " \n";
	copy(a, a + n, front_inserter(ci));
	cout << "\n��������:\n";
	copy(ci.begin(), ci.end(), ostream_iterator<typename Cont::value_type>(cout, " "));
	cout << '\n'; cin.get();
}
// vector �� �� ������ ���������� �� �������, ���� ��� ����� ������
// ���� ������������ �������
template<>
void frontInsertion<vector<Noisy>>(Noisy* a, vector<Noisy>& ci, char* name)
{
	cout << "\n*** FI *** ���������� �� ������� " << name << " \n";
	copy(a, a + n, inserter(ci, ci.begin()));
	cout << "\n��������:\n";
	copy(ci.begin(), ci.end(), ostream_iterator<typename vector<Noisy>::value_type>(cout, " "));
	cout << '\n'; cin.get();
}

int use_Inserters()
{
	// ������� ����� ��� ���������� ����������
	Noisy a[n];

	cout<<"\n��������� ������ ����������\n";
	deque<Noisy> di;
	list<Noisy> li;
	vector<Noisy> vi, A, B;
	A.reserve(5); B.reserve(5);
	cin.get();

	cout << "\n~~~ ��������� push_back � emplace_back\n\n";
	A.push_back(Noisy());
	B.emplace_back();
	cout << "  .................\n";
	A.push_back(Noisy(17));
	B.emplace_back(17);
	cout << "  .................\n";
	A.push_back(Noisy(5, 5));
	B.emplace_back(5, 5);
	cout << "  .................\n";
	cin.get();

	cout << "\n+++ ����������� � ����� ����������\n\n";
	backInsertion(a, vi, "VECTOR");
	backInsertion(a, di, "DEQUE");
	backInsertion(a, li, "LIST");

	cout << "\n--- �������� ����������\n\n";
	vi.clear(); vi.shrink_to_fit(); cin.get();
	di.clear(); di.shrink_to_fit(); cin.get();
	li.clear(); cin.get();

	cout << "\n+++ ��������� � ���� ����������\n\n";
	backEmplacing(a, vi, "VECTOR");
	backEmplacing(a, di, "DEQUE");
	backEmplacing(a, li, "LIST");

	cout << "\n--- �������� ����������\n\n";
	vi.clear(); vi.shrink_to_fit(); cin.get();
	di.clear(); di.shrink_to_fit(); cin.get();
	li.clear(); cin.get();

	cout << "\n+++ ���������� �� ������� ����������\n\n";
	frontInsertion(a, vi, "VECTOR");
	frontInsertion(a, di, "DEQUE");
	frontInsertion(a, li, "LIST");

	cout << "\n+++ ���������� � �������� ����������\n\n";
	midInsertion(a, vi, "VECTOR");
	midInsertion(a, di, "DEQUE");
	midInsertion(a, li, "LIST");

	return 0;
}

/*
23 19 17 13 11 7 5 3 1
23 19 17 13 11 7 5 3 1
1 3 5 7 11 13 17 19 23
1 3 5 7 11 13 17 19 23
1 3 5 7 11 13 17 19 23
1 3 5 1 3 5 7 7 11 13 17 19 23
1 3 5 1 3 5 7 7 11 13 17 19 23
1 3 5 1 3 5 7 7 11 13 17 19 23
*/
