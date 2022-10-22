//#define _ITERATOR_DEBUG_LEVEL 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Array.h"
#include "InOutOperators.h"
#include "DblList.h"
#include "Stack.h"

using namespace std;

void Containers();
void Stacks();
void Algorithms();

int main()
{
	Containers();
	system("pause");
	Stacks();
	system("pause");
	Algorithms();
	system("pause");
	return 0;
}

template <typename Cont>
void printOut(const Cont& C)
{
	for (size_t i = 0; i < C.size(); ++i)
		std::cout << ' ' << C[i];
	std::cout << '\n';
}

void Containers()
{
	cout << typeid(Array<int>::Iterator::difference_type).name() << '\n';
	Array<int> A;
	//DblList<int> A;
	cout << A;
	cin.get();
	A.putLast(10).showOn(cout);
	cin.get();
	A.putLast(20).showOn(cout);
	cin.get();
	A.putLast(30).putLast(40).putLast(50).showOn(cout);
	cin.get();
	Array<int> D(A);
	//DblList<int> D(A);
	D.showOn(cout);
	cin.get();
	A.clear().putLast(123).showOn(cout);
	cin.get();
	Array<double> B(5, 1.5);
	//DblList<double> B(5, 1.5);
	B.showOn(cout);
	cin.get();
	float c[5] = { 3.1F, 3.5F, -0.4F, 7.25F };
	Array<float> C(c, 5);
	//DblList<float> C(c, 5);
	C.showOn(cout);
	cin.get();
	C.put(6.4F, 2);
	cout << C;
	cout << '\t' << C.get(5) << '\n';
	cout << C;
	cin.get();
	std::swap(C.front(), C.back());
	printOut(C);
	cin.get();
	Array<float>::Iterator it = C.begin();
	//DblList<float>::Iterator it = C.begin();
	while (it != C.end())
	{
		cout << '\t' << *it++;
	}
	cout << '\n';
	cin.get();
	D = A;
	D.showOn(cout);
	cin.get();
	cout << "Input size n and n integers: ";
	cin >> D; cin.get();
	cout << D;
	cin.get();
	cout << "Input two integers: ";
	int u, v; cin >> u >> v; cin.get();
	D.putFirst(v).putFirst(u);
	for (size_t i = 0; i < D.size(); ++i) cout << '\t' << D[i];
	cout << '\n';
	cin.get();
	for (size_t i = 0; i < D.size(); ++i) D[i] += 5;
	cout << D;
	cin.get();
	while (D.size() > 0) cout << '\t' << D.getLast();
	cout << '\n';
	cin.get();
}
void Stacks()
{
	Stack<int> S;
	if (S.isEmpty()) cout << "Stack is empty\n";
	else cout << "Stack contains something\n";
	S.push(5);
	if (S.isEmpty()) cout << "Stack is empty\n";
	else cout << "Stack contains something: " << S.peek() << '\n';
	cin.get();
	const int n = 4;
	int a[n] = { 1, 2, 3 };
	for (int i = 0; i < n; ++i)
	{
		S.push(a[i]);
		cout << '\t' << a[i];
	}
	cout << '\n' << S.peek() << '\n';
	cin.get();
	S.peek() = n;
	while (!S.isEmpty())
		cout << '\t' << S.pop();
	cout << '\n';
	cin.get();

	Stack<int, Array> T;
	if (T.isEmpty()) cout << "Stack is empty\n";
	else cout << "Stack contains something\n";
	T.push(5);
	if (T.isEmpty()) cout << "Stack is empty\n";
	else cout << "Stack contains something: " << T.peek() << '\n';
	cin.get();
	for (int i = 0; i < n; ++i)
	{
		T.push(a[i]);
		cout << '\t' << a[i];
	}
	cout << '\n' << T.peek() << '\n';
	cin.get();
	T.peek() = n;
	while (!T.isEmpty())
		cout << '\t' << T.pop();
	cout << '\n';
	cin.get();
}

void Algorithms()
{
	const int n = 5;
	int a[n] = { 1, 2, 3, 4, 5 };
	vector<int> v(a, a + n);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	cin.get();
	Array<int> A(a, n);
	cout << A;
	cin.get();
	A.putLast(17);
	copy(A.begin(), A.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	cin.get();
	//copy(v.rbegin(), v.rend(), A.begin());
	A.clear();
	copy(v.rbegin(), v.rend(), back_inserter(A));
	copy(A.begin(), A.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	cin.get();
	copy(v.begin(), v.end(), back_inserter(A));
	copy(A.begin(), A.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	cin.get();
	sort(A.begin(), A.end());
	copy(A.begin(), A.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	cin.get();
	DblList<int> B(2);
	copy(A.begin(), A.end(), front_inserter(B));
	copy(B.begin(), B.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	cout << B << '\n';
	cin.get();
	LinkedList<double> L(5);
	copy(L.begin(), L.end(), ostream_iterator<double>(cout, "\t"));
	cout << endl;
	cin.get();
	DblList<int>::Node<int> node(9);
	LinkedList<double>::Node lode(5.5);
	DblList<double>::Node<double> dode(3.25);
	cout << node.data << ' ' << lode.data << ' ' << dode.data << '\n';
	cin.get();
}