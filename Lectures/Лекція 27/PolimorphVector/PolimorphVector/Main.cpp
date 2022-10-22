#include "FlatShapes.h"
#include "pVector.h"
#include <memory>
using std::auto_ptr;

int main()
{
	_CrtMemState oldState, newState, diff;
	cout << "------ vector<T> --- section --------------\n\n";
	_CrtMemCheckpoint(&oldState);
	vector<Shape*> v;
	v.push_back(new Rectangle(3., 4.));
	v.push_back(new Square(5.));
	v.push_back(new Circle(2.75));
	_CrtMemCheckpoint(&newState);
	_CrtMemDifference(&diff, &oldState, &newState);
	cout << "vector<Shape*> afler three pushbacks\n";
	for (unsigned i = 0; i < v.size(); ++i)
		cout << ' ' << *v[i] << '\n';
	cout << "\nThere are " << diff.lTotalCount << " bytes used on the heap\n";

	_CrtMemCheckpoint(&oldState);
	vector<Shape*> c(v);
	_CrtMemCheckpoint(&newState);
	_CrtMemDifference(&diff, &oldState, &newState);
	cout << "\ncopy of vector<Shape*>\n";
	for (unsigned i = 0; i < c.size(); ++i)
		cout << ' ' << *c[i] << '\n';
	cout << "\nThere are " << diff.lTotalCount << " additional bytes used on the heap\n";

	for (unsigned i = 0; i < c.size(); ++i) c[i]->multBy(1.5);
	cout << "\ncopy of vector<Shape*> after multBy(1.5)\n";
	for (unsigned i = 0; i < c.size(); ++i)
		cout << ' ' << *c[i] << '\n';
	cout << "\nUps! The original vector<Shape*>\n";
	for (unsigned i = 0; i < v.size(); ++i)
		cout << ' ' << *v[i] << '\n';
	_CrtMemCheckpoint(&oldState);
	v.clear();
	c.clear();
	_CrtMemCheckpoint(&newState);
	_CrtMemDifference(&diff, &oldState, &newState);
	cout << "\nThere are " << diff.lTotalCount << " bytes returned to the heap\n";
	system("pause");

	cout << "\n\n------ pVector<T> --- section --------------\n\n";
	_CrtMemCheckpoint(&oldState);
	pVector<Shape*> V;
	V.push_back(new Rectangle(3., 4.));
	V.push_back(new Square(5.));
	V.push_back(new Circle(2.75));
	_CrtMemCheckpoint(&newState);
	_CrtMemDifference(&diff, &oldState, &newState);
	for (unsigned i = 0; i < V.size(); ++i)
		cout << *V[i] << '\n';
	cout << '\n';
	cout << "\nThere are " << diff.lTotalCount << " bytes used on the heap\n";

	_CrtMemCheckpoint(&oldState);
	pVector<Shape*> C(V);
	_CrtMemCheckpoint(&newState);
	_CrtMemDifference(&diff, &oldState, &newState);
	cout << "\nThere are " << diff.lTotalCount << " additional bytes used on the heap\n";
	delete C.front();
	C.front() = new Triangle(4., 4., 60);
	for (unsigned i = 0; i < V.size(); ++i)
		cout << *C[i] << '\n';
	system("pause");

	for (unsigned i = 0; i < C.size(); ++i) C[i]->multBy(1.5);
	cout << "\ncopy of pVector<Shape*> after multBy(1.5)\n";
	for (unsigned i = 0; i < C.size(); ++i)
		cout << ' ' << *C[i] << '\n';
	cout << "\nThe original pVector<Shape*>\n";
	for (unsigned i = 0; i < V.size(); ++i)
		cout << ' ' << *V[i] << '\n';
	_CrtMemCheckpoint(&oldState);
	V.clear();
	C.clear();
	_CrtMemCheckpoint(&newState);
	_CrtMemDifference(&diff, &oldState, &newState);
	cout << "\nThere are " << diff.lTotalCount << " bytes returned to the heap\n";
	system("pause");

	vector<auto_ptr<Shape>> VAS;
	VAS.push_back(auto_ptr<Shape>(new Rectangle(3., 4.)));
	VAS.push_back(auto_ptr<Shape>(new Square(5.)));
	VAS.push_back(auto_ptr<Shape>(new Circle(2.75)));
	for (unsigned i = 0; i < VAS.size(); ++i)
		cout << ' ' << *VAS[i] << '\n';
	/*vector<auto_ptr<Shape>> PAS(VAS); // error in constructor auto_ptr
	for (unsigned i = 0; i < PAS.size(); ++i)
		cout << ' ' << *PAS[i] << '\n';*/
	system("pause");
	return 0;
}