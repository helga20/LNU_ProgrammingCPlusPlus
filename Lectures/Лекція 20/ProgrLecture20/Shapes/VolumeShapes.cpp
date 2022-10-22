#include "VolumeShapes.h"

VolShape* VolShape::CopyInstance(VolShape* v)
{
	if (typeid(*v) == typeid(Cylinder))       return new Cylinder(*static_cast<Cylinder*>(v));
	if (typeid(*v) == typeid(Parallelepiped)) return new Parallelepiped(*static_cast<Parallelepiped*>(v));
	if (typeid(*v) == typeid(TriPrizm))       return new TriPrizm(*static_cast<TriPrizm*>(v));
	if (typeid(*v) == typeid(Conus))          return new Conus(*static_cast<Conus*>(v));
	if (typeid(*v) == typeid(RectPiramid))    return new RectPiramid(*static_cast<RectPiramid*>(v));
	if (typeid(*v) == typeid(TriPiramid))     return new TriPiramid(*static_cast<TriPiramid*>(v));
	throw BadClassname("Unknown type of Volume Shape encountered");
}

VolShape* VolShape::MakeInstance(std::ifstream& fin)
{
	int y; double h, r, a, b;
	string name;
	fin >> name;
	if (name == "Cylinder")
	{
		fin >> h >> r;
		return new Cylinder(h,r);
	}
	if (name == "Parallelepiped")
	{
		fin >> h >> a >> b; return new Parallelepiped(h,a,b);
	}
	if (name == "TriPrizm")
	{
		fin >> h >> a >> b >> y; return new TriPrizm(h,a,b,y);
	}
	if (name == "Conus")
	{
		fin >> h >> r; return new Conus(h,r);
	}
	if (name == "RectPiramid")
	{
		fin >> h >> a >> b; return new RectPiramid(h,a,b);
	}
	if (name == "TriPiramid")
	{
		fin >> h >> a >> b >> y; return new TriPiramid(h,a,b,y);
	}
	throw BadClassname(name.c_str());
}
//-----------------------------------------------------------
void VolShape::storeOn(ofstream& fout) const
{
	const char * line = this->getClassName();
	for (int i = 6; line[i] != ' '; ++i) fout << line[i];
	fout << ' ' << this->h << ' ';
	this->base->storeOn(fout);
}

ostream& operator<<(ostream& os, const VolShape& s)
{
	s.printOn(os);
	return os;
}

//-----------------------------------------------------------

void DirectShape::printOn(ostream& os) const
{
	os << "DirectShape of " << h << " high on " << *base;
}
Cylinder& Cylinder::operator=(const Cylinder& c)
{
	if (this != &c)
	{
		h = c.h;
		delete base;
		base = new Circle(*dynamic_cast<Circle*>(c.base));
	}
	return *this;
}
Parallelepiped& Parallelepiped::operator=(const Parallelepiped& p)
{
	if (this != &p)
	{
		h = p.h;
		delete base;
		base = new Rectangle(*dynamic_cast<Rectangle*>(p.base));
	}
	return *this;
}
TriPrizm& TriPrizm::operator=(const TriPrizm& t)
{
	if (this != &t)
	{
		h = t.h;
		delete base;
		base = new Triangle(*dynamic_cast<Triangle*>(t.base));
	}
	return *this;
}
//-----------------------------------------------------------

void PiramidalShape::printOn(ostream& os) const
{
	os << "PiramidalShape of " << h << " high on " << *base;
}

double Conus::sideSquare() const
{
/* Площа бічної поверхні = Pi R L, де L - твірна. Її можна обчислити через H i R.
   Однозначно, потрібен радіус основи (круга) ==> потрібно привести абстрактний тип основи до конкретного
*/
	double r = dynamic_cast<Circle*>(base)->radius();
	return M_PI*r*sqrt(h*h+r*r);
}

double RectPiramid::sideSquare() const
{
/* Щоб обчислити площу бічної поверхні прямокутної піраміди,
   потрібно знати сторони основ
*/
	double a = dynamic_cast<RectAB*>(base)->getA();
	double b = dynamic_cast<RectAB*>(base)->getB();
	return a*sqrt(h*h+b*b*0.25)+b*sqrt(h*h+a*a*0.25);
}

double TriPiramid::sideSquare() const
{
/* Вважається, що вершина піраміди проектується в центр вписаного кола,
   тому можна обчислити апофему через радіус вписаного кола
*/
	double r = 2. * base->square() / base->perim();
	return 0.5 * base->perim() * sqrt(h*h+r*r);
}
