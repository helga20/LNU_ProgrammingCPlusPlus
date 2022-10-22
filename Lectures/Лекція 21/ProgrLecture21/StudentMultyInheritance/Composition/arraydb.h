#ifndef array_db_h_
#define array_db_h_

#include <iostream>
using std::ostream;

class ArrayDb
{
private:
	unsigned int size;
	double* arr;
public:
	ArrayDb(): arr(0), size(0) {}
	explicit ArrayDb(unsigned int n, double val = 0.0);
	ArrayDb(const double* pn, unsigned int n);
	ArrayDb(const ArrayDb& a);
	virtual ~ArrayDb();
	unsigned int arSize() const { return size; }
	double average() const;
	double& operator[](int i);
	const double& operator[](int i) const;
	ArrayDb& operator=(const ArrayDb& a);
	friend ostream& operator<<(ostream& os, const ArrayDb& a);
};
#endif