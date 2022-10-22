#pragma once
#include <string>
#include "person.h"


class Group
{
private:
	std::string groupName;
	Person* groupLeader;
	Person** groupMembers;
	int groupSize; // макс розмір масиву
	int groupCount; // к-ть заповнених ел-тів масиву

public:
	Group();
	Group(const std::string& name);
	Group(const std::string& name, Person* lead, int size);
	~Group();

	void addMember(Person* member);
	void deleteMember(const std::string& surname);
	void printGroupInfo() const;
	void setLeader(Person* lead);
	Person*& getLeader();

	void readGroupFromFile(const std::string& fileName);
	void writeGroupToFile(const std::string& fileName) const;

	Person*& findBestMember() const;
	double totalMark() const;
	double averageTotalMark() const;

};