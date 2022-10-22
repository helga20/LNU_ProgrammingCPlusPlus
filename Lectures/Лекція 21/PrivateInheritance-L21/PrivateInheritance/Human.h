#pragma once
#include <string>
#include "Date.h"
class Human
{
private:
	std::string name;
	Date birthday;
public:
	Human();
	Human(const char* n, unsigned d, unsigned m, unsigned y) 
		:name(n), birthday(Date(d, m, y)) {}
	virtual ~Human();
	// ������ ��� ������� ����� ����������
	Date Birthday() const { return birthday; }
	std::string Name() const { return name; }
	// ��������� � ����
	virtual void printOn(std::ostream& os) const
	{
		os << name << " (";
		birthday.printOn(os);
		os << ')';
	}
	Human& say(std::string phrase)
	{
		std::cout << name << ": \"" << phrase << "\"\n";
		return *this;
	}
};

std::ostream& operator<<(std::ostream& os, const Human& human);

