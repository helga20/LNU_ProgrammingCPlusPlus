/*
 ����-���������, �� ������ ����������� ��'����� ����� (����� �������).
  ���'��� - ��������� ����� ��������� �� ��'���� (��� ������������ �����������).
  ���� ������� �������������� ���'��� (�� �������), ��������� ���� ����
  ������������, ����������, �������� ���������.
 ��������������� ����������: ��������� �������� � �����, ���������� ���������,
  ��������� �� �������, ��������� ���, ������ ��������: - ���� �������,
  - ��������� �������, - ��������� ������� 䳿 � ������, - ����� �������,
  �� ����������� ������ �������.

 ��������� - ������� ���� ��������, ���� ���� ������� ������: ����� �����
  ���� ���������, ����� �� ��� ����� ��������� �� ���������.
 ��������:
  �� �� ���������� ���������� ��������� ��� ��'����, �� ��������� �� ����������
     �� ����� - �������� �� ������������� �� ������� ���� ����������� ��'����
  �� ����������� ����������� ������ ���������� (��������� ����� ���� ����������
     ����, ������ �� ���������� ��������) - ���������� �������� ��������, ���
     �������� ������������ ��'������-���������
*/
#ifndef _Shapes_Array_
#define _Shapes_Array_

#include "..\Shapes\VolumeShapes.h"

// ��� �������, ��� ����� ����������� �� ������� �������� ����������
typedef void Action(VolShape*);

// ��� ������� ��� ��������(������) �������� ����������
typedef bool Predicate(VolShape*);

class ShArray
{
private:
	int used, size;		// ������ ������� �� ������� ���'��
	VolShape** mem;		// �������� �� ���� ���'���
	void checkMem();	// �� ������� ������������� ���'���
	void chekIndex(int i) const { if (i < 0 || i >= used) throw BadIndex(i); }
public:
	class BadIndex: public std::range_error		// ����������� ������� - ��������� ������
	{
	public:
		int index;
		BadIndex(int i): range_error("Index out of range of the container"), index(i) {}
	};
// ��������� ��������� ���� ������ �� ������
	ShArray(): used(0), size(2), mem(new VolShape*[2]) {}

// ����� ������� �������� �������� ����� ������� ���'��, ��� �������� �������������
// explicit ��������� �� ����������� ������������ ������ ����� � ���������
	explicit ShArray(int n): used(0), size(n), mem(new VolShape*[n]) {}

// ����'������ ��� �����, �� ����������� �������� ���'���
	ShArray(const ShArray &);
	~ShArray();
	ShArray& operator=(const ShArray &);
// ������ �� ��������
	ShArray& put(VolShape*);
	ShArray& insert(VolShape*, int); // throw(BadIndex&)
	ShArray& remove(int);            // throw(BadIndex&)
	ShArray& clear();
	VolShape*& operator[](int);      // throw(BadIndex&)
	const VolShape* operator[](int) const;
	int high() const { return used - 1; }
	void loadFrom(std::ifstream&);   // throw(VolShape::BadClassname&)
// ������ ��������
	void printOn(ostream&) const;
	void storeOn(ofstream&) const;

	void doEach(Action) const;
	int detectFirst(Predicate) const;
};

#endif