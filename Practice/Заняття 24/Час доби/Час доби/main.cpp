#include <iostream>
#include "timeOfDay.h"
#include "exactTimeOfDay.h"
#include <algorithm>
#include <vector>
#include "functions.h"
using namespace std;
int main()
{
	TimeOfDay T1(10, 20);
	TimeOfDay T2(12, 50);

	cout << "\nTime of day:\n";
	T1.printTimeOfDay(); cout << "\n";
	T2.printTimeOfDay(); cout << "\n";
	cout << "\n-----------------------------------\n";

	ExactTimeOfDay ET1;
	ExactTimeOfDay ET2(T1, 25);
	ExactTimeOfDay ET3(15, 20, 5);
	ExactTimeOfDay ET4(ET2);
	ExactTimeOfDay ET5;
	ET5.readExactTimeOfDay();
	cout << "\nExact time of day:\n";
	ET1.printExactTimeOfDay();
	ET2.printExactTimeOfDay();
	ET3.printExactTimeOfDay();
	cout << "Just times: "; ET4.printTimeOfDay(); cout << "; "; ET5.printTimeOfDay(); cout << "\n";
	cout << "\n-----------------------------------\n";

	vector<TimeOfDay> myTime; readTimeFromFile(myTime, "time.txt");
	TimePrinterClass timePrinter;
	for_each(myTime.cbegin(), myTime.cend(), timePrinter); cout << "\n";
	for_each(myTime.cbegin(), myTime.cend(), [](const TimeOfDay& hm) { cout << hm << "\n"; }); cout << "\n";
	cout << "______________________________________\n\n";

	//vector<ExactTimeOfDay> myT; readTimeFromFile(myT, "time.txt");
	//ExactTimeOfDay exactPrinter;
	//for_each(myT.cbegin(), myT.cend(), exactPrinter); cout << "\n";
	//for_each(myT.cbegin(), myT.cend(), [](const ExactTimeOfDay& time) { cout << time << "\n"; }); cout << "\n";
	//cout << "______________________________________\n\n";


	system("pause");
	return 0;
}