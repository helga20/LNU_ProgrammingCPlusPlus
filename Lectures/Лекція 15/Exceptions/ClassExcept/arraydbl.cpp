#include "arraydbl.h"

void ArrayDbl::BadIndex::report() const
{
	std::cerr << "Out of bounds index value: " << badInd << '\n';
}

void ArrayDbl::checkSize(int n)
{
	if (n <= 0 || n > 32000) throw BadSize();
}

ArrayDbl::ArrayDbl(int n, double val) :size(0), arr(nullptr)
{
	checkSize(n);
	arr = new double[n];
	size = n;
	for (int i = 0; i < n; ++i) arr[i] = val;
}

ArrayDbl::ArrayDbl(const double *pn, int n) :size(0), arr(nullptr)
{
	checkSize(n);
	arr = new double[n];
	size = n;
	for (int i = 0; i < n; ++i) arr[i] = pn[i];
}

ArrayDbl::ArrayDbl(const ArrayDbl &a)
{
	size = a.size;
	arr = new double[size];
	for (int i = 0; i<size; ++i) arr[i] = a.arr[i];
}

ArrayDbl& ArrayDbl::operator =(const ArrayDbl &a)
{
	if (this == &a) return *this;
	delete[] arr;
	size = a.size;
	arr = new double[size];
	for (int i = 0; i < size; ++i) arr[i] = a.arr[i];
	return *this;
}

ArrayDbl::~ArrayDbl()
{
	delete[] arr;
}

void ArrayDbl::resize(int n)
{
	checkSize(n);
	if (n == size) return;
	double *newMem = new double[n];
	if (size < n)
	{
		for (int i = 0; i < size; ++i) newMem[i] = arr[i];
		for (int i = size; i < n; ++i) newMem[i] = 0.0;
	}
	else
		for (int i = 0; i < n; ++i) newMem[i] = arr[i];
	delete[] arr;
	arr = newMem;
	newMem = nullptr;
	size = n;
}

double ArrayDbl::average() const
{
	double sum = 0.0;
	for (int i = 0; i < size; ++i) sum += arr[i];
	return sum / size;
}

double ArrayDbl::max() const
{
	double res = arr[0];
	for (int i = 1; i < size; ++i)
		if (arr[i] > res) res = arr[i];
	return res;
}

double& ArrayDbl::operator[](int i)
{
	if (i < 0 || i >= size) throw BadIndex(i);
	return arr[i];
}

const double& ArrayDbl::operator[](int i) const
{
	if (i < 0 || i >= size) throw BadIndex(i);
	return arr[i];
}

ostream& operator<<(ostream& os, const ArrayDbl& a)
{
	for (int i = 0; i<a.size; ++i)
	{
		os.width(8); os<<a.arr[i];
	}
	if (a.size % 10 != 0) os << '\n';
	return os;
}