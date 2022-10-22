#include "FlatShapes.h"
#include "Functions.h"
#include <complex>
#include <iostream>
#include <vector>
#include <memory>
#include <valarray>

using namespace std;

void proc0();
void proc1();
void proc2();
void proc3();

int main()
{
	proc0();
	proc1();
	proc2();
	proc3();
	system("pause");
	return 0;
}

void proc0()
{
	// функція повертає одне значення, але може повернути декілька, об'єднані одним об'єктом
	// простенький приклад використання pair
	// деякі стандартні алгоритми і контейнери сикористовують такий підхід - згадайте, які
	cout << " **** RETURN AGREGATE OBJECT\n\n";
	const size_t n = 7;
	int a[7] = { 2, 9, -1, 0, 4, 12, -5 };
	cout << "The source array contains\n";
	for (size_t i = 0; i < n; ++i) cout << "    a[" << i << "] = " << a[i];
	cout << "\n\n";
	int max = maxVal(a, n);
	cout << "Usual maxVal gives value " << max << endl;
	size_t pos;
	max = maxVal(a, n, pos);
	cout << "Extended maxVal gives value " << max << " and position " << pos << endl;
	Element<int> answer = maxElement(a, n);
	cout << "The maxElement gives value " << answer.value << " and position " << answer.index << endl;
	pair<int, size_t> p = Max(a, n);
	cout << "The answer as pair<> is: value = " << p.first << "; position = " << p.second << endl;
	cin.get();
}

