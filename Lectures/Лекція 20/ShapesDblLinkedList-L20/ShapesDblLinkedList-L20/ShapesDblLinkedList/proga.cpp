#include "..\Shapes\FlatShapes.h"
#include "..\Shapes\VolumeShapes.h"
#include "ShapesList.h"

void printVol(VolShape*);
bool largeVol(VolShape*);

int main()
{
// випробування ієрархії об'ємних фігур
	std::cout <<" * Volume shapes section *\n-----------------------\n";
	VolShape* v[] = {
		new Paralelepiped(5.,6.,4.),
		new RectPiramid(7.,5.,5.),
		new TriPiramid(),
		new Cylinder(5.,4.),
		new Conus()};
	int m = sizeof v / sizeof *v;
	for (int i=0; i<m; ++i)
		std::cout << *v[i] << "\n\tSo = " << v[i]->baseSquare() << " \tV = " << v[i]->volume()
		<< "\n\tSb = " << v[i]->sideSquare() << '\n';
	std::cin.get();
	Cylinder copyCyl;
	std::cout << "Cylinder before assignment " << copyCyl << '\n';
	copyCyl = *dynamic_cast<Cylinder*>(v[3]);
	std::cout << "And after: " << copyCyl << '\n';
	std::cin.get();
	RectPiramid piramid(5., 3., 4.);
	std::cout << "Original piramid " << piramid << "\n has Sb = " << piramid.sideSquare() << "; V = " << piramid.volume() << '\n';
	RectPiramid copyPir(piramid);
	std::cout << "Copied piramid " << copyPir << "\n has Sb = " << copyPir.sideSquare() << "; V = " << copyPir.volume() << '\n';
	std::cin.get();

// випробування контейнера об'ємних фігур
	std::cout <<"\n * Container section *\n-----------------------\n";
	ShDblList A(3);
	A.printOn(std::cout); std::cin.get();

	A.put(VolShape::CopyInstance(v[0]));
	A.printOn(std::cout); std::cin.get();

	A.put(v[1]->clone()).put(v[2]->clone()).printOn(std::cout);
	std::cin.get();

	std::cout << " * Copy of the container\n";
	ShDblList B(A); B.printOn(std::cout);
	std::cin.get();
	B.clear();

	std::cout << " * After inserting to 1 and puting\n";
	A.insert(v[3],1).put(v[4]).printOn(std::cout);
	std::cin.get();

	std::cout << " * After removing 2\n";
	A.remove(2);
	A.printOn(std::cout); std::cin.get();

	std::cout << " * By the method doEach(Action)\n";
	A.doEach(printVol); std::cin.get();

	std::cout << " * Enumerate and print by operator[]\n";
	for (int i = 0; i <= A.high(); ++i) std::cout << *A[i] << '\n';
	std::cin.get();
	
	std::cout << " * Detecting\n";
	int k = A.detectFirst(largeVol);
	if (k > A.high()) std::cout << "Nothing detected\n";
	else std::cout << "Shape detected " << *A[k] << '\n';
	std::cin.get();
	// лямбда
	k = A.detectFirst([](VolShape* S){ return S->baseSquare() > 20.1; });
	if (k > A.high()) std::cout << "Nothing detected\n";
	else std::cout << "Shape detected " << *A[k] << '\n';
	std::cin.get();

	A.clear();
	A.printOn(std::cout); std::cin.get();

// випробування винятків
	std::ifstream fin("volShapes.txt");
	try
	{
		A.loadFrom(fin);
	}
	catch (VolShape::BadClassname& bcn)
	{
		std::cout << " !!! ERROR: Bad class name '" << bcn.what() << "' encountered!\n";
	}
	fin.close();
	A.printOn(std::cout); std::cin.get();
	try
	{
		A.insert(v[0],10);
	}
	catch (const ShDblList::BadIndex& bi)
	{
		std::cout << "Insertion said: " << bi.what() << '\n';
		std::cout << " !!! ERROR: Bad index '" << bi.index << "' encountered!\n";
		if (bi.index > A.high()) A.put(v[0]);
	}
	std::cin.get();

	ofstream fout("storeShapes.txt");
	A.storeOn(fout);
	fout.close();
	return 0;
}

void printVol(VolShape* s)
{
	std::cout << *s << "\n     has volume V = " << s->volume() << '\n';
}

bool largeVol(VolShape* s)
{
	return s->volume() > 250.;
}
