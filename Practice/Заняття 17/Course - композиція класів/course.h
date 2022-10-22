#pragma once
#include <string>
#include <iostream>
#include "prof.h"

class Course
{
private:
	std::string courseName;
	Person* courseTeacher;
	int courseHours;

public:
	Course();
	Course(const std::string& name, Person* teacher, int hours);
	Course(const Course& C);
	~Course();

	void printInfo() const;
	const std::string& getCourseName() const;
	int getCourseHours() const;

	void printTeacherInfo() const;
	Person* getCourseTeacher() const;

	void setCourseName(const std::string& name);
	std::string& getCourseName();

	void setCourseTeacher(Person* teacher);
	Person*& getCourseTeacher();

	void readFrom(std::istream& in);
	void writeTo(std::ostream& out) const;

};

std::istream& operator >> (std::istream& in, Course& C);
std::ostream& operator << (std::ostream& out, const Course& C);
