// Шаблон стека на основі векторної пам'яті.
// Для зберігання даних використано динамічний масив.
// Розмір масиву задають в конструкторі стека.

template <typename Type>
class DStack
{
private:
	enum { MAX = 10 };
	int size;
	Type* mem;
	int top;
	DStack(const DStack& st);
	DStack& operator=(const DStack& st);
public:
	explicit DStack(int ss = MAX):size(ss),top(0){ mem = new Type[size]; }
	~DStack() { delete [] mem; }
	bool isEmpty() const {return top == 0;}
	bool isFull() const {return top == size;}
	bool push(const Type& x);
	bool pop(Type& res);
};

template <typename Type> bool DStack<Type>::push(const Type &x)
{
	if (top<size)
	{
		mem[top++] = x;
		return true;
	}
	return false;
}
template <typename Type> bool DStack<Type>::pop(Type &res)
{
	if (top>0)
	{
		res = mem[--top];
		return true;
	}
	return false;
}