#include <iostream>
#include <fstream>
#include "prof.h"
#include "student.h"
#include "course.h"
using namespace std;

int main()
{
	ifstream iFile("courses.txt");
	int n; iFile >> n;
	Course* arr = new Course[n];
	for (int i = 0; i < n; ++i)
	{
		iFile >> arr[i];
	}
	iFile.close();

	ofstream oFile("course_copy.txt");
	oFile << n << '\n';
	cout << "Courses from file\n";
	for (int i = 0; i < n; ++i)
	{
		arr[i].printInfo();
		cout << "\n";

		oFile << arr[i] << '\n';
	}
	oFile.close();
	cout << "\n";
	delete[] arr;

	/*
	Prof P1("Sviatoslav", "Tarasiuk");
	Prof P2("Goshko", "Bohdan");
	Student S1("Igor", "Petrovych", 85.5);
	Person* S2 = new Student("Oksana", "Yaroshko", 86.1);

	Course C1;
	Course C2("MatAn", &P1, 120);
	Course C2_1("C++", new Prof("Anatoliy", "Muzychuk"), 200);
	Course C3("DyscrMat", &S1, 160);
	Course C3_1("Algorithms", S2, 110);

	cout << "All courses\n";
	C1.printInfo(); cout << "\n";
	C2.printInfo(); cout << "\n";
	C2_1.printInfo(); cout << "\n";
	C3.printInfo(); cout << "\n";
	cout << "!!!  "; C3_1.printInfo(); cout << "\n";
	cout << "\n";

	C3_1.setCourseName("");
	C3_1.getCourseName() = "NEW Python";
	cout << "Updates\n";
	C3_1.printInfo(); cout << "\n";
	cout << "\n";

	C3_1.setCourseTeacher(nullptr);
	C3_1.setCourseTeacher(&P2);
	C3_1.printInfo(); cout << "\n";
	cout << "\n";

	C3_1.setCourseTeacher(new Student("Olga", "Kravets", 95.5));
	C3_1.printInfo(); cout << "\n";
	cout << "\n";

	Person*& T3_1 = C3_1.getCourseTeacher();
	T3_1 = &P2;
	C3_1.printInfo(); cout << "\n";
	cout << "\n";

	
	cout << "Courses: " << C2.getCourseName() << "; " << C3.getCourseName() << "\n";
	cout << "Total hours: " << C2.getCourseHours() + C3.getCourseHours() << "\n";
	cout << "\n";

	cout << "Teacher:\n";
	C2.printTeacherInfo();
	cout << "\n";
	Person * T3 = C3.getCourseTeacher();
	if (T3 != nullptr)
	{
		cout << T3 << ": " << *T3 << "\n";
		//cout << T3->getSurname() << ":  ";
		//T3->workInfo();
	}
	else
	{
		cout << "Teacher no assigned\n";
	}
	*/
	
	cout << "\n";


	system("pause");
	return 0;
}