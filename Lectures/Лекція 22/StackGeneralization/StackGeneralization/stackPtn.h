// Шаблон стека на основі векторної пам'яті.
// Для зберігання даних використано вбудований масив фіксованого розміру.

template <typename Type>
class Stack
{
private:
	enum { MAX = 10 };
	Type mem[MAX];
	int top;
	Stack(const Stack&);
	Stack& operator=(const Stack&);
public:
	Stack() :top(0) {}
	bool isEmpty() const { return top == 0; }
	bool isFull() const { return top == MAX; }
	void push(const Type& x) { mem[top++] = x; }
	Type pop() { return mem[--top]; }
};