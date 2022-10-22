#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <iterator>
#include <functional>
#include "tools.h"

double sqr(double x) { return sqrt(x*x + 1.); }
double cube(double x) { return ((x + 1.)*x - 2.)*x + 6.; }
bool isEven(int x) { return x % 2 == 0; }
void print(double x) { cout << '\t' << x; }

int main()
{
	srand(time(0));
	const int n = 9;
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	writeOut("first", a, a + 4);
	writeOut("second", a + 4, a + n);
	writeOut("whoul", a, a + n);
	cin.get();
	// Заповнення інтервалів та генерування значень

	// void fill(FI first, FI last, const T& val);
	fill(a, a + n, 5);
	writeOut("Filled array", a, a + n);
	cin.get();

	// void fill_n(OI first, Size n, const T& val);
	vector<int> V(n);
	writeOut("Created vector", V.begin(), V.end());
	fill_n(V.begin(), V.size(), 7);
	writeOut("Filled vector", V.begin(), V.end());
	cin.get();


	// void generate(FI first, FI last, G gen);
	generate(V.begin(), V.end(), RandGen(n));
	writeOut("Random generated vector", V.begin(), V.end());
	cin.get();

	// void generate_n(OI first, Size n, G gen);
	generate_n(a, n, ArithmGen(2, 2));
	writeOut("Arithmetic generated array", a, a + n);
	cin.get();
	vector<double> F;
	generate_n(back_inserter(F), 12, FuncGen(0., .25, sqr));
	writeOut("Functionally sqr generated vector", F.begin(), F.end());
	F.resize(n);
	generate_n(F.begin(), n, FuncGen(1., .1, cube));
	writeOut("Functionally cube generated vector", F.begin(), F.end());
	cin.get();
	/*
	  Підрахунок
	  ----------
	  IntegralValue count(II first, II last, const EqualityComparable& val);
	  IntegralValue count_if(II first, II last, UP pred);
	  */
	cout << "How many F[i] belongs to (7;9): "
		<< count_if(F.begin(), F.end(), [](double x){ return x > 7 && x < 9; })
		<< endl;
	cin.get();
	cout << "How many F[i] belongs to (7;9): "
		<< count_if(F.begin(), F.end(),
			bind(logical_and<bool>(),
				bind(greater<double>(), std::placeholders::_1, 7.0),
				bind(less<double>(), std::placeholders::_1, 9.0)))
		<< endl;
	cin.get();


	// Копіювання та перестановки
	// OI copy(II first, II last, OI dest);
	// BI2 copy_backward(BI1 first, BI1 last, BI2 destEnd);
	copy_backward(a, a + 5, V.end());
	writeOut("Backward copied vector", V.begin(), V.end());
	cin.get();

	// void reverse(BI first, BI last);
	// OI reverse_copy(BI first, BI last, OI dest);
	// FI2 swap_ranges(FI1 first, FI1 last, FI2 dest);
	// void rotate(FI first, FI middle, FI last);
	// OI rotate_copy(FI first, FI middle, FI last, OI dest);

	// bool next_permutation(BI first, BI last);
	generate_n(V.begin(), n, ArithmGen(1, 1));
	writeOut("Arithmetic generated vector", V.begin(), V.end());
	next_permutation(V.begin(), V.end());
	writeOut("1 Permuted vector", V.begin(), V.end());
	next_permutation(V.begin(), V.end());
	writeOut("2 Permuted vector", V.begin(), V.end());
	next_permutation(V.begin(), V.end());
	writeOut("3 Permuted vector", V.begin(), V.end());
	cin.get();

	// bool next_permutation(BI first, BI last, SO binary_pred);
	// bool prev_permutation(BI first, BI last);
	// bool prev_permutation(BI first, BI last, SO binary_pred);

	// void random_shuffle(RI first, RI last);
	random_shuffle(V.begin(), V.end());
	writeOut("Shuffled vector", V.begin(), V.end());
	cin.get();

	// void random_shuffle(RI first, RI last, G random_number);

	// BI partition(BI first, BI last, UP pred);
	vector<int>::iterator it;
	//it = partition(V.begin(), V.end(), bind2nd(greater<int>(), 4));
	it = partition(V.begin(), V.end(), bind(greater<int>(), std::placeholders::_1, 4));
	writeOut("Partition of vector", V.begin(), V.end());
	cout << "last permuted element " << *it << endl;
	cin.get();

	// BI stable_partition(BI first, BI last, UP pred);
	O b[] = { O('a', 1), O('a', 2), O('a', 3), O('a', 4), O('c', 1), O('c', 2), O('c', 3), O('d'), O('e') };
	writeOut("Array of objects", b, b + n);
	random_shuffle(b, b + n);
	writeOut("Shuffled array of objects", b, b + n);
	cout << "--- Copy in process...\n";
	vector<O> C; C.reserve(n);
	copy(b, b + n, back_inserter(C));
	cout << "\n--- Partition in process...\n";
	//partition(b, b + n, bind2nd(greater<O>(), O('b')));
	partition(b, b + n, bind(greater<O>(), std::placeholders::_1, O('b')));
	writeOut("Partition of the array of objects", b, b + n);
	//stable_partition(C.begin(), C.end(), bind2nd(greater<O>(), O('b')));
	stable_partition(C.begin(), C.end(), bind(greater<O>(), std::placeholders::_1, O('b')));
	writeOut("Stable_partition of the array of objects", C.begin(), C.end());
	cin.get();

	// Застосування дії до кожного елемента

	// UF for_each(II first, II last, UF f);
	// OI transform(II first, II last, OI dest, UF f);
	// OI transform(II1 first1, II1 last1, II2 first2, OI dest, BF f);
	fill(a, a + n, 2);
	generate(V.begin(), V.end(), RandGen(n));
	writeOut("Random generated vector", V.begin(), V.end());
	cout << "\n -- for_each is printing --\n\n";
	for_each(V.cbegin(), V.cend(), [](int x){ cout << '[' << x << ']'; });
	cout << "\n\n -- for_each is accumulating --\n\n";
	int summa = for_each(V.cbegin(), V.cend(), Summ()).s;
	cout << "summa = " << summa << '\n';
	cout << "\n -- for_each is modifying --\n\n";
	for_each(V.begin(), V.end(), [](int &x){ x *= 2; });
	writeOut("Doubled vector", V.begin(), V.end());
	cin.get();

	int r[n];
	//transform(V.begin(), V.end(), r, bind1st(plus<int>(), 2));
	transform(V.begin(), V.end(), r, bind(plus<int>(), 2, std::placeholders::_1));
	writeOut("Transformed vector + 2", r, r + n);
	cout << "Transformed vector - a\n";
	transform(V.begin(), V.end(), a, ostream_iterator<int>(cout, "\t"), minus<int>());
	cout << endl;
	cin.get();

	// адаптація вказівника на функцію
	cout << "Take odds from the vector\n";
	int * k = transform(V.begin(), V.end() - 2, r, not1(ptr_fun(isEven)));
	writeOut("Whole vector", r, r + n);
	writeOut("taked vector", r, k);
	cin.get();

	transform(F.begin(), F.end(), F.begin(), bind2nd(ptr_fun<double, double, double>(pow), 2.));
	writeOut("Powered vector", F.begin(), F.end());
	cin.get();

	// адаптація вказівника на метод
	list<Shape*> L;
	L.push_back(new Circle); L.push_back(new Square); L.push_back(new Circle);
	cout << " - - - Shapes:\n";
	//for_each(L.begin(), L.end(), mem_fun(&Shape::draw));
	for_each(L.begin(), L.end(), mem_fn(&Shape::draw));
	cout << endl;
	cin.get();

	list<string> S;
	S.push_back("first"); S.push_back("second"); S.push_back("A"); S.push_back("Bb");
	cout << " - - - Strings:\n";
	//transform(S.begin(), S.end(), ostream_iterator<int>(cout, "; "), mem_fun_ref(&string::length));
	transform(S.begin(), S.end(), ostream_iterator<int>(cout, "; "), mem_fn(&string::length));
	cout << endl;
	cin.get();

	// користувацький адаптер
	cout << "Compose print(sqr) generated vector\n";
	for_each(F.begin(), F.end(), compose(ptr_fun(print), ptr_fun(sqr)));
	cout << endl;
	cin.get();
	
	list<O*> vo;
	vo.push_back(new O('A', 5));
	vo.push_back(new O('B', 1));
	vo.push_back(new O('A', 2));
	vo.push_back(new O('B', 9));
	vo.push_back(new O('B', 3));
	vo.push_back(new O('A', 6));
	vo.push_back(new O('B', 7));
	vo.push_back(new O('B', 4));
	vo.push_back(new O('A', 8));
	cout << "List of Objects:\n";
	for (list<O*>::iterator it = vo.begin(); it != vo.end(); ++it) cout << "   " << **it;
	cout << '\n';
	vo.remove_if([](O* x){return *x == O('A', 0); });
	/*list<O*>::const_iterator tr = vo.begin();
	while (tr != vo.end())
	{
	if (**tr == O('A', 0))
	{
	delete *tr;
	tr = vo.erase(tr);
	}
	else ++tr;
	}*/
	for (list<O*>::iterator it = vo.begin(); it != vo.end(); ++it) cout << "   " << **it;
	cout << '\n';
	cin.get();
	return 0;
}