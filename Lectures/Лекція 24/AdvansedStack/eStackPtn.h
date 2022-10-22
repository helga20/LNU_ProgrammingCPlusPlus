/*
������ ����� ����� ����������� �� ������� ��� ��������� �������.
����� ����-������ �������� ��������� ������������.
*/
#include "stackPtn.h"
template <typename Type>
class ExtStack : public Stack<Type>
{
public:
	//������� �������� � ������� ��� ���� �����
	Type peek() const { return mem[top - 1]; }
};

// ��������������� ������ ����� ���� ���� ������� ������

class StackDbl : public ExtStack<double>
{
public:
	// �� ����� �������� ���������� �����
	void print() const;
};