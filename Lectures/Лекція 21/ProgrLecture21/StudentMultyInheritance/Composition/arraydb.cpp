#include <iostream>
#include <cstdlib>
#include "arraydb.h"
ArrayDb::ArrayDb(unsigned int n, double val)
{
	arr = new double[n];
	size = n;
	for (size_t i=0; i<n; i++) arr[i] = val;
}
ArrayDb::ArrayDb(const double *pn, unsigned int n)
{
	arr = new double[n];
	size = n;
	for (size_t i=0; i<n; i++) arr[i] = pn[i];
}
ArrayDb::ArrayDb(const ArrayDb &a)
{
	size = a.size;
	arr = new double[size];
	for (size_t i=0; i<size; i++) arr[i] = a.arr[i];
}
ArrayDb::~ArrayDb()
{
	delete[] arr;
}
double ArrayDb::average() const
{
	if (size>0)
	{
		double sum = 0.0;
		for (size_t i=0; i<size; i++) sum += arr[i];
		return sum/size;
	}
	std::cerr << "No entries in score array\n";
	return 0;
}
double& ArrayDb::operator[](int i)
{
	if ( i<0 || i>=size )
	{
		std::cerr << "Error in ArrayDb limits: " << i 
			<< " is a bad index.\n";
		exit(1);
	}
	return arr[i];
}
const double& ArrayDb::operator[](int i) const
{
	if ( i<0 || i>=size )
	{
		std::cerr << "Error in ArrayDb limits: " << i 
			<< " is a bad index.\n";
		exit(1);
	}
	return arr[i];
}
ArrayDb& ArrayDb::operator =(const ArrayDb &a)
{
	if (this == &a) return *this;
	delete[] arr;
	size = a.size;
	arr = new double[size];
	for (size_t i=0; i<size; i++) arr[i] = a.arr[i];
	return *this;
}
ostream& operator<<(ostream& os, const ArrayDb& a)
{
	for (size_t i=0; i<a.size; i++)
	{
		os.width(8); os<<a.arr[i];
	}
	if (a.size % 10 != 0) os << '\n';
	return os;
}