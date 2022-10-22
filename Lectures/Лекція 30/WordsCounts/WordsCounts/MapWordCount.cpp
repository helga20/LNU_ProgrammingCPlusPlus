#include <iostream>
#include <cctype>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <sstream>
#include "Procedures.h"
using namespace std;

void MapWordCount()
{
	cout << "\n*** Count words in the program\n\n";
	ifstream in("MultiSetWordCount.cpp");
	// ����������� �������� �������, �� ������ ������� �����
	map<string, int> wordmap;
	string line;
	while (getline(in, line))
	{
		transform(line.begin(), line.end(), line.begin(), replaceNotAlpha);
		istringstream is(line);
		string word;
		// �������� [] ��������� �������� �� ������ ���
		// ����������� ������� ���� (����, �������� �� �������������)
		while (is >> word) ++wordmap[word];
	}
	// ������� ����� ������� ����������� ����������, ����
	// ������������� �������� ��������� ��� pair
	copy(wordmap.begin(), wordmap.end(), ostream_iterator<pair<string, int>>(cout, "\n"));
	//for (auto it = wordmap.begin(); it != wordmap.end(); ++it)
	//{
	//	cout << *it << '\n';
	//}
	cout << '\n';
	system("pause");
	return;
}