void proc1()
{
	// Скільки коренів має квадратне рівняння? Хто згадав дискримінант, той молодець, але йому треба до школи.
	// Студент мав би згадати основну теорему алгебри і сказати: "Квадратне рівняння з дійсними коефіцієнтами
	// має два корені: різні дійсні, якщо D>0, різні однакові, якщо D=0, комплексні спряжені, якщо D<0.
	// Нагадаємо, уявною одиницею (позначають і) називають таке число, що його квадрат == -1. Комплексне число
	// складається з дійсної та уявної частини: z = x + i y (x, y - дійсні, і - уявна одиниця). 

	// Далі - два приклади обчислень з використанням комплексних чисел.
	cout << " **** COMPLEX\n\n";
	// Корені квадратного рівняння з комплексними коефіцієнтами
	Complex a(1., 0.);
	Complex b(0., 0.);
	Complex c(4., 0.);
	cout << a << "x^2 + " << b << "x + " << c << " = 0\n";
	pair<Complex, Complex> x = SolveSqrEq(a, b, c);
	cout << "x1 = " << x.first << "\nx2 = " << x.second << endl;
	Complex r1 = CalcSqr(a, b, c, x.first);
	Complex r2 = CalcSqr(a, b, c, x.second);
	cout << "Checking: " << r1 << ' ' << r2 << endl;
	cin.get();
	cout << "Input your a, b, c: ";
	(cin >> a >> b >> c).get();
	cout << a << "x^2 + " << b << "x + " << c << " = 0\n";
	x = SolveSqrEq(a, b, c);
	cout << "x1 = " << x.first << "\nx2 = " << x.second << endl;
	// Перевірка підстановкою знайдених коренів
	r1 = CalcSqr(a, b, c, x.first);
	r2 = CalcSqr(a, b, c, x.second);
	cout << "Checking: " << r1 << ' ' << r2 << endl;
	cin.get();
	// Комплексний корінь восьмого степеня з 1
	// У множині дійсних чисел корінь восьмого степеня з 1 має два значення: 1 і -1,
	// а в сножині комплексних чисел - вісім значень
	vector<Complex> Roots;
	ComplexRoots(Complex(1, 0), 8, Roots);
	cout << "\nComplex roots of power 8 of number 1 are:\n";
	for (size_t i = 0; i < Roots.size(); ++i) cout << "    " << Roots[i];
	cout << endl;
	cin.get();
}
void proc2()
{
	// auto_ptr працює зі стандартними контейнерами, якщо не застосовувати копіювання чи присвоєння контейнерів
	// допомагає автоматизувати звільнення пам'яті від динамічних об'єктів
	// Випробуйте дію unique_ptr<objType>, shared_ptr<objType>, weak_ptr<objType>
	cout << "\n\n **** AUTO_PTR\n\n";
	// Створення масиву
	Shape * s[4] = { new Square(), new Rectangle(2,3), new Circle(), new Triangle() };
	cout << "Array:\n";
	for (int i = 0; i < 4; ++i) cout << *s[i] << endl;
	cin.get();
	// Очищення масиву "вручну"
	cout << "Clean array\n";
	for (int i = 0; i < 4; ++i)
		delete s[i];
	cin.get();
	// Створення вектора з аналогічним наповненням
	vector<Shape*> v;
	v.push_back(new Square());
	v.push_back(new Rectangle(2,3));
	v.push_back(new Circle());
	v.push_back(new Triangle());
	cout << "vector:\n";
	for (int i = 0; i < 4; ++i) cout << *v[i] << endl;
	cin.get();
	// Неправильний виклик методу призводить до втрат пам'яті
	v.clear();
	cout << "cleared!\n";
	cin.get();
	// Загорнемо вказівники в шаблон auto_ptr
	vector<auto_ptr<Shape>> av;
	av.push_back(auto_ptr<Shape>(new Square()));
	av.push_back(auto_ptr<Shape>(new Rectangle(2,3)));
	av.push_back(auto_ptr<Shape>(new Circle()));
	av.push_back(auto_ptr<Shape>(new Triangle()));
	cout << "AutoVector:\n";
	for (int i = 0; i < 4; ++i) cout << *av[i] << endl;
	cin.get();
	// Тепер очищення відбувається коректно
	av.clear();
	cout << "AV cleared!\n";

	// shared_ptr - щось інше. Наступні експерименти це демонструють
	// поясніть отримані результати
	cout << "\n **** Shared pointers\n\n";
	if (true)
	{
		shared_ptr<Shape> p(new Square());
		cout << *p << endl;
		cin.get();
		shared_ptr<Shape> c(p);
		c->multBy(2.5);
		cout << *p << endl;
		cin.get();
	}
	vector<shared_ptr<Shape>> uv;
	uv.push_back(auto_ptr<Shape>(new Square()));
	uv.push_back(auto_ptr<Shape>(new Rectangle(2, 3)));
	uv.push_back(auto_ptr<Shape>(new Circle()));
	uv.push_back(auto_ptr<Shape>(new Triangle()));
	vector<shared_ptr<Shape>> cv(uv);
	cout << "\nSharedVectors:\n";
	for (int i = 0; i < 4; ++i) cout << *uv[i] << "     " << *cv[i] << endl;
	cin.get();
	uv.clear();
	cout << "First vector cleared!\n";
	cin.get();
	cv.clear();
	cout << "Second vector cleared!\n";
	cin.get();
}
ostream& operator<<(ostream& os, const valarray<int>& a)
{
	for (size_t i = 0; i < a.size(); ++i)
		os << '\t' << a[i];
	os << '\n';
	return os;
}
void print(const char* title, valarray<int> a[], size_t n)
{
	cout << title << endl;
	for (size_t i = 0; i < n; ++i) cout << a[i];
}
void proc3()
{
	// Числові масиви - набагато ефективніше, ніж (вектори + алгоритми)
	cout << "\n\n **** VALARRAY\n\n";
	typedef valarray<int> Array;
	int x[] = { 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
	Array a(x, 4);
	Array b(x + 4, 4);
	Array c(x + 8, 4);
	Array d(a + b - c);
	cout << a << b << c << d;
	cout << "max(a) = " << a.max() << endl;
	cout << "min(b) = " << b.min() << endl;
	cout << "sum(c) = " << c.sum() << endl;
	cout << " d squared\n" << pow(d, 2);
	cin.get();

	const size_t n = 3;
	const size_t m = 4;
	Array E(n*n);
	E[slice(0, n, n + 1)] = 1;
	cout << "\nUnite matrix by valarray & slice:\n";
	for (size_t i = 0, k = 0; i < n; ++i)
	{
		for (size_t j = 0; j < n; ++j, ++k)
			cout << '\t' << E[k];
		cout << endl;
	}
	cin.get();

	int y[n*m] = { 11, 12, 13, 14, 21, 22, 23, 24, 31, 32, 33, 34 };
	Array s(y, n*m);
	cout << "\nfor_each by valarray:\n" << s << s.apply([](int x){ return 45 - x; });
	cin.get();
	Array CMatr[n];
	for (size_t i = 0; i < n; ++i) CMatr[i] = s[slice(i*m, m, 1)];
	Array FMatr[m];
	for (size_t i = 0; i < m; ++i) FMatr[i] = s[slice(i, n, m)];
	print("\nMatrix in C style", CMatr, n);
	print("\nMatrix in Fortran style", FMatr, m);
	cin.get();
}