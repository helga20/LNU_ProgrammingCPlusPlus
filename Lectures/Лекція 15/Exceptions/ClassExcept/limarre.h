#ifndef _LIMARRE_H_
#define _LIMARRE_H_
#include "arraydbe.h"

class LimitArE: public ArrayDbE
{
public:
	class SonOfBad: public ArrayDbE::BadIndex
	{
	public:
		int l_lim, u_lim;
		SonOfBad(int i, int l, int u): BadIndex(i), l_lim(l), u_lim(u) {}
		void report() const;
	};
private:
	unsigned int low_bnd;
protected:
	virtual void ok(int) const throw(SonOfBad&);
public:
	LimitArE(): ArrayDbE(), low_bnd(0) {}
	LimitArE(unsigned int n, double val = 0.0): ArrayDbE(n,val), low_bnd(0) {}
	LimitArE(unsigned int n, int lb, double val = 0.0): ArrayDbE(n,val), low_bnd(lb) {}
	LimitArE(const double* pn, unsigned int n): ArrayDbE(pn,n), low_bnd(0) {}
	LimitArE(const ArrayDbE& a): ArrayDbE(a), low_bnd(0) {}
	void new_lb(int lb) { low_bnd = lb; }
	int lbound() const { return low_bnd; }
	int ubound() const { return arSize()+low_bnd-1; }
	double& operator[](int) throw(ArrayDbE::BadIndex&);
	const double& operator[](int) const throw(ArrayDbE::BadIndex&);
};
#endif