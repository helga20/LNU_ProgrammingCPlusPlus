#include "Human.h"
using std::cout;

int main()
{
	Student<int> Gen("Programmer Bill", Male, "2700120c");
	Gen.setPoint(99, 0).setPoint(85, 1).setPoint(93, 2);
	Student<std::string> Ukr("Mathematiсian Banakh", Male, "2700251c");
	Ukr.setPoint("good", 0).setPoint("excellent", 1).setPoint("excellent", 2);
	Student<Point> Euro("Analysist Julia", Female, "2701331c");
	Euro.setPoint(98, 0).setPoint(86, 1).setPoint(91, 2);
	cout << " --- Our students are:\n" << Gen << '\n' << Ukr << '\n' << Euro << '\n';
	system("pause");
    return 0; 
}

