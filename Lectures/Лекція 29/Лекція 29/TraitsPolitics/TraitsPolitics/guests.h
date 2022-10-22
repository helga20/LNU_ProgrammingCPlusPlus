#ifndef _GESTS_H_
#define _GESTS_H_

// ������� ������� ���������� ������� ������, ������, ������ :)
// �� �������� ������� �����, ��� �� ���'���� ������������

#include <iostream>
#include <string>
using std::ostream;
using std::string;

#include "food_place.h"

class Bear  // ������ �� ������ ��
{
private:
	int age;
public:
	Bear(int y=5):age(y) {}
	friend ostream& operator<<(ostream& os, const Bear& B)
	{
		return os << "Bear " << B.age << " years old";
	}
};
class Boy  // ������� �� ��'�
{
private:
	string name;
public:
	Boy(string n="Alex"):name(n) {}
	friend ostream& operator<<(ostream& os, const Boy& B)
	{
		return os << "Boy " << B.name;
	}
};
class Predator  // ������ ��������� �� ��������� �����
{
private:
	string species;
public:
	Predator(string s="Volf"):species(s) {}
	friend ostream& operator<<(ostream& os, const Predator& P)
	{
		return os << P.species;
	}
};

// ������ � ��� в���� ����� ��, �� ��� ���������� ���������� ��������
//   ���� �� �������, �������� ����� ��� ���� � �������� ����������
// ̳���, ����, ������� - �������������� �������� ���� �����
// �� �������� (������)��������� �������

// "���������", "�����������" ������, ���� ���� �� ���� ���������������
// �� ���� ���� ������, � ������������� ������������
// ������������, �� ����� ������������ ����������� �������� ���� ����

template <class Guest> class GuestTraits;
/* place_type, beverage_type, snack_type */

template<> class GuestTraits<Bear>
{ // �������������� �������, �� �����:
  // ���� - �����, ���� - ������� ������, ������� - ���
public:
	typedef Carpet place_type;
	typedef CondensedMilk beverage_type;
	typedef Honey snack_type;
};
template<> class GuestTraits<Boy>
{ // �������������� ��������, �� �����:
  // ���� - �� ������, ���� - ������, ������� - ������
public:
	typedef Table place_type;
	typedef Milk beverage_type;
	typedef Cookies snack_type;
};
template<> class GuestTraits<Predator>
{ // �������������� ������, �� �����:
  // ���� - �����, ���� - ����, ������� - �'���
public:
	typedef Cage place_type;
	typedef Water beverage_type;
	typedef Meat snack_type;
};

#endif