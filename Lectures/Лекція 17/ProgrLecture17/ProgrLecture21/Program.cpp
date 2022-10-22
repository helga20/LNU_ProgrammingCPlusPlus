#include "Rect.h"
#include "RectangleSquare.h"
#include "SquareRect.h"

using namespace std;

void TestRectangle(const Rectangle& A, const Rectangle& B);
void TestSquare(const BaseSquare& A, const BaseSquare& B);

int main()
{
	cout << "Simple rectangle section\n----------------------------\n";
	Rect A;
	Rect B(5, 2);
	Rect C(B);
	cout << "  default: "; A.printOn(cout); cout << endl;
	cout << "parameter: "; B.printOn(cout); cout << endl;
	cout << "     copy: "; C.printOn(cout); cout << endl;
	cout << "squares are: " << A.area() << ", " << B.area() << ", " << C.area() << endl;
	cout << " perimeters: " << A.perim() << ", " << B.perim() << ", " << C.perim() << endl;
	system("pause");
	cout << "\nAdvanced rectangle section\n----------------------------\n";
	Rectangle D;
	Rectangle E(5, 2);
	TestRectangle(D, E);
	system("pause");
	cout << "\nSquare section\n----------------------------\n";
	TestRectangle(Square(), Square(5.));
	system("pause");
	cout << "\nBaseSquare section\n----------------------------\n";
	TestSquare(BaseSquare(), BaseSquare(5.));
	system("pause");
	cout << "\nRectSquare section\n----------------------------\n";
	TestSquare(RectSquare(), RectSquare(5.,4.));
	system("pause");
	cout << "\nArray of Rectangles section\n---------------------------------\n";
	const int n = 5;
	Rectangle* R[n] {new Rectangle(4., 6.), new Rectangle(7., 4.), new Square(5.), new Square(4.5), new Rectangle()};
	cout << "Fiqures:\n";
	for (int i = 0; i < n; ++i) cout << "   " << *R[i] << endl;
	cout << "Perimeters:\n";
	for (int i = 0; i < n; ++i) cout << "   " << R[i]->perim() << endl;
	system("pause");
	cout << "\nTemplate section\n-------------------------------------\n";
	Show<Rectangle> SR(Rectangle(6,4));
	Show<Square> SS(Square(5));
	SR.show();
	SS.show();
	//Show<Rectangle>* PS = &SS;
	system("pause");
	return 0;
}

void TestRectangle(const Rectangle& A, const Rectangle& B)
{
	Rectangle* C = new Rectangle(B);
	cout << "  default: "; A.printOn(cout); cout << endl;
	cout << "parameter: "; B.printOn(cout); cout << endl;
	cout << "     copy: "; C->printOn(cout); cout << endl;
	cout << "squares are: " << A.area() << ", " << B.area() << ", " << C->area() << endl;
	cout << " perimeters: " << A.perim() << ", " << B.perim() << ", " << C->perim() << endl;
}
void TestSquare(const BaseSquare& A, const BaseSquare& B)
{
	BaseSquare* C = new BaseSquare(B);
	cout << "  default: "; A.printOn(cout); cout << endl;
	cout << "parameter: "; B.printOn(cout); cout << endl;
	cout << "     copy: "; C->printOn(cout); cout << endl;
	cout << "squares are: " << A.area() << ", " << B.area() << ", " << C->area() << endl;
	cout << " perimeters: " << A.perim() << ", " << B.perim() << ", " << C->perim() << endl;
}