#ifndef _FOODnPLACE_H_
#define _FOODnPLACE_H_

#include <iostream>
using std::ostream;

// ���� �� ������� ��� ������
class Milk
{
public:
	friend ostream& operator<<(ostream& os, const Milk&)
	{
		return os << "Milk";
	}
};
class CondensedMilk
{
public:
	friend ostream& operator<<(ostream& os, const CondensedMilk&)
	{
		return os << "CondensedMilk";
	}
};
class Honey
{
public:
	friend ostream& operator<<(ostream& os, const Honey&)
	{
		return os << "Honey";
	}
};
class Cookies
{
public:
	friend ostream& operator<<(ostream& os, const Cookies&)
	{
		return os << "Cookies";
	}
};
class Water
{
public:
	friend ostream& operator<<(ostream& os, const Water&)
	{
		return os << "Water";
	}
};
class Bread
{
public:
	friend ostream& operator<<(ostream& os, const Bread&)
	{
		return os << "Bread";
	}
};
class Meat
{
public:
	friend ostream& operator<<(ostream& os, const Meat&)
	{
		return os << "Meat";
	}
};

// ̳���, �� ����� ����������� ������
class Table
{
public:
	friend ostream& operator<<(ostream& os, const Table&)
	{
		return os << "at the table";
	}
};
class Carpet // �����, �����
{
public:
	friend ostream& operator<<(ostream& os, const Carpet&)
	{
		return os << "on the carpet";
	}
};
class Cage // �����
{
public:
	friend ostream& operator<<(ostream& os, const Cage&)
	{
		return os << "in the cage";
	}
};
#endif