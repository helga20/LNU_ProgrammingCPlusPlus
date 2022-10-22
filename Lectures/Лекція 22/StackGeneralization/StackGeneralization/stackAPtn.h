// ������ ����� �� ����� �������� ���'��.
// ��� ��������� ����� ����������� ���������� ����� �������� ������.
// ����� ������ � ����������-������� �������.

template <typename Type, int N>
class AStack
{
private:
	Type mem[N];
	int top;
public:
	AStack():top(0){};
	bool isEmpty() const {return top == 0;}
	bool isFull() const {return top == N;}
	bool push(const Type& x);
	bool pop(Type& res);
};
template <typename Type, int N> bool AStack<Type,N>::push(const Type &x)
{
	if (top<N)
	{
		mem[top++] = x;
		return true;
	}
	return false;
}
template <typename Type, int N> bool AStack<Type,N>::pop(Type &res)
{
	if (top>0)
	{
		res = mem[--top];
		return true;
	}
	return false;
}