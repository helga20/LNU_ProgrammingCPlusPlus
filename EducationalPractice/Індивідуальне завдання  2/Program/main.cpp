#include <iostream>
#include "functions.h"
using namespace std;
int main()
{
	int n;
	cout << "Enter n (n>10) : " << endl;
	cin >> n;
	if (n <= 10)
	{
		cout << "Thanks. But please enter n>10 and try again!";
		return 0;
	}
	double* a = new double[n];
	double x;
	cout << "Enter x (x!=0) : " << endl;
	cin >> x;
	cout << "Thank you\n";

	function(a, n, x);

	int sum = 0;
	sum = sumArray( a, n, x);
	cout << "Sum: " << sum << "\n";

	int prod = 1;
	prod = prodArray(a, n, x);
	cout << "Product: " << prod << "\n";

	delete[] a;

	system("pause");
	return 0;
}