/*
 ����-���������, �� ������ ����������� ��'����� ����� (����� �������).
  ���'��� - �����'����� ������ ��������� �� ��'���� (��� ������������ �����������)
    � ���������� ������.
  ���� ������� �������� �������/�������� ���'���, ��������� ���� ����
  ������������, ����������, �������� ���������.
 ��������������� ����������: ��������� �������� � �����, ���������� ���������,
  ��������� �� �������, ��������� ���, ������ ��������:
  - ���� �������,
  - ��������� �������,
  - ��������� ������� 䳿 � ������,
  - ����� �������, �� ����������� ������ �������.

 ��������� - ������� ���� ��������, ���� ���� ������� ������: ����� �����
  ���� ���������, ����� �� ��� ����� ��������� �� ���������.
 ��������:
  �� �� ���������� ���������� ��������� ��� ��'����, �� ��������� �� ����������
     �� ����� - �������� �� ������������� �� ������� ���� ����������� ��'����
  �� ����������� ����������� ������ ���������� (��������� ����� ���� ����������
     ����, ������ �� ���������� ��������) - ���������� �������� ��������, ���
     �������� ������������ ��'������-���������
*/
#ifndef _Shapes_DblList_
#define _Shapes_DblList_

#include "..\Shapes\VolumeShapes.h"

// ��� �������, ��� ����� ����������� �� ������� �������� ����������
typedef void Action(VolShape*);

// ��� ������� ��� ��������(������) �������� ����������
typedef bool Predicate(VolShape*);

class ShDblList
{
private:
	// ����� ������
	struct Node
	{
		VolShape* shape;
		Node* prev;
		Node* next;
		Node(VolShape* s = nullptr, Node* p = nullptr, Node* n = nullptr) :shape(s), prev(p), next(n) {}
		~Node() { delete shape; }
	};
	int len;		// ������� �������� ������ (�����)
	Node* mem;		// �������� �� ���� ���'��� - �� ������� ������
	Node* bottom;	// ������� ����� ������ 
	// ���� ����� ��� ������������ ������������
	mutable Node* curr;		// ������� ������������
	mutable int index;		// ����� �������� ����������� �����
	bool chekIndex(int i) const { if (i < 0 || i >= len) throw BadIndex(i); }
	void moveCurr(int i) const;
public:
	class BadIndex: public std::range_error		// ����������� ������� - ��������� ������
	{
	public:
		int index;
		BadIndex(int i): range_error("Index out of range of the container"), index(i) {}
	};
// ��������� ��������� - �� ������� ������, �� ������ ���� ��������� �����
	ShDblList(): len(0), mem(new Node()), index(-1)
	{
		curr = bottom = mem;
	}

// ����������� � ������� ���������� ��������� ������ ��������
// explicit ��������� �� ����������� ������������ ������ ����� � ���������
	explicit ShDblList(int n) : ShDblList() {}

// ����'������ ��� �����, �� ����������� �������� ���'���
	ShDblList(const ShDblList &);
	~ShDblList();
	ShDblList& operator=(const ShDblList &);
// ������ �� ��������
	ShDblList& put(VolShape*);
	ShDblList& insert(VolShape*, int); // throw(BadIndex&)
	ShDblList& remove(int);            // throw(BadIndex&)
	ShDblList& clear();
	VolShape*& operator[](int);      // throw(BadIndex&)
	const VolShape* operator[](int) const;  //�� �� ����������? ���� ����� ������������ ����� ����� ���� ����������!
	int high() const { return len - 1; }
	void loadFrom(std::ifstream&);   // throw(VolShape::BadClassname&)
// ������ ��������
	void printOn(ostream&) const;
	void storeOn(ofstream&) const;
	void doEach(Action) const;
	int detectFirst(Predicate) const;
};

#endif