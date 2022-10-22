#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include "Procedures.h"
using namespace std;

char replaceNotAlpha(char c)
{
	return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '_' ? c : ' ';
}

/* ���������� ������� ��� � ���� �� ��������� �������������
   ������� ����� �� ��, �� ������������ ������� ��������� ��������*/
void MultisetWordCount()
{
	cout << "\n*** Count words in the program with help of multiset\n\n";
	ifstream in ("MultiSetWordCount.cpp");
	multiset<string> wordmset;
	string line;
	while (getline(in, line)) // ����������� �� ������ �����
	{                  // �������� � ������ ���� �������� �����
		transform(line.begin(), line.end(), line.begin(), replaceNotAlpha);
		istringstream is(line);
		string word;   // ������ ����� � ������ �� �� ����������
		while (is >> word) wordmset.insert(word);
	}
	// �������� ������������� ���������� �� ��������� ���������
	typedef multiset<string>::iterator MSIter;
	MSIter it = wordmset.begin();
	while (it != wordmset.end())
	{
		// ����� equal_range ������� ���� ��������� [�������; �����)
		pair<MSIter, MSIter> p = wordmset.equal_range(*it);
		// �������� ������� ��� ���������� ������� ���������
		int count = distance(p.first, p.second);
		cout << *it << "  :  " << count << '\n';
		it = p.second; // ������� �� ���������� �����
	}
	system("pause");
	return;
}
