#include <iostream>
using namespace std;
int main()
{
    /*Task 3*/
	int n;
	cout << "Enter n: "; cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	cout << "Enter arrays a\n";
	for (int i = 0; i < n; ++i)
	{
		cout << "a[" << i << "]: "; cin >> a[i];

		if (a[i] <= 0) {
			b[i] = a[i] * 10;
		}
		else if (a[i] > 0) {
			b[i] = 0;
		}
		cout << "b[" << a[i] << "]: " << b[i] << endl;
	}
	system("pause");
	return 0;
}
