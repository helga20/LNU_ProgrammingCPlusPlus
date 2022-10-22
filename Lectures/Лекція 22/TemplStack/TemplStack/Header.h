#include <iostream>
template <class T>
class Stack
{
	enum { size = 10 };
	T mem[size];
	int top;
public:
	Stack() :top(0){}
	bool isEmpty() const { return top == 0; }
	bool isFull() const { return top == size; }
	void push(const T& x){ mem[top++] = x; }
	T& pop(){ return mem[--top]; }
};

struct Time
{
	int hour; int min;
	Time(int h, int m)
	{
		std::cout << "\n *** Parameter\n";
		min = m % 60;
		hour = h + m / 60;
	}
	Time() :hour(0), min(0){ std::cout << "\n *** Default\n"; }
	Time(const Time& t) :hour(t.hour), min(t.min) { std::cout << "\n *** Copy\n"; }
	Time& operator=(const Time& t)
	{
		hour = t.hour; min = t.min;
		std::cout << "\n *** Assignment\n";
		return *this;
	}
};