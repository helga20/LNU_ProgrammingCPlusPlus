////Завдання 1 а
//#include <cmath>
//#include <iostream>
//using namespace std;
//int main()
//{
//    int n;
//    cin >> n;
//    int c = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        int a;
//        cin >> a;
//        if (a % 2 != 0)
//        {
//           c += 1;
//        }
//    }
//    cout << "k-st " << c << endl;
//    return 0;
//}

////Завдання 1 б
//#include <cmath>
//#include <iostream>
//using namespace std;
//int main()
//{
//    int n;
//    cin >> n;
//    int c = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        int a;
//        cin >> a;
//        if (a % 2 == 0)
//        {
//            c += 1;
//        }
//    }
//    cout << "k-st " << c << endl;
//    return 0;
//}

////Завдання 1 в 
//#include <cmath>
//#include <iostream>
//using namespace std;
//int main()
//{
//    int n;
//    cin >> n;
//    int c = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        int a;
//        cin >> a;
//        if (a < 0)
//        {
//            c += 1;
//        }
//    }
//    cout << "k-st " << c << endl;
//    return 0;
//}

////Завдання 1 г 
//#include <cmath>
//#include <iostream>
//using namespace std;
//int main()
//{
//    int n;
//    cin >> n;
//    int c = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        int a;
//        cin >> a;
//        if (a % 2 == 0 && a != 5)
//        {
//            c += 1;
//        }
//    }
//    cout << "k-st " << c << endl;
//    return 0;
//}

////Завдання 2 а
//#include <iostream>
//using namespace std;
//int main()
//{
//    int n;
//    cin >> n;
//    double sumA = 0;
//    bool isPositive = false;
//    for (int i = 1; i < n; ++i)
//    {
//        double a;
//        cin >> a;
//        if (a > 0)
//        {
//            isPositive = true;
//            sumA += a;
//        }
//    }
//    if (isPositive == true)
//    {
//        cout << "Sum: " << sumA << endl;
//    }
//    else
//    {
//        cout << "No positive elements, no sum" << endl;
//    }
//    return 0;
//}


////Завдання 2 в
//#include <iostream>
//using namespace std;
//int main()
//{
//    int n;
//    cin >> n;
//    double sumA = 0;
//    int a;
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> a;
//        if (a % 3 == 0)
//        {
//            sumA += a; 
//        }
//        else
//        {
//            cout << "The number is not a multiple of 3" << endl;
//        }
//    }   
//    double result = sumA;
//    cout << "Task 4b: " << result << endl;
//    return 0;
//}


////Завдання 2 г
//#include <iostream>
//using namespace std;
//int main()
//{
//    int n;
//    cin >> n;
//    double sumA = 0;
//    bool isPositive = false;
//    for (int i = 0; i < n; ++i)
//    {
//        double a;
//        cin >> a;
//        if (a > 0)
//        {
//            isPositive = true;
//            sumA += a*2;
//        }
//    }
//    if (isPositive == true)
//    {
//        cout << "Sum: " << sumA << endl;
//    }
//    else
//    {
//        cout << "No positive elements, no sum" << endl;
//    }
//    return 0;
//}


////Заддання 2 ж
//#include <iostream>
//#include <cmath>
//using namespace std;
//int main()
//{	
//	int n; cin >> n; 
//	double b;	cin >> b;
//	double minB = abs(b);
//	for (int i = 1; i < n; ++i)
//	{
//		double a; cin >> a;
//		if (a > 1)
//		{
//			b = a;
//		}
//		else
//		{
//			b = 2;
//		}
//		if (abs(b) < minB)
//		{
//			minB = abs(b);
//		}
//	}    cout << "Min of |b|: " << minB << endl;
//	system("pause");
//	return 0;
//}

////Завдання 2 д
//#include <iostream>
//using namespace std;
//int main()
//{
//	int n; cin >> n;
//	double b;	cin >> b;
//	double sumB = b;
//	for (int i = 1; i < n; ++i)
//	{
//		double a; cin >> a;
//		if (a < 10 && a>0)
//		{
//			b = a;
//		}
//		else
//		{
//			b = 1;
//		}
//		sumB += b;
//	}    cout << "b1+bn= " << sumB << endl;
//	system("pause");
//	return 0;
//}



