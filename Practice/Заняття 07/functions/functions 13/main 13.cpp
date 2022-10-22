#include <iostream>
#include <math.h>
#include "functions 13.h"
using namespace std;

int main()
{
	cout << "Task 13\n";
	double a, h; int n;
	cout << "Enter a: "; cin >> a;
	cout << "Enter h: "; cin >> h;
	cout << "Enter n: "; cin >> n;
	double task13 = task13y(a + (2 * (double)n * h));
	cout << "Result: " << task13 << "\n";

    system("pause");
    return 0;
}