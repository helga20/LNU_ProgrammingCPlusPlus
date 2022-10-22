#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "Header.h"

using namespace std;

int main()
{
	int arr[] = { 2, 0, 9, 8, 3, 5, 6, 1, 4, 7 };
	// Множини спеціально збудовано з частин масиву
	set<int> A(arr, arr + 7);
	set<int> B(arr + 4, arr + 10);
	ostream_iterator<int> out(cout, " ");

	// Вигляд вихідних множин
	cout << " A = { ";
	copy(A.begin(), A.end(), out);
	cout << "}\n";
	cout << " B = { ";
	copy(B.begin(), B.end(), out);
	cout << "}\n";

	// Чи належить arr[0] множинам?
	cout << arr[0] << " occures in A " << A.count(arr[0]) << " times.\n";
	if (B.find(arr[0]) != B.end()) cout << arr[0] << " belongs to B.\n";
	else cout << arr[0] << " not belongs to B.\n";

	// Виконання дій з множинами за допомогою алгоритмів
	set<int> C;
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(C, C.begin()));
	cout << "\n A * B = { ";
	copy(C.begin(), C.end(), out);
	cout << "}\n";

	set<int> D;
	set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(D, D.begin()));
	cout << " A + B = { ";
	copy(D.begin(), D.end(), out);
	cout << "}\n";

	set<int> E;
	set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(E, E.begin()));
	cout << " A - B = { ";
	copy(E.begin(), E.end(), out);
	cout << "}\n";

	system("pause");

	// ті ж дії за допомогою перевантажених операторів
	C.clear();
	C = A * B;
	cout << " A * B = { " << C << "}\n";

	D.clear();
	D = A + B;
	cout << " A + B = { " << D << "}\n";

	E.clear();
	E = A - B;
	cout << " A - B = { " << E << "}\n";

	system("pause");

	// сортування масиву за допомогою дерева (множини)
	cout << " *** The array before:\n";
	for (int i = 0; i < 10; ++i)
		cout << '\t' << arr[i];
	A.clear();
	A.insert(arr, arr + 10);
	copy(A.begin(), A.end(), arr);
	cout << "\n *** ... and after:\n";
	for (int i = 0; i < 10; ++i)
		cout << '\t' << arr[i];
	cout << endl;
	system("pause");

	return 0;
}