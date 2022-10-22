////Завдання 1 а
//#include <iostream>
//using namespace std;
//int main()
//{
//  int i, n, a;
//  cout << "Enter n" << endl;
//  cin >> n;
//  a = 2;
//  for (i = 0; i < n-1 ; ++i)           
//  {
//    a= a* 2;
//  }
//  cout << "2^a= " <<a<< endl;
//  system("pause");
//  return 0;
//}


////Завдання 1 б
//#include <iostream>
//using namespace std;
//int main()
//{
//	cout << "Input n (n > 0): ";
//	unsigned n;  cin >> n;
//	unsigned long long f = 1ULL;
//	for (unsigned i = 2; i <= n; ++i) f *= i;
//	cout << n <<  "!= " <<f<< endl;
//	system("pause");
//	return 0;
//}

////Завдання 1 в
//#include <iostream>
//using namespace std;
//int main()
//
//{
//    double i, n, x;
//    cout << "Enter n: " << endl;
//    cin >> n;
//    x = 1;
//    for (int i = 1; i <= n; i++)              
//    {
//        x = (1 + (1 / i * i) * x);
//    }
//    cout << "x= " <<x<< endl;
//    system("pause");
//    return 0;
//}

////Завдання 1 г
//#include <iostream>
//using namespace std;
//int main()
//{
//    int n;
//    cout << "Enter n: " << endl;
//    cin >> n;
//    double S = 0, d = 0;
//    for (int i = 1; i <= n; ++i)              
//    {
//        d += sin(i);
//        S += 1 / d;
//    }
//    cout << "S= " <<S<< endl;
//    system("pause");
//    return 0;
//}

////Завдання 2 а
//#include <iostream>
//using namespace std;
//int main()
//{
//    int i, n, a, b, m;
//    cout << "Enter a: " << endl;
//    cin >> a;
//    cout << "Enter n: " << endl;
//    cin >> n;
//    m = a;
//    for (i = 0; i < n - 1; ++i)
//    {
//        m*= a;
//    }
//    cout << m << endl;
//    system("pause");
//    return 0;
//}

////Завдання 2 б
//#include <iostream>
//using namespace std;
//int main()
//{
//    double a;
//    int n;
//    cout << "Enter a: " << endl;
//        cin >> a;
//        cout << "Enter n: " << endl;
//        cin >> n;
//    double summa = 0;
//    double iteration = 1;
//    for (int i = 0; i < n; ++i)
//    {
//        iteration *= (a + i-1);
//        summa += iteration;
//    }
//    cout << summa;
//    system("pause");
//    return 0;
//}

////Завдання 2 в
//#include <iostream>
//using namespace std;
//int main()
//{
//    double a;
//    int n;
//    cout << "Enter a: " << endl;
//    cin >> a;
//    cout << "Enter n: " << endl;
//    cin >> n;
//    double summa = 0;
//    double iteration = 1;
//    for (int i = 0; i < n; ++i) {
//
//        iteration *= 1 / (a + n - 1);
//
//        summa += iteration;
//
//    }
//    cout << summa;
//    system("pause");
//    return 0;
//}

//////Завдання 3
//#include <iostream>
//using namespace std;
//int main()
//{
//	int a, i = 1;
//	double x = 1;
//	cout << "Input a: ";
//	cin >> a;
//	while (x < a) {
//		x += 1. / i;
//		++i;
//	}
//	cout << "I= " << i << "\n";
//	system("pause");
//	return 0;
//}

////Завдання 4 а,б
//#include <iostream>
//using namespace std;
//int main()
//{
//	int n;
//	double x, a = 0, b = 1, d = 0, c = 1;
//	cout << "n: ";
//	cin >> n;
//	cout << "a: ";
//	cin >> x;
//	for (int i = 1; i <= n; ++i)
//	{
//		c *= sin(x);
//		a += c;
//		b *= x;
//		d += sin(b);
//	}
//	cout << "(a):(sin(x))^n= " << a << "\n";
//	cout << "(b):(sin(x^n))= " << d << "\n";
//	system("pause");
//	return 0;
//}

//Завдання 5
#include <iostream>
using namespace std;
int main()
{
	int n;
	double a = 1, i;
	cout << "n: " << endl;
	cin >> n;
	for (i = 1; i <= n; ++i)
	{
		a = i * a + 1 / i;
	}
	cout << "a(n)= " << a << endl;
	system("pause");
	return 0;
}

////Завдання 6
//#include <iostream>
//using namespace std;
//int main()
//{
//	double x = 0, y = 0, z = 0, n = 1, s, q = 1, r = 1;
//	/*double с = 1, d = 1, q = 1, r = 1, b = 1, n = 1;*/
//	int i, f;
//	for (i = 1; i <= n; ++i)
//	{
//		x += (i + 1) / (i + 2);
//	}
//	cout << "xn= " << x << "\n";
//	system("pause");
//	return 0;
//}

////Завдання 7 а
//#include <iostream>
//using namespace std;
//int main()
//{
//	double x = 0;
//	int i;
//	for ( i = 1; i <= 100; ++i)
//	{
//		x += 1. / (i * i);
//	}
//	cout << "(7a)= " << x << "\n";
//	system("pause");
//	return 0;
//}

////Завдання 7 б
//#include <iostream>
//using namespace std;
//int main()
//{
//	double x = 0;
//	int i;
//	for (i = 1; i <= 50; ++i)
//	{
//		x += 1. / (i * i * i);
//	}
//	cout << "(7b)= " << x << "\n";
//	system("pause");
//	return 0;
//}

////Завдання 7 в
//#include <iostream>
//using namespace std;
//int main()
//{
//	double x = 0;
//	int i;
//	for (i = 1; i <= 128; ++i)
//	{
//		x += 1. / (2 * i) * (2 * i);
//	}
//	cout << "(7B)= " << x << "\n";
//	system("pause");
//	return 0;
//}

////Завдання 7 г
//#include <iostream>
//using namespace std;
//int main()
//{
//	double x = 1;
//	int i;
//	for (i = 2; i <= 100; ++i)
//	{
//		x *= (i+1.)/(i+2.);
//	}
//	cout << "(7h)= " << x << "\n";
//	system("pause");
//	return 0;
//}

////Завдання 7 д
//#include <iostream>
//using namespace std;
//int main()
//{
//	double x = 1;
//	int i;
//	for (i = 2; i <= 100; ++i)
//	{
//		x *= (1 - 1. / i) * (1 - 1. / i);
//	}
//	cout << "(7d)= " << x << "\n";
//	system("pause");
//	return 0;
//}

