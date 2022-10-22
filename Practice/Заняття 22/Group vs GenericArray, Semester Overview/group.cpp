#include "group.h"
#include <fstream>
using namespace std;

Group::Group()
	: groupLead(), groupMembers(5)
{}

Group::Group(const Prof& lead, int nofStudents)
	: groupLead(lead), groupMembers(nofStudents)
{}

Group::~Group()
{}

void Group::setGroupLead(const Prof& P)
{
	groupLead = P;
}

void Group::addStudent(const Student& S)
{
	groupMembers.addElem(S);
}

void Group::printGroupInfo() const
{
	cout << "Group Info\n\n";
	groupLead.printPersonInfo();
	cout << "\nStudents Info\n";
	groupMembers.printArray();
	cout << "\n---------------------------------------------\n";
}

void Group::deleteStudent_1(const std::string& surname)
{
	// GenericArray<>::operator[]
	// find index of Student with surname
	int studIndex;
	for (studIndex = 0; studIndex < groupMembers.getElementCount(); ++studIndex)
	{
		if (groupMembers[studIndex].getSurname() == surname)
			break;
	}

	if (studIndex == groupMembers.getElementCount())
		return; // no such Student in group

	groupMembers.deleteElem(studIndex);
}

void Group::deleteStudent_2(const std::string& surname)
{
	// GenericArray<>::findElement() + Student::operator==
	int studIndex = groupMembers.findIndex(Student("", surname, 0));
	if (studIndex == -1)
		return;
	groupMembers.deleteElem(studIndex);
}

void Group::readFromFile(const std::string& fileName)
{
	ifstream iFile(fileName);
	iFile >> groupLead;
	groupMembers.readFromFile(iFile);
	iFile.close();
}

double Group::groupScore() const
{
	double totalSum = groupMembers[0].getMark();
	for (int i = 1; i < groupMembers.getElementCount(); ++i)
	{
		totalSum += groupMembers[i].getMark();
	}
	return totalSum;
}

const Student& Group::getMaxStudent() const
{
	int maxIndex = 0;
	for (int i = 1; i < groupMembers.getElementCount(); ++i)
	{
		if (groupMembers[i].getMark() > groupMembers[maxIndex].getMark())
			maxIndex = i;
	}
	return groupMembers[maxIndex];
}