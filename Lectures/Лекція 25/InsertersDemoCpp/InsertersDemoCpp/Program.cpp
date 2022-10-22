/* �������� ��������� ������������ ����������� ���������:
   ������������, ���������, ������� */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <Windows.h>
// ��������� ������ �������� ��������� ������ �����쳿 ����
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	// ����������� ���������� ����� � ���������� ���������
	// ������ �������� ��������� �� ������ �������
	int a[] = { 1,2,3,4,5,6,7,8 };
	const int n = sizeof a / sizeof *a;
	int b[n] = { 0 };

	// ���������� ��������� ������ �� �������
	cout << "\n * ����� � *\n";
	for (int i = 0; i < n; ++i) cout << '\t' << a[i];
	cout << "\n * ����� b - ��������� �������� *\n";
	for (int i = 0; i < n; ++i) cout << '\t' << b[i];
	cout << '\n';
	system("pause");

	// ��������� ������� ������������ ��������� ���������
	copy(a, a + n, b);
	cout << "\n * ����� b - �������� ���� ��������� *\n";
	for (int i = 0; i < n; ++i) cout << '\t' << b[i];
	cout << '\n';
	system("pause");

	// ��������� �������� ��� ��������� �� �������
	// ������� ������ ��� ���������:
	//  - ������� - ��� �����, �� ����� ��������
	//  - ������������ - ���� � �����-���������
	ostream_iterator<int> out(cout, "\t");
	// ��������� �� ������� �� ��������� ���������
	cout << "\n * ����� � - ��������� ���������� *\n";
	copy(a, a + n, out);
	cout << "\n * ����� b - ��������� ���������� *\n";
	copy(b, b + n, out);
	cout << '\n';
	system("pause");

	// ���������� ��������� �� �������
	cout << "\n --- ������������ ����������� ���������� ���������\n";
	for (int i = 7; i < 99; i += 10) *out++ = i;
	cout << '\n';
	system("pause");

	// ��������� ���������� �� ������� �� ��������� ���������
	// ��������� ������� ��� ���������
	vector<int> A = { 10,20,30,40,50,60,70,80 };
	cout << "\n * ������ � - ��������� ���������� *\n";
	copy(A.begin(), A.end(), out);
	cout << '\n';
	system("pause");

	// ��������� ����������, ����� ������
	vector<int> B(A.size());
	copy(A.begin(), A.end(), B.begin());
	cout << "\n * ������ B - ���� ��������� *\n";
	copy(B.begin(), B.end(), out);
	cout << '\n';
	system("pause");

	// ������� � ������� ������ ���� ����� ����
	copy(a, a + n, B.begin());
	cout << "\n * ������ B - ���� ��������� � ������ *\n";
	copy(B.begin(), B.end(), out);
	cout << '\n';
	system("pause");

	// ��������� ���� ������ ����� ��������, ���� ����������� ����������� ��������
	vector<int> C = { 55 };
	cout << "\n * ������ C - ��������� �������� *\n";
	copy(C.begin(), C.end(), out);
	copy(A.begin(), /*A.end(),*/ back_inserter(C));
	cout << "\n * ������ C - ���� ��������� *\n";
	copy(C.begin(), C.end(), out);
	cout << '\n';
	system("pause");

	// ��������� ����� ��������������� � �������������
	vector<int> D(C.begin(), C.end());
	cout << "\n * ������ D - ���� ������������� *\n";
	copy(D.begin(), D.end(), out);
	cout << '\n';
	system("pause");

	// ������ ��������� ����� ��������������� ��� ��������� ����� ����������,
	// ��� ������������ ���������� � �����, ��� ��������� ���������� � �����
	ofstream fout("Integers.txt");
	copy(D.begin(), D.end(), ostream_iterator<int>(fout, "\t")); // ���������
	fout.close();
	cout << "\n * ������ D �������� �� ����� *\n";
	system("copy Integers.txt con");
	cout << '\n';
	system("pause");

	// ������������ � �����
	ifstream fin("Integers.txt");
	A.clear(); // ���������� ����� ��������� �������� �� ������� �����
	// ��� ����������� ��������� ������� ������ �������� ����
	// ʳ������ �������� ������� ����������� �� �������������
	copy(istream_iterator<int>(fin), istream_iterator<int>(), back_inserter(A));
	cout << "\n * ������ � - ���� ������������ � ����� *\n";
	copy(A.begin(), A.end(), out);
	cout << '\n';
	fin.close();
	system("pause");

	// ��������� � �����. ��� �������� ������ ������������ ����'������
	// ��������� ��������� �������� �� ��������� �����
	fin.open("Integers.txt");
	istream_iterator<int> start_iter(fin), end_iter;
	vector<int> E(start_iter, end_iter);
	//vector<int> E(start_iter, istream_iterator<int>()); // ����� � ���
	cout << "\n * ������ E - ���� ��������� � ����� *\n";
	copy(E.begin(), E.end(), out);
	cout << '\n';
	fin.close();
	system("pause");

	return 0;
}