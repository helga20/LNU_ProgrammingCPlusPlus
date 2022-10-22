#include "triangle.h"

Triangle::Triangle() : A(), B(), C()
{
	//cout << "Default Triangle\n";
}

Triangle::Triangle(const double& a, const double& b, const double& c) : A(a), B(b), C(c)
{
	//cout << "Parameters Triangle\n";
}

Triangle::Triangle(const Triangle& T) : A(T.A), B(T.B), C(T.C)
{
	//cout << "Copy Triangle\n";
}

Triangle::~Triangle()
{
	//cout << "Destroy Triangle\n"<< A <<"\n";
}

double Triangle::getA() const
{
	return this->A;
}

double Triangle::getB() const
{
	return this->B;
}

double Triangle::getC() const
{
	return this->C;
}

void Triangle::printInfo() const
{
	cout << "Triangle info: ";
	cout << "\na = " << A << "\nb = " << B << "\nc = " << C << "\n";
}

double& Triangle::getA()
{
	return A;
}

double& Triangle::getB()
{
	return B;
}

double& Triangle::getC()
{
	return C;
}

void Triangle::setA(const double& a)
{
	if (a <= 0)
	{
		cout << "Error! The side of the triangle cannot be " << a << "\n";
		return;
	}
	A = a;
}

void Triangle::setB(const double& b)
{
	if (b <= 0)
	{
		cout << "Error! The side of the triangle cannot be " << b << "\n";
		return;
	}
	B = b;
}

void Triangle::setC(const double& c)
{
	if (c <= 0)
	{
		cout << "Error! The side of the triangle cannot be " << c << "\n";
		return;
	}
	C = c;
}

istream& operator>>(istream& in, Triangle& T)
{
	in >> T.getA() >> T.getB() >> T.getC();
	return in;
}

ostream& operator<<(ostream& out, const Triangle& T)
{
	out << "\na= " << T.getA() << "\nb= " << T.getB() << "\nc= " << T.getC();
	return out;
}

double Triangle::getPerimeter() const
{
	return A + B + C;;
}

bool Triangle::operator<(const Triangle& T)const
{
	return this->getPerimeter() < T.getPerimeter();
}

double Triangle::getSquare() const
{
	double p = (A + B + C) / 2;
	double s = sqrt(p * (p - A) * (p - B) * (p - C));
	return s;
}

void printArray(Triangle* arr, int n)
{
	cout << "\nArray of Triangles\n";
	for (int i = 0; i < n; ++i)
	{
		arr[i].printInfo();
	}
	cout << "\n";
}

void sortByPerimeter(Triangle* arr, int n)
{
	int i, j, min;
	for (i = 0; i < n; ++i)
	{
		min = 1;
		for (j = i; j < n; ++j)
		{
			if (arr[j] < arr[min])
			{
				min = j;
				Triangle temp;
				temp = arr[i];
				arr[i] = arr[min];
				arr[min] = temp;
			}

		}
	}
}

double totalSquare(Triangle* arr, int n) 
{
	double sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += arr[i].getSquare();
	}
	return sum;
}


