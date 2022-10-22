#pragma once
#include <iostream>
#include <string>
using namespace std;

class Triangle
{
private:
	double A;
	double B;
	double C;

public:
	Triangle();
	Triangle(const double& a, const double& b, const double& c);
	Triangle(const Triangle& T);
	~Triangle();

	double getA() const;
	double getB() const;
	double getC() const;

	void printInfo() const;

	double& getA();
	double& getB();
	double& getC();

	void setA(const double& a);
	void setB(const double& b);
	void setC(const double& c);

	double getPerimeter() const;
	double getSquare() const;

	bool operator<(const Triangle& T)const;

};

istream& operator>>(istream& in, Triangle& T);
ostream& operator<<(ostream& out, const Triangle& T);

void printArray(Triangle* arr, int n);
void sortByPerimeter(Triangle* arr, int n);
double totalSquare(Triangle* arr, int n);


