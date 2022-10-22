#include <iostream>
using namespace std;

/* ���� ������� ������ "��������� ���������".
   ³� ���������� �������� ��������, �������� ����� ����������� �������� ������������.
   ������� �������� - �������� �������� �������� ���'���, �� � ������ ����������.
   ���� name - �����. ���� ������ �������� ��� �������� ������������� �� ��'������
*/
class DoublePtr
{
	double * p;
	char name;
public:
	DoublePtr(char n) :name(n) { p = new double; cout << "Get mem for " << name << '\n'; }
	~DoublePtr() { delete p; cout << "Free mem from " << name << '\n'; }
	double& operator*() { return *p; }
};

// ������� ��������� ������������ �������� ���������:
// ������ x>=0 - �������� ��������� ����������,
// ������ x < 0 - ������� �������.
// � ���� �������� ��������� ��'��� �������� ������� �������� ���'���
void doMem()
{
	DoublePtr a('A'); // Local smart pointer
	double x;
	cout << "Input a number: "; cin >> x;
	if (x < 0) throw "Negative";
	*a = x*2.3;
	cout << x << ' ' << *a << '\n';
}

int main()
{
	DoublePtr b('B'); // Global smart pointer
	// ����������� ��������� doMem()
	try
	{
		doMem();
	}
	catch(...)
	{
		cout<< "catched!\n";
	}
	system("pause");

	// ������� � msdn ������������ � ���������� ������� ���� ���������
	const char * c = "test"; // ������������ �������� ����������
	//const char * c = "ukr";
	// runtime_error  
	try
	{
		locale loc(c);
		cout << c << endl;
	}
	catch (exception &e)
	{
		cerr << "Caught " << e.what() << endl;
		cerr << "Type " << typeid(e).name() << endl;
	};
	system("pause");
	return 0;
}