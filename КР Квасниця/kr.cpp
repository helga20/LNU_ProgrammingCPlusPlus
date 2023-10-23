#include <iostream>
using namespace std;

void Zavd1() 
{
	double y = 99;
	for (int i = 96; i >= 3; i-=3)
	{
		y = sqrt(y) + i;
	}
	cout << y;
	return;
}

void Zavd2()
{
	double eps, a, b, h;
	cin >> eps >> a >> b >> h;
	double x = a;

	while (x <= b)
	{
		double sum = 0;
		double y = -(x*x*x*x) / 162;
		int k = 0;

		while (abs(y) > eps)
		{
			sum += y;
			y *= -(x*x*x*x) / 81 / (k + 1);
			++k;
		}

		cout << "x = " << x << "\t s = " << sum << '\n';
		x += h;
	}

	return;
}

void Zavd3(void)
{
	int n;
	bool t = 1, dod, prevdod;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	dod = (arr[0] > 0);
	if (!arr[0])
	{
		t = false;
		cout << t;
		return;
	}

	for (int i = 1; i < n; ++i)
	{
		if (!arr[i])
		{
			t = 0;
			break;
		}
		prevdod = dod;
		dod = (arr[i] > 0);
		if (prevdod == dod)
		{
			t = 0;
			break;
		}
	}

	cout << t;
	return;
}

int main(void)
{
	cout << "/t/t ZAVD #1" << endl;
	Zavd1();

	cout << "/t/t ZAVD #2" << endl;
	Zavd2();

	cout << "/t/t ZAVD #3" << endl;
	Zavd3();
	return 0;
}