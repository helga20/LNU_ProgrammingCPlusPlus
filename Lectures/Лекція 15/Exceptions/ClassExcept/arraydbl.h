#ifndef array_dbe_h_
#define array_dbe_h_

#include <iostream>
using std::ostream;

class ArrayDbl
{
private:
	int size;
	double* arr;
	void checkSize(int n);
public:
	class BadSize {};
	class BadIndex
	{
	public:
		int badInd;
		BadIndex(int i) : badInd(i) {}
		void report() const;
	};

	ArrayDbl() : arr(0), size(0) {}
	explicit ArrayDbl(int n, double val = 0.0) /*throw(BadSize)*/;
	ArrayDbl(const double* pn, int n) /*throw(BadSize)*/;
	ArrayDbl(const ArrayDbl& a);
	ArrayDbl& operator=(const ArrayDbl& a);
	~ArrayDbl();

	int arSize() const { return size; }
	void resize(int n) /*throw(BadSize)*/;

	double average() const;
	double max() const;

	double& operator[](int i) /*throw(BadIndex&)*/;
	const double& operator[](int i) const /*throw(BadIndex&)*/;
	friend ostream& operator<<(ostream& os, const ArrayDbl& a);
};
#endif