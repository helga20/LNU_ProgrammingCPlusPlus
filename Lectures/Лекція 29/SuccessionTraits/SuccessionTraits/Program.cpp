#include <algorithm>
#include <iterator>
#include "TraitsTemplates.h"
#include "Traits.h"
using namespace std;

int main()
{
	// створення контейнерів
	int source[] = {3, 14, 15, 9, 2, 65, 35, 89, 7, 9, 3};
	const int n = sizeof source / sizeof *source;
	vector<int> A(source, source + n);
	list<int> B(source, source + n);
	B.sort();
	deque<double> C(A.rbegin(), A.rend());
	vector<double> D(C.cbegin(), C.cend());
	set<int> S(A.begin(), A.end());
	multiset<int> M(A.begin(), A.end());
	forward_list<int> F(source, source + n);

	// виведення за допомогою алгоритмів
	cout << " * Vector of integers *\n";
	copy(A.begin(), A.end(), ostream_iterator<int>(cout, "\t"));
	cout << "\n\n * Sorted list of integers *\n";
	copy(B.begin(), B.end(), ostream_iterator<int>(cout, "\t"));
	cout << "\n\n * Reversed deque of integers *\n";
	copy(C.begin(), C.end(), ostream_iterator<int>(cout, "\t"));
	cout << "\n\n * Set of integers *\n";
	copy(S.begin(), S.end(), ostream_iterator<int>(cout, "\t"));
	cout << "\n\n * Sorted bag of integers *\n";
	copy(M.begin(), M.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;
	cin.get();
	// шаблонна функція для класів
	PrintSuccession<int>(A);
	PrintSuccession<int>(B);
	PrintSuccession<double>(C);
	PrintSuccession<double>(D);
	PrintSuccession<int>(S);
	PrintSuccession<int,multiset<int>,SuccessionTraits<int,set<int>>>(M);
	cin.get();
	PrintContainer(A);
	PrintContainer(D);
	cin.get();
	// шаблонна функція для шаблонів
	PrintSucc(A);
	PrintSucc(B);
	PrintSucc(C);
	PrintSucc(F);
	vector<float> E;
	PrintSucc(E);
	cin.get();
	return 0;
}