// ����� ������ ������� ���������� �����
// ���������� �� ���� �����

typedef unsigned long Item;

// ���� �� ����� ����������� ������ ������� ������.
// ��������� ���������� �� ���������/��������� �����
// ������� ����������, ��������� ����� ����������.
class stack
{
private:
	enum { MAX = 10 };
	Item mem[MAX];
	int top;
	stack(const stack&);
	stack& operator=(const stack&);
public:
	stack() :top(0) {}
	bool isEmpty() const { return top == 0; }
	bool isFull() const { return top == MAX; }
	void push(const Item& x) { mem[top++] = x; }
	Item pop() { return mem[--top]; }
};