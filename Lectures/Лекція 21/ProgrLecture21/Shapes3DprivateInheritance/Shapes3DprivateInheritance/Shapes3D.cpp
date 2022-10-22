#include "Shapes3D.h"
#include <exception>

Shape3D* Shape3D::MakeInstance(std::ifstream& fin)
{
	double a, b, h;
	string name, baseName;
	fin >> name;
	if (name == "Parallelepiped")
	{
		fin >> h >> baseName >> a >> b; fin.get();
		return new Parallelepiped(a, b, h);
	}
	if (name == "RectangularPyramid")
	{
		fin >> h >> baseName >> a >> b; fin.get();
		return new RectangularPyramid(a, b, h);
	}
	throw std::domain_error("Class name not recognized");
}

ostream& operator<<(ostream& os, const Shape3D& s)
{
	s.printOn(os); return os;
}

bool operator>(const Shape3D& a, const Shape3D& b)
{
	return a.volume() > b.volume();
}
