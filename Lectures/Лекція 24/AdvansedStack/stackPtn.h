/*
Шаблон стека на основі векторної пам'яті.
Для зберігання даних використано вбудований масив фіксованого розміру.
*/
template <typename Type>
class Stack
{
protected:
	enum { MAX = 10 };
	Type mem[MAX];
	int top;
	Stack(const Stack&) = delete;
public:
	Stack() :top(0) {}
	bool isEmpty() const { return top == 0; }
	bool isFull() const { return top == MAX; }
	void push(const Type& x) { mem[top++] = x; }
	Type pop() { return mem[--top]; }
	Stack& operator=(const Stack& st)
	{
		if (&st != this)
		{
			top = 0;
		}
		return *this;
	}
};