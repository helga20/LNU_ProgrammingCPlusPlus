////Завдання 1 а, б
//#include <iostream>
//using namespace std;
//int main()
//{
//	int x, y;
//	cout << "x= ";
//	cin >> x;
//	cout << "y= ";
//	cin >> y;
//
//
//	if (x > y) {
//		cout << "max = " << x << endl;
//	}
//	if (x < y) {
//		cout << "max= " << y << endl;
//	}
//	else {
//		cout << "x=y" << endl;
//	}
//	system("pause");
//	return 0;
//}

////Завдання 1 в
//#include <iostream>
//using namespace std;
//int main()
//{
//	int x, y, z;
//	cout << "x= ";
//	cin >> x;
//	cout << "y= ";
//	cin >> y;
//	cout << "z= ";
//	cin >> z;
//	if (x > y && x > z) {
//		cout << "max= " << x << endl;
//	}
//	else if (y > z && y > z) {
//		cout << "max= " << y << endl;
//	}
//	else if (z > y && z > x)
//	{
//		cout << "max= " << z << endl;
//	}
//	else {
//		cout << "There is no max number\n";
//	}
//
//}
//system("pause");
//return 0;
//}

///*Завдання 1 д*/
//#include <iostream>
//using namespace std;
//int main()
//{
//    int x, y, z, a, b;
//    cout << "x= ";
//    cin >> x;
//    cout << "y= ";
//    cin >> y;
//    cout << "z= ";
//    cin >> z;
//    a = x + y + z;
//    b = x * y * z;
//
//    if (a < b && b > a)
//    {
//        cout << "max mult = " << b << endl;
//    }
//    if (a > b && a > b)
//    {
//        cout << "max sum = " << a << endl;
//    }
//
//    system("pause");
//    return 0;
//}

//	/*Завдання 1 е*/
//#include <iostream>
//using namespace std;
//int main()
//{
//	int x, y, z, a, b, c;
//	cout << "x= ";
//	cin >> x;
//	cout << "y= ";
//	cin >> y;
//	cout << "z= ";
//	cin >> z;
//	a = x + y + z / 2;
//	b = x * y * z;
//	if (a > b)
//	{
//		c = b * b + 1;
//		cout << "min^2+1= " << c << "\n";
//	}
//	else if (a < b)
//	{
//		c = a * a + 1;
//		cout << "min^2+1= " << c << "\n";
//	}
//	else
//	{
//		cout << "a== b\n";
//	}
//
//system("pause");
//return 0;
//}

////Завдання 2
//#include <iostream>
//using namespace std;
//int main()
//{
//    int a, b, c;
//    cout << "Enter a: " << endl;
//    cin >> a;
//    cout << "Enter b: " << endl;
//    cin >> b;
//    cout << "Enter c: " << endl;
//    cin >> c;
//    if (a >= b && b >= c)
//    {
//        a = a * 2;
//        b = b * 2;
//        c = c * 2;
//    }
//    else if (a < b && b < c)
//    {
//        a = a + 5;
//        b = b + 5;
//        c = c + 5;
//    }
//    cout << "a: " << a << endl;
//    cout << "b: " << b << endl;
//    cout << "c: " << c << endl;
//    system("pause");
//    return 0;
//}

////Завдання 3
//#include <iostream>
//using namespace std;
//int main()
//{
//    int x, y, z;
//    cout << "Enter x: " << endl;
//    cin >> x;
//    cout << "Enter y: " << endl;
//    cin >> y;
//    {
//        if (x > y)
//        {
//            z = x - y;
//            cout << "z: " << z << endl;
//        }
//        else
//        {
//            z = y - x + 1;
//            cout << "z: " << z << endl;
//        }
//        system("pause");
//        return 0;
//    }
//    }

////Завдання 4
//#include <iostream>
//using namespace std;
//int main()
//{
//	int a, b, c;
//    cout << "Enter a: " << endl;
//    cin >> a;
//    cout << "Enter b: " << endl;
//    cin >> b;
//    cout << "Enter c: " << endl;
//    cin >> c;
//    if (a >= 1 && a <= 5)
//    {
//        cout << "a: " << a << endl;
//    }
//    if (b >= 1 && b <= 5)
//    {
//    cout << "b: " << b << endl;
//    }
//    else if (c >= 1 && c <= 5)
//    {
//    cout << "c: " << c << endl;
//    }
//	system("pause");
//	return 0;
//}

////Завдання 5 a
//#include <iostream>
//using namespace std;
//int main()
//{
//    int x,y;
//    cout << "Enter x: " << endl;
//    cin >> x;
//    {
//        if (x >= -2 && x < 2)
//        {
//            y=x*x;
//            cout << "y= " << y << endl;
//        }
//        else
//        {
//            y = 4;
//            cout << "y= " << y << endl;
//        }
//        system("pause");
//        return 0;
//    }
//    }

////Завдання 5 б
//#include <iostream>
//using namespace std;
//int main()
//{
//    double x,y;
//    cout << "Enter x: " << endl;
//    cin >> x;
//    {
//        if (x <= 2)
//        {
//            y = x * x + 4 * x + 5;
//            cout << "y= " << y << endl;
//        }
//        else 
//        {
//            y = 1 /(x * x + 4 * x + 5);
//            cout << "y= " << y << endl;
//        }
//        system("pause");
//        return 0;
//    }
//}

////Завдання 5 в
//#include <iostream>
//using namespace std;
//int main()
//{
//    int x,y;
//    cout << "Enter x: " << endl;
//    cin >> x;
//    {
//        if (x <= 0)
//        {
//            y= 0;
//            cout << "y= " << y << endl;
//        }
//        if (x <= 1 && x > 0)
//        {
//            y=x;
//            cout << "y= " << y << endl;
//        }
//        else
//        {
//            y = x*x*x*x;
//            cout << "y= " << y << endl;
//        }
//        system("pause");
//        return 0;
//    }
//}

////Завдання 6
//#include <iostream>
//using namespace std;
//int main()
//{
//    int a;
//    cout << "Enter a: " << endl;
//    cin >> a;
//    {
//        if (a % 2 == 0){
//            cout << "Chyslo parne " <<endl;
//        }
//        else
//        {
//            cout << "Chyslo neparne " << endl;
//        }
//        system("pause");
//        return 0;
//    }
//}
