#include <iostream>
using namespace std;

// Обчислення факторіала на стадії компіляції
template<long long n>
struct Factorial
{
	enum { val = Factorial<n - 1>::val * n };
};
template<> struct Factorial<1> { enum { val = 1 }; };
template<> struct Factorial<0> { enum { val = 1 }; };

// Рекурсія за допомогою константи всередині структури
// (накопичення шкідливих викликів не відбувається
template<int n> struct Fib {
	enum { val = Fib<n-1>::val + Fib<n-2>::val };
};
template<> struct Fib<1> { enum { val = 1 }; };
template<> struct Fib<0> { enum { val = 1 }; };

// Арифметичний цикл через рекурсію
template<int N, int P> struct Power {
	enum { val = N * Power<N, P-1>::val };
};
template<int N> struct Power<N,0> {
	enum { val = 1 }; };

// Просте галуження
template<int a, int b> struct Max {
	enum { val = a>b ? a : b }; };

// Вибір способу виконання запрограмувати складніше
template<bool cond> struct Select {};

template<> struct Select<false> {
	static inline void f() {
		cout << "False statement executing\n";
	}
};
template<> struct Select<true> {
	static inline void f() {
		cout << "True statement executing\n";
	}
};
template<bool cond> void execute() {
	Select<cond>::f();
}

int main()
{
// Факторіал
	cout << "Factorials\n\n";
	cout << "\t 0! = " << Factorial<0>::val << '\n';
	cout << "\t12! = " << Factorial<12>::val << "\n\n";
// Числа Фібоначчі
	cout << "Fibonacci numbers\n\n";
	cout << "\tF( 5) = " << Fib<5>::val << '\n';
	cout << "\tF(35) = " << Fib<35>::val << "\n\n";
// Піднесення цілого до цілої степені
	cout << "Integer power\n\n";
	cout << "\t 2^5 = " << Power<2, 5>::val << '\n';
	cout << "\t2^10 = " << Power<2, 10>::val << "\n\n";
// Більше з двох цілих
	cout << "Max value\n\n";
	cout << "\tmax(10,20) = " << Max<10, 20>::val << '\n';
	cout << "\tmax(F(10),2^10) = " << Max<Fib<10>::val, Power<2, 10>::val>::val << "\n\n";
// Умовне виконання
	cout << "A condition dependent executing\n\n";
	cout << "\tif 2>5 then - "; Select<(2>5)>::f(); cout << '\n';
	cout << "\tif sizeof(int)=4 then - "; execute<sizeof(int) == 4>(); cout << "\n\n";
	cin.get();
	return 0;
}
