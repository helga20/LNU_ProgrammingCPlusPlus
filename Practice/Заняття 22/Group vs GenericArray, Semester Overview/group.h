#pragma once
#include "prof.h"
#include "student.h"
#include "genericarray.h"

class Group
{
private:
	Prof groupLead;
	GenericArray<Student> groupMembers;

public:
	Group();
	Group(const Prof& lead, int nofStudents);
	~Group();

	void setGroupLead(const Prof& P);
	void addStudent(const Student& S);
	void printGroupInfo() const;

	void deleteStudent_1(const std::string& surname);
	void deleteStudent_2(const std::string& surname);

	void readFromFile(const std::string& fileName);

	double groupScore() const;
	const Student& getMaxStudent() const;
};