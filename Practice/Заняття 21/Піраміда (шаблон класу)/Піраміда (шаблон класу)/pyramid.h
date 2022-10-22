#pragma once
#include <iostream>
#include <fstream>
using namespace std;

template <typename P>
class Pyramid
{
private:
	double height;
	double apophema;
	P base;
public:
	Pyramid();
	Pyramid(double h, double a, const P& p);
	Pyramid(const Pyramid& P);
	~Pyramid();

	void printPyramid() const;
	double getSurfaceArea() const;
	double getVolume() const;

	void setHeight(double h);
	void setApophema(double a);
	void setBase(const P& p);

	void readPyramid(istream& in);
	void writePyramid(ostream& out) const;
};

template <typename P>
Pyramid<P>::Pyramid()
	: height(0.0), apophema(0.0), base()
{}

template <typename P>
Pyramid<P>::Pyramid(double h, double a, const P& p)
	: height(h), apophema(a), base(p)
{}

template <typename P>
Pyramid<P>::Pyramid(const Pyramid& P)
	: height(P.height), apophema(P.apophema), base(P.base)
{}

template <typename P>
Pyramid<P>::~Pyramid()
{}

template <typename P>
void Pyramid<P>::printPyramid() const
{
	cout << "\nHeight = " << height << "\n";
	cout << "Apophema = " << apophema << "\n";
	base.printInfo();
}

template <typename P>
double Pyramid<P>::getSurfaceArea() const
{
	double sa;
	sa = base.getSquare() + base.getPerimeter() * apophema;
	cout << "Surface area = " << sa << "\n";
	return sa;
}

template <typename P>
double Pyramid<P>::getVolume() const
{
	double v;
	v = (height * base.getSquare()) / 3;
	cout << "Volume = " << v << "\n";
	return v;
}

template <typename P>
void Pyramid<P>::setHeight(double h)
{
	if (h <= 0)
	{
		cout << "Error! The height cannot be negative or zero\n";
	}
	else
	{
		height = h;
	}
}

template <typename P>
void Pyramid<P>::setApophema(double a)
{
	if (a <= 0)
	{
		cout << "Error! The apophema cannot be negative or zero\n";
	}
	else
	{
		apophema = a;
	}
}

template <typename P>
void Pyramid<P>::setBase(const P& p)
{
	base = p;
}

template <typename P>
void Pyramid<P>::readPyramid(istream& in)
{
	in >> height >> apophema >> base;
}

template <typename P>
void Pyramid<P>::writePyramid(ostream& out) const
{
	out << "h = " << height << "; a = " << apophema << "; base = ";
	base.writeTo(out);
}

template <typename P>
istream& operator>>(istream& in, Pyramid<P>& p)
{
	p.readPyramid(in);
	return in;
}

template <typename P>
ostream& operator<<(ostream& out, const Pyramid<P>& p)
{
	p.writePyramid(out);
	return out;
}
