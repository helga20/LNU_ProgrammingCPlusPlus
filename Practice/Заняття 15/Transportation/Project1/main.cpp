#include<iostream>
#include "function.h"
#include "plane.h"
#include "train.h"
#include <fstream>
using namespace std;
int main()
{
	cout << "A trip by transport\n";

	Transportation T1("Stryi-", "Lviv", 6, 80);
	Transportation T2("Stryi-", "Lviv", 11, 80);
	cout << T1 << "\n"; cout << T2 << "\n";
	cout << "6 place: " << T1.getPrice() << "\n";
	cout << "11 place: " << T2.getPrice() << "\n";


	cout << "\nA trip by plane\n";

	Plane P1("Kharkiv-", "Lviv", 16, 2000, true);
	Plane P2("Kharkiv-", "Lviv", 16, 2000, false);
	cout << "Kharkiv-Lviv (+ food): " << P1.getPrice() << "\n";
	cout << "Kharkiv-Lviv: " << P2.getPrice() << "\n";


	cout << "\nA trip by train\n";

	Train V1("Kyiv-", "Kherson", 5, 500, 4);
	Train V2("Kyiv-", "Kherson", 5, 500, 16);
	cout << "Kyiv-Kherson(van<10): " << V1.getPrice() << "\n";
	cout << "Kyiv-Kherson(van<10): " << V2.getPrice() << "\n";
	system("pause");
	return 0;
}
