#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	double minA;
	cin >> minA;
	double maxA = minA;

	double prodA = 1.0;
	bool isNegative = false;
	if (minA < 0)
	{
		isNegative = true;
		prodA *= minA;
	}

	// b
	double b;
	if (abs(minA) <= 2)
	{
		b = minA;
	}
	else
	{
		b = 0.5;
	}
	double maxB = abs(b);
	double sumB = b;

	for (int i = 1; i < n; ++i)
	{
		double a;
		cin >> a;
		// min
		if (a < minA)
		{
			minA = a;
		}
		// max
		if (a > maxA)
		{
			maxA = a;
		}

		// product
		if (a < 0)
		{
			isNegative = true;
			prodA *= a;
		}

		// b
		if (abs(a) <= 2)
		{
			b = a;
		}
		else
		{
			b = 0.5;
		}
		// max |b|
		if (abs(b) > maxB)
		{
			maxB = abs(b);
		}
		sumB += b;

	}
	cout << "Min: " << minA << endl;
	cout << "Max: " << maxA << endl;

	if (isNegative == true)
	{
		cout << "Product: " << prodA << endl;
	}
	else
	{
		cout << "No negative elements, no Product" << endl;
	}

	cout << "Max of |b|: " << maxB << endl;
	

	return 0;
}