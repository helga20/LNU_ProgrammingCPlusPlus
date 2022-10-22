#include "course.h"
#include "prof.h"
#include "student.h"
using namespace std;

Course::Course()
	: courseName(), courseTeacher(nullptr), courseHours(0)
{}

Course::Course(const string& name, Person* teacher, int hours)
	: courseName(name), courseTeacher(teacher), courseHours(hours)
{}

Course::Course(const Course& C)
	: courseName(C.courseName), courseTeacher(C.courseTeacher), courseHours(C.courseHours)
{}

Course::~Course()
{}

void Course::printInfo() const
{
	if (courseTeacher == nullptr)
	{
		cout << "Invalid course (no teacher assigned)\n";
		return;
	}

	cout << "University course: " << courseName << " (" << courseHours << "h)" << "\n";
	courseTeacher->printPersonInfo();
}

const std::string& Course::getCourseName() const
{
	return courseName;
}

int Course::getCourseHours() const
{
	return courseHours;
}

void Course::printTeacherInfo() const
{
	if (courseTeacher == nullptr)
	{
		cout << "Invalid course (no teacher assigned)\n";
		return;
	}

	//courseTeacher.printPersonInfo();
	cout << *courseTeacher << "\n";
}

Person* Course::getCourseTeacher() const
{
	return courseTeacher;
}

void Course::setCourseName(const std::string& name)
{
	if (name.empty())
	{
		cout << "Error: course name is empty!\n";
		return;
	}

	courseName = name;
}

std::string& Course::getCourseName()
{
	return courseName;
}

void Course::setCourseTeacher(Person* teacher)
{
	if (teacher == nullptr)
	{
		cout << "Error: invalid teacher!\n";
		return;
	}

	courseTeacher = teacher;
}

Person*& Course::getCourseTeacher()
{
	return courseTeacher;
}

void Course::readFrom(std::istream& in)
{
	in >> courseName >> courseHours;
	char code; in >> code;
	if (code == 'P')
	{
		courseTeacher = new Prof();
		in >> *courseTeacher;
	}
	else if (code == 'S')
	{
		courseTeacher = new Student();
		in >> *courseTeacher;
	}
	else
	{
		in.ignore(256, '\n');
	}
}

void Course::writeTo(std::ostream& out) const
{
	if (courseTeacher == nullptr)
	{
		return;
	}

	out << courseName << ' ' << courseHours << '\n';
	out << courseTeacher->getType() << ' ' << *courseTeacher;
}

std::istream& operator >> (std::istream& in, Course& C)
{
	C.readFrom(in);
	return in;
}

std::ostream& operator << (std::ostream& out, const Course& C)
{
	C.writeTo(out);
	return out;
}