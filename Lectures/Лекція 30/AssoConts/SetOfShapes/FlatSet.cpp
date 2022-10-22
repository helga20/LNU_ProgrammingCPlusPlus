#include "FlatShapes.h"
#include <set>
#include <list>
//#include <functional>
#include <algorithm>
#include <iterator>

using namespace std;

// ��'���-������� ��� ��������� ����������-�����
struct shapeComparer /*: public binary_function<Shape*, Shape*, bool>*/
{
	bool operator()(const Shape* a, const Shape* b) const
	{
		return a->square() < b->square();
	}
};

int main()
{

	set<Circle> circleSet;
	circleSet.insert(Circle(2.));
	circleSet.insert(Circle());
	circleSet.insert(Circle(3.));
	circleSet.insert(Circle(1.));

	for (set<Circle>::iterator it = circleSet.begin(); it != circleSet.end(); ++it)
		cout << *it << '\n';
	cout << '\n';

	typedef set<Shape*>::iterator Iterator;
	// ������� ����� ��� ��������-������������ �������
	Shape* shapes[] = { new Circle(), new Square(), new Rectangle(), new Triangle(),
		new Rectangle(2., 1.), new Circle(), new Triangle(4., 3., 90), new Triangle(3., 3., 60) };
	const int n = sizeof shapes / sizeof *shapes;

	// ����������� ���������� �������
	set<Shape*  , shapeComparer> shapeSet;
	for (int i = 0; i < n; ++i)
	{
		// ����� ���������� ������� ����: ���� ������� � ������ �����
		pair<Iterator, bool> res = shapeSet.insert(shapes[i]);
		cout << *shapes[i] << (res.second ? " was inserted successfully\n" : " was NOT inserted\n");
	}
	cout << "\n  ***  The set contains:\n";
	// ����������� ������ ����������
	Iterator it = shapeSet.begin();
	while (it != shapeSet.end())
	{
		cout << **it << '\n';
		++it;
	}
	system("pause");

	system("pause");
	return 0;
}
