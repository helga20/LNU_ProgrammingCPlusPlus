#include "group.h"
#include <iostream>
#include <fstream>
#include "prof.h"
#include "student.h"
using namespace std;

Group::Group()
	: groupName(), groupLeader(nullptr), groupMembers(nullptr), groupSize(0), groupCount(0)
{}

Group::Group(const std::string& name)
	: groupName(name), groupLeader(nullptr), groupMembers(nullptr), groupSize(0), groupCount(0)
{}

Group::Group(const std::string& name, Person* lead, int size)
	: groupName(name), groupLeader(lead), groupSize(size), groupCount(0), groupMembers(new Person*[size])
{
	//groupMembers = new Student[size]; // те саме що в списку ініціалізації (використовувати лише один спосіб)
}

Group::~Group()
{
	if (groupMembers != nullptr)
	{
		delete[] groupMembers;
	}
}

void Group::addMember(Person* member)
{
	if (groupSize == 0)
	{
		groupSize = 5;
		groupCount = 0;
		groupMembers = new Person*[groupSize];
	}
	else if (groupCount == groupSize)
	{
		int tempSize = groupSize + 5;
		Person** tempGroup = new Person * [tempSize];
		for (groupCount = 0; groupCount < groupSize; ++groupCount)
		{
			tempGroup[groupCount] = groupMembers[groupCount]->clone();
		}
		delete[] groupMembers;
		groupMembers = tempGroup;
	}

	groupMembers[groupCount] = member;
	++groupCount;
}

void Group::printGroupInfo() const
{
	cout << "Group: " << groupName << "\n";
	if (groupLeader != nullptr)
	{
		cout << "Leader: " << *groupLeader << "\n";
	}
	else
	{
		cout << "Leader: no leader\n";
	}
	
	cout << "Members (" << groupCount << "):\n";
	for (int i = 0; i < groupCount; ++i)
	{
		if (groupMembers[i] != nullptr)
		{
			cout << "   " << *groupMembers[i] << "\n";
		}		
	}
	cout << "\n";
}

void Group::setLeader(Person* lead)
{
	groupLeader = lead;
}

Person*& Group::getLeader()
{
	return groupLeader;
}

void Group::deleteMember(const std::string& surname)
{
	if (groupSize == 0 || groupCount == 0)
	{
		return;
	}

	for (int i = 0; i < groupCount; ++i)
	{
		if (groupMembers[i]->getSurname() == surname)
		{
			delete groupMembers[i];
			for (int j = i+1; j < groupCount; ++j)
			{
				groupMembers[i] = groupMembers[j];
				++i;
			}
			groupMembers[groupCount] = nullptr;
			--groupCount;
			return;
		}
	}
}

void Group::readGroupFromFile(const std::string& fileName)
{
	ifstream iFile(fileName);
	iFile >> groupName;

	char leadType; iFile >> leadType;
	if (leadType == 'P')
	{
		groupLeader = new Prof();
	}
	else
	{
		groupLeader = new Student();
	}
	iFile >> *groupLeader;

	iFile >> groupCount;
	
	groupSize = groupCount + 5;
	if (groupMembers != nullptr)
	{
		delete[] groupMembers;
	}

	groupMembers = new Person*[groupSize];
	for (int i = 0; i < groupCount; ++i)
	{
		char memberType; iFile >> memberType;
		if (memberType == 'S')
		{
			groupMembers[i] = new Student();
		}
		else
		{
			groupMembers[i] = new Prof();
		}
		iFile >> *groupMembers[i];
	}

	iFile.close();
}

void Group::writeGroupToFile(const std::string& fileName) const
{
	ofstream oFile(fileName);
	oFile << groupName << '\n';
	if (groupLeader != nullptr)
	{
		oFile << groupLeader->getType() << ' ' << *groupLeader << '\n';
	}
	else
	{
		throw "Error writing to file - no group leader.";
	}
	
	oFile << groupCount << '\n';
	for (int i = 0; i < groupCount; ++i)
	{
		oFile << groupMembers[i]->getType() << ' ' << *groupMembers[i] << '\n';
	}

	oFile.close();
}

Person*& Group::findBestMember() const
{
	if (groupCount == 0)
	{
		throw "Empty members list!";
	}

	int maxIndex = 0;
	for (int i = 1; i < groupCount; ++i)
	{
		if (groupMembers[i]->getMark() > groupMembers[maxIndex]->getMark())
		{
			maxIndex = i;
		}
	}

	return groupMembers[maxIndex];
}

double Group::totalMark() const
{
	double total = 0.;
	for (int i = 0; i < groupCount; ++i)
	{
		total += groupMembers[i]->getMark();
	}
	return total;
}

double Group::averageTotalMark() const
{
	if (groupCount == 0)
	{
		return 0.;
	}

	double totMark = totalMark();
	return totMark / (double)groupCount;
}
