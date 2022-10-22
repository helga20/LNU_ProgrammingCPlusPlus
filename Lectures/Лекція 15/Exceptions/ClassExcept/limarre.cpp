#include "limarre.h"
#include <iostream>

void LimitArE::SonOfBad::report() const
{
	std::cerr << "Out of bounds index value: " << badInd 
		<< "\n  actual bounds are: "<<l_lim<<':'<<u_lim<<'\n';
}
void LimitArE::ok(int i) const throw(SonOfBad&)
{
	unsigned size = arSize();
	if (i<low_bnd || i>=size+low_bnd) throw SonOfBad(i,low_bnd,low_bnd+size-1);
}
double& LimitArE::operator[](int i) throw(ArrayDbE::BadIndex&)
{
	ok(i); return arr[i-low_bnd];
}
const double& LimitArE::operator[](int i) const throw(ArrayDbE::BadIndex&)
{
	ok(i); return arr[i-low_bnd];
}
