#include "arrayPtn.h"
/*
������ ����� �� ����� �������� ���'��. ������� ��������� "has-a" �� ���������.
��� ��������� ����� ����������� ��������� �����-����. ���� �� ���������� ���
��������� ��������� ���'����, ���� ����-���� ������ ����������. ����� ����������
������ � ��������� ������ �����. ������ ���������-��������� ����� ������
���������� ������� (� �����)
*/
template <typename Type>
class HStack
{
private:
	enum { MAX = 10 };
	Array<Type> mem;
	int top;
public:
	explicit HStack(int ss = MAX):mem(ss),top(0){ }
	bool isEmpty() const {return top == 0;}
	bool isFull() const {return top == mem.arSize();}
	void push(const Type& x) { mem[top] = x; ++top; }
	Type pop();
};

template<typename Type>
inline Type HStack<Type>::pop()
{
	try
	{
		return mem[--top];
	}
	catch (std::out_of_range)
	{
		top = 0;
		throw;
	}
}
