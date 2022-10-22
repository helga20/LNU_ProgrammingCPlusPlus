#include <iostream>
#include "date.h"
#include "weekday.h"
#include "holiday.h"
#include "time.h"
#include "datetime.h"
using namespace std;
int main()
{
	Date D1(18, 3, 2021);
	Date D2(2, 5, 2021);
	//D2.readDate();

	cout << "\nAll dates:\n";
	D1.printDate(); cout << "\n";
	D2.printDate(); cout << "\n";
	cout << "\n-----------------------------------\n";

	Time T1(11, 39);
	Time T2;
	//T2.readTime();

	cout << "\nAll times:\n";
	T1.printTime(); cout << "\n";
	T2.printTime(); cout << "\n";
	cout << "\n-----------------------------------\n";

	DateTime DT1;
	DateTime DT2("Thursday", D1, T1);
	DateTime DT3("Monday", 17, 5, 2021, 14, 15);
	//DateTime DT4(DT2);
	//DateTime DT5;
	//DT5.readDateTime();
	cout << "\nAll calendar days:\n";
	DT1.printDateTime();
	DT2.printDateTime();
	DT3.printDateTime();
	//cout << "Just dates: "; DT4.printDate(); cout << "; "; DT5.printDate(); cout << "\n";
	//cout << "Just times: "; DT4.printTime(); cout << "; "; DT5.printTime(); cout << "\n";
	cout << "\n-----------------------------------\n";

	Date* date1 = &DT1;
	Date* date2 = new Date(2, 2, 2021);
	Time* time1 = &DT1;
	Time* time2 = new Time(1, 1);
	date1->printDate(); cout << "\n";
	date2->printDate(); cout << "\n";
	time1->printTime(); cout << "\n";
	time2->printTime(); cout << "\n";


	/*
	WeekDay W1;
	WeekDay W2("Thursday", D1);
	WeekDay WE("Sunday", 2, 5, 2021);
	WeekDay W3(W2);
	//WeekDay W4;
	//W4.readWeekDay();

	cout << "\nAll week days:\n";
	W1.printWeekDay();
	W2.printWeekDay();
	WE.printWeekDay();
	W3.printWeekDay();
	//W4.printWeekDay();
	cout << "\n-----------------------------------\n";

	Holiday NewYear;
	Holiday Easter("Easter", D2);
	Holiday Indep("Independence Day", 24, 8, 2021);
	Holiday EasterCopy(Easter);
	Holiday BirthDay;
	//BirthDay.readHoliday();

	cout << "\nAll holidays:\n";
	NewYear.printHoliday();
	Easter.printHoliday();
	Indep.printHoliday();
	EasterCopy.printHoliday();
	//BirthDay.printHoliday();
	cout << "\n-----------------------------------\n";
	*/

	return 0;
}