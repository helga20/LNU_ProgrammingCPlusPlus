// ���������� ��� ������� �� ������������ ��������
// �������: define �� ���� � ������� �����!
#define _USE_MATH_DEFINES 
#include <cmath>

#include <iostream>
using namespace std;

int main()
{
	/* ������ ��� ��� ��� �����.
	   ����������� �������� ������� � ��� (�� �������������� ���������� if)
	*/
	cout << "Input two different integers: ";
	int s, t;
	cin >> s >> t;
	int m = s > t ? s : t;
	cout << "max(" << s << ',' << t << ")=" << m << endl;
	system("pause");

	/* ������ ���������� ������������� �����.
	   �� � ���� ����������?
	   �������� �������� �������� ���� ������� � ������ �����.
	*/
	cout << "Input a four-digit number: ";
	int k;
	cin >> k;
	int left = k / 100;  // �������� ���� ������� ����
	int right = k % 100; // �������� ���� �������� ����
	cout << (left / 10 == right % 10 && left % 10 == right / 10 ? "Yes! It is a polindrome.\n" : "NO, it is not.\n");
	system("pause");

	/* ������ ������� ������ ������������ ����������.
	   ��������� ���� �����, ��������, ������ ��������� �� ��������� ��, �������� ������� ���� � ��������.
	*/
	cout << "Input legs of the right triangle: ";
	double a, b;
	cin >> a >> b;
	// �����
	double S = a*b*0.5;
	// ��������� ������ ���� ��������� ��������� � ������
	double c = sqrt(a*a + b*b);
	// ��������
	double P = a + b + c;
	// ����� ��������� ����
	double R = c*0.5;
	// ����� ��������� ����
	double r = (a + b - c) / 2.;
	// �������� ������� ����
	double alpha = atan(a / c) / M_PI * 180;
	double betha = 90 - alpha;
	cout << "All about the " << a << " x " << b << " right triangle:\n"
		<< " S = " << '\t' << S << "\n P = " << '\t' << P
		<< "\n R = " << '\t' << R << "\n r = " << '\t' << r << '\n';
	cout << "The anles are (in degree): " << alpha << " and " << betha << '\n';
	system("pause");
	return 0;
}