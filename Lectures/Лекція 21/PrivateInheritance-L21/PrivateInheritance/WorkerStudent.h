#pragma once
#include "Human.h"

class Worker :
	virtual public Human
{
private:
	long personalID;
	double salary;
protected:
	// ����� "����������" ��������� � ���� � ����� ������� ����������
	virtual void print(std::ostream& os) const
	{
		os << " #" << personalID << " $" << salary;
	}
public:
	Worker() : Human(), personalID(0), salary(0) {}
	// �������� �����������
	Worker(const char* n, unsigned d, unsigned m, unsigned y, long No)
		: Human(n, d, m, y), personalID(No), salary(300) {}
	virtual ~Worker() {}
	virtual void printOn(std::ostream& os) const
	{
		Human::printOn(os);
		os << " with ";
		this->print(os);
	}
};

class Student :
	virtual public Human
{
private:
	Date entryDate;
	int points[50];
protected:
	// ����� "����������" ��������� � ���� � ����� ������� ��������
	virtual void print(std::ostream& os) const
	{
		os << " entered at " << entryDate;
	}
public:
	Student() : Human(), entryDate(Date()) {}
	// �������� �����������
	Student(const char* n, unsigned d, unsigned m, unsigned y)
		: Human(n, d, m, y), entryDate(Date(1,9,2016)) {}
	virtual ~Student() {}
	virtual void printOn(std::ostream& os) const
	{
		Human::printOn(os);
		this->print(os);
	}
};

class WorkingStudent :
	public Student,
	public Worker
{
public:
	WorkingStudent() : Student(), Worker() {}
	// ���������� �����������: ��� ����� ���������
	WorkingStudent(const char* n, unsigned d, unsigned m, unsigned y, long No) :
		Human(n, d, m, y),
		Student(n, d, m, y),
		Worker(n, d, m, y, No) {}
	// ��������� � ���� "����� �������"
	virtual void printOn(std::ostream& os) const
	{
		Human::printOn(os);
		Student::print(os);
		Worker::print(os);
	}
};
