#include <iostream>
using namespace std;

template<typename Iter>
void writeOut(char * title, Iter start, Iter end)
{
	cout << " * * * " << title << endl;
	while (start != end)
		cout << *start++ << ' ';
	cout << endl;
}

class RandGen
{
private:
	int base;
public:
	RandGen(int i = 5){ base = (i == 0) ? 5 : ((i > 0) ? i : -i); }
	int operator()(){ return rand() % base + 1; }
};

class ArithmGen
{
private:
	int a, d;
public:
	ArithmGen(int b, int q) :a(b), d(q){}
	int operator()(){ int b = a; a += d; return b; }
};

typedef double(*func)(double);

class FuncGen
{
private:
	double x, h; func f;
public:
	FuncGen(double start, double step, func fun) : x(start), h(step), f(fun){}
	double operator()(){ double g = f(x); x += h; return g; }
};

struct Summ
{
	int s;
	Summ() :s(0) {}
	void operator()(int x)
	{
		s += x;
	}
};

class O
{
private:
	char c; int i;
public:
	O(char a = 'a', int b = 1) :c(a), i(b){}
	bool operator<(const O& x)const{ return c < x.c; }
	bool operator==(const O& x)const{ return c == x.c; }
	bool operator>(const O& x)const{ return c > x.c; }
	friend ostream& operator<<(ostream& os, const O& x)
	{
		os << x.c << x.i; return os;
	}
	~O(){ cout << *this << " bye\n"; }
	O(const O& o) :c(o.c), i(o.i) { cout << o << " copied "; }
};

class Shape
{
public:
	virtual void draw()const = 0;
	virtual ~Shape(){}
};
class Circle: public Shape
{
	virtual void draw()const { cout << "Circle::Draw()\n"; }
};
class Square: public Shape
{
	virtual void draw()const { cout << "Square::Draw()\n"; }
};

template<typename F1, typename F2>
class unary_composer : public
	unary_function<typename F2::argument_type, typename F1::result_type>
{
	F1 f1; F2 f2;
public:
	unary_composer(F1 a, F2 b) :f1(a), f2(b){}
	typename F1::result_type operator() (typename F2::argument_type x)
	{
		return f1(f2(x));
	}
};

template<typename F1, typename F2>
unary_composer<F1, F2> compose(F1 a, F2 b)
{
	return unary_composer<F1, F2>(a, b);
}
