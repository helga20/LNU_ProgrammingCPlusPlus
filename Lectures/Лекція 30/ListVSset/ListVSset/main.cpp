#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <list>
#include <set>
#include <algorithm>
#include <sstream>
using namespace std;

int main()
{
	// ������ ������ ��� �������� ����� � ����������
	ifstream fin("OldmanAndSea.txt"); // �������
	ofstream fout("result.txt");      // ���������
	// ������ �� ���� ���� ����� ���������
	istream_iterator <string> begin(fin), end;
	ostream_iterator <string> out(fout,"\n");

	// ������ ��� ����������� ���
	list <string> L;
	// ��� ������ ������ ��������, �������� ������ �������, � �������� �������� � ������
	// ���� �������� �������� "�쳺" ������������� ����� ����, ������������ ����������
	// ��� ����� �������� � ����� ������
	copy(begin, end, back_inserter(L));
	// ���� �������������� ������� ��� �����, �������� ������ ������ ���� ���������
	//*out++ = "----------------------------- list after copy";
	//copy(L.begin(), L.end(), out);
	// ��������� ��������� �������� ��� - ���������
	L.sort();
	L.unique();
	// ����� ����� �������� ��������� ���������
	*out++ = "----------------------------- list after sort & unique";
	// ��� ������ ����� ������ ��������
	copy(L.begin(),L.end(),out);
	// �������� ������� ��������� ���
	cout << "There are " << L.size() << " words\n";
	fin.clear(); fin.seekg(0);
	// ������� ��� ����������� ���
	set <string> S;
	// ���������� � ������� ������ ��������� � �������
	copy(begin, end, inserter(S, S.begin()));
	// ��� ������ - ����� �������� ���������
	*out++ = "----------------------------- set after copy";
	copy(S.begin(), S.end(), out);
	// �������� ������� ��������� ���
	cout << "There are " << S.size() << " words\n";

	// ��������� ���� � ������� �� ����������� �����
	S.clear();
	fin.clear(); fin.seekg(0);
	// �����, �� ��������� ��������� �������� � �������
	set<char> punct = { '.', ',', '!', '?', ':', ';', '-', '(', ')', '\"', '[', ']' };
	string line;
	// ���������� � ����� �� ������ �����
	while (getline(fin, line))
	{
		// ��������� ��������� ����� (��������� �������)
		transform(line.begin(), line.end(), line.begin(), [&punct](char c){ return punct.find(c) == punct.end() ? c : ' '; });
		// ������������ ��� � ��������� �� �������
		istringstream is(line);
		string word;
		while (is >> word) S.insert(word);
	}
	// ��� ������ - ����� �������� ���������
	*out++ = "----------------------------- set after input & wiping";
	copy(S.begin(), S.end(), out);
	// �������� ������� ��������� ���
	cout << "There are " << S.size() << " words\n";

	fin.close();
	fout.close();
	system("pause");
	return 0;
}
