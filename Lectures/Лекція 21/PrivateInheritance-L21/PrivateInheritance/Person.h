#pragma once
#include "Date.h"
#include <string>
class Person :
	private Date
{
private:
	std::string name;
public:
	Person();
	Person(const char* n, unsigned d, unsigned m, unsigned y) 
		:Date(d, m, y), name(n) {}
	// ������ ������� ����� ����������
	// - ���� ���������� �������� � ���������
	//   �������� ���������� �� �������� ����
	Date Birthday() const { return *this; }
	std::string Name() const { return name; }
	// ��� ��������� � ���� ������� ����� ����� �������� �����
	virtual void printOn(std::ostream& os) const
	{
		os << name << " (";
		Date::printOn(os);
		os << ')';
	}
	virtual ~Person();
};

std::ostream& operator<<(std::ostream& os, const Person& person);

