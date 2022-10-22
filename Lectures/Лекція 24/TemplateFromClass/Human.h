#pragma once
#include <iostream>
#include <string>

enum Gender { Male, Female };

// Особа має ім'я та стать
class Human
{
private:
	std::string name;
	Gender sex;
public:
	Human() :name("Unknown"), sex(Male) {}
	Human(const char* n, Gender s) :name(n), sex(s) {}
	// методи для читання даних екземпляра
	Gender Sex() const { return sex; }
	std::string Name() const { return name; }
	// виведення в потік
	virtual void printOn(std::ostream& os) const;
	// Особа вміє висловлюватися
	Human& say(std::string phrase)
	{
		std::cout << name << ": \"" << phrase << "\"\n";
		return *this;
	}
};

// Студент - це особа, що має залікову та колекцію оцінок
// Тип оцінки не обмежено, вимоги - operator==, operator<< 
template<typename TPoint>
class Student :public Human
{
private:
	std::string indNo;
	TPoint point[50] = { TPoint() };
public:
	Student() :Human(), indNo("2701234c") {}
	Student(const char* n, Gender s, const char* i) : Human(n, s), indNo(i) {}
	Student<TPoint>& setPoint(TPoint p, int i) { point[i] = p; return *this; }
	virtual void printOn(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, Gender gender);
std::ostream& operator<<(std::ostream& os, const Human& human);

template<typename TPoint>
inline void Student<TPoint>::printOn(std::ostream & os) const
{
	Human::printOn(os);
	os << " is a student: [";
	int i = 0;
	while (!(point[i] == TPoint())) std::cout << ' ' << point[i++];
	os << " ]";
}

// Спеціальний тип для всестороннього відображення оцінки
struct Point
{
	int num;
	char letter;
	std::string word;
	Point() : num(0), letter('F'), word("unsatisfied") {}
	Point(int point);
	bool operator==(const Point& point) const
	{
		return this->num == point.num;
	}
};
std::ostream& operator<<(std::ostream&os, const Point& p);
