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
	// методи читанн€ даних екземпл€ра
	// - день нарожденн€ отримуЇмо в результат≥
	//   не€вного приведенн€ до базового типу
	Date Birthday() const { return *this; }
	std::string Name() const { return name; }
	// ƒл€ виведенн€ в пот≥к потр≥бен також метод базового класу
	virtual void printOn(std::ostream& os) const
	{
		os << name << " (";
		Date::printOn(os);
		os << ')';
	}
	virtual ~Person();
};

std::ostream& operator<<(std::ostream& os, const Person& person);

