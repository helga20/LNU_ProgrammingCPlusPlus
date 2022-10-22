#include <iostream>
using namespace std;
int main()
{
	int n;
	double x, a = 0, b = 1;
	cout << "n: ";
	cin >> n;
	cout << "x: ";
	cin >> x;
	for (int i = 1; i <= n; ++i)
	{
		b *= sin(x);
		a += b;
	}
	cout << "(sin(x))^n= " << a << "\n";
	system("pause");
	return 0;
}

