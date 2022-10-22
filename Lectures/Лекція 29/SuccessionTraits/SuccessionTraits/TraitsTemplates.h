#pragma once

#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <set>
#include <memory>
#include <iostream>

using std::cout;

// �������������� ������������ ���Ѳ�, �������� ������������ ��� ���������� �����
template <class T, class Succession> class SuccessionTraits;
/* ��� Succession - �������� ����: �������, ���������, � ���� � �
       � - ��� �����, �� ����������� � ���������, �� ��� ���� �������� � �������������
   ��� ������ - �������, ������� ����� ������� ��� ��'� �������-������������ */

// ���� ������������� �������, �������� ������������ ��� Succession = std::vector<T>
// �������� � ���������� ������, ������� ������������ ��������� ��� �������
template <class T> class SuccessionTraits<T, std::vector<T>>
{
public:
	static const char * GetTitle() { return " * Vector *"; }
};
// ����� ������������ ��� ������� ������� ������ ����
template <> class SuccessionTraits<int, std::vector<int>>
{
public:
	static const char * GetTitle() { return " * Vector of Integers *"; }
};

// ���� ������������� ������, �������� ������������ ��� Succession = std::list<T>
template <class T> class SuccessionTraits<T, std::list<T>>
{
public:
	static const char * GetTitle() { return " * List *"; }
};

// ���� ������������� ����, �������� ������������ ��� Succession = std::deque<T>
template <class T> class SuccessionTraits<T, std::deque<T>>
{
public:
	static const char * GetTitle() { return " * Deque *"; }
};

// ���� ������������� �������, �������� ������������ ��� Succession = std::set<T>
template <class T> class SuccessionTraits<T, std::set<T>>
{
public:
	static const char * GetTitle() { return " -*- Set -*-"; }
};

// ������ �������� ������� �� �������� �� �, ���� ���� ������� ��������� ��� �������
template <class T, class Succession, class Traits = SuccessionTraits<T, Succession> >
void PrintSuccession(const Succession& S)
{
	typename Succession::const_iterator it = S.cbegin();
	cout << Traits::GetTitle() << '\n';
	while (it != S.cend())
	{
		cout.width(8);
		cout << *it++;
	}
	cout << '\n';
}

//----------------------------------------------------------

// �������������� �����Ͳ� ������������ �����
template <template <class T, class Allocator = std::allocator<T>> class Succession> class SuccTraits;
/* �������� � �����������, �� ����� � ��� �������� ���������� ����������
   ��� �������� �� ��� ��� ����������, � ���� ��� ���, �� ������� �����
   ��������� ���� ���������
*/
// ������������ ��� ������� ����������� ���������� ����������
template <> class SuccTraits<std::vector>
{
public:
	static const char * GetTitle() { return " +++ VECTOR +++"; }
	static const char leftBound = '[';
	static const char rightBound = ']';
};
template <> class SuccTraits<std::list>
{
public:
	static const char * GetTitle() { return " +++ DOUBLE-LINKED LIST +++"; }
	static const char leftBound = '<';
	static const char rightBound = '>';
};
template <> class SuccTraits<std::deque>
{
public:
	static const char * GetTitle() { return " +++ DEQUE +++"; }
	static const char leftBound = '\\';
	static const char rightBound = '/';
};
template <> class SuccTraits<std::forward_list>
{
public:
	static const char * GetTitle() { return " +++ SINGLE-LINKED LIST +++"; }
	static const char leftBound = '|';
	static const char rightBound = '|';
};
template <class E, template <class T, class Allocator = std::allocator<T>> class Succession, class Traits = SuccTraits<Succession> >
void PrintSucc(const Succession<E>& S)
{
	typename Succession<E>::const_iterator it = S.cbegin();
	cout << Traits::GetTitle() << '\n';
	if (S.empty())
	{
		cout << Traits::leftBound << " empty " << Traits::rightBound << '\n';
		return;
	}
	while (it != S.cend())
	{
		cout << Traits::leftBound << *it++ << Traits::rightBound << ' ';
	}
	cout << '\n';
}
