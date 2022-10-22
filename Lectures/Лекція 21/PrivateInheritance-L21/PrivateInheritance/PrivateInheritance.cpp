#include "pch.h"
#include <iostream>
#include "Date.h"
#include "Human.h"
#include "Person.h"
#include "Robotics.h"
#include "WorkerStudent.h"

int main()
{
	Date toDay = Date::DateToday();
	int k = toDay.DaysFromStart();
	std::cout << "Today " << toDay << "\n k = " << k << "\nRebuild " << Date(k) << '\n';
	std::cout << "Future: " << toDay + 25 << '\n';
	std::cout << "Programmer's day: " << Date(13, 9, 2019) - Date(31, 12, 2018) << '\n';
	system("pause");
	std::cout << "\n\n\n";
	Human baby;
	Human Ernest("Ernest Miller Hemingway", 21, 7, 1899);
	std::cout << baby << '\n';
	std::cout << Ernest << '\n';
	std::cout << "Human " << Ernest.Name() << " was born on " << Ernest.Birthday() << '\n';
	std::cout << "\n";
	Person pups;
	Person JackLondon("John Griffith Chaney", 12, 1, 1876);
	std::cout << pups << '\n';
	std::cout << JackLondon << '\n';
	std::cout << "Person " << JackLondon.Name() << " was born on " << JackLondon.Birthday() << '\n';
	system("pause");
	std::cout << "\n\n\n";
	Robot Roby;
	std::cout << Roby << '\n';
	Roby.doWork("Make a cup of coffee").doWork("Make a cake");
	std::cout << '\n';
	Robocop John("Judge Dredd", 11, 7, 1982);
	std::cout << John << '\n';
	John.doWork("Push the wall").doWork("Grab the criminal");
	John.say("Asta La Vista, BABY!");
	system("pause");
	std::cout << "\n\n\n";
	Worker worker("Winnie Pooh", 13, 9, 1926, 123456);
	Student stud("Alex", 1, 10, 1999);
	WorkingStudent Haster("Sent More Money", 2, 10, 1998, 2709876);
	std::cout << "Worker: " << worker << '\n';
	std::cout << "Student: " << stud << '\n';
	std::cout << "Working Student: " << Haster << '\n';
	system("pause");
	std::cout << "\n\n *** Check size of the objects!\n\n";
	std::cout << "Human size: " << sizeof(baby) << "   " << sizeof(Ernest) << '\n';
	std::cout << "Worker size: " << sizeof(worker) << "   " << sizeof((Human)worker) << '\n';
	std::cout << "Student size: " << sizeof(stud) << "   " << sizeof((Human)stud) << '\n';
	std::cout << "WorkingStudent size: " << sizeof(Haster) << "   " << sizeof((Human)Haster) << 
		"   " << sizeof((Worker)Haster) << "   " << sizeof((Student)Haster) << '\n';
	system("pause");
}
