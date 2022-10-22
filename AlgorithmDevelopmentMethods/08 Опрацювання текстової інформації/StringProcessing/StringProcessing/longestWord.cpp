#include "processProcedures.h"
#include <string>
#include <sstream>

using std::string;

void longestByArray()
{
	const int maxLength = 256;
	char text[maxLength] = { 0 }; // ���� ��� ����������� ������
	cout << "������ ����� (�� 255 ����): ";
	cin.getline(text, maxLength);
	cout << "�� �����: " << text << '\n';
	// �������� �����������
	int start = 0;             // ������� ���������� �����
	int maxLen = 0;            // ���� �������
	int curr = 0;              // ������� ������
	while (text[curr] != '\0') // ����������� �� ������������ �������
	{
		int pos = curr;        // ������� ��������� �����
		while (text[curr] != '\0' && text[curr] != ' ')	++curr; // ������ ���� ���������
		int len = curr - pos;  // ������� ��������� �����
		if (len > maxLen)
		{                      // ������� �����
			maxLen = len;
			start = pos;
		}
		while (text[curr] != '\0' && text[curr] == ' ') ++curr; // ������ �������� �����
	}
	// ����� ����� �������� �������� �����
	char * longestWord = new char[maxLen + 1];
	for (int i = 0; i < maxLen; ++i) longestWord[i] = text[start + i];
	longestWord[maxLen] = '\0';
	cout << "�������� �����: " << longestWord << '\n';
	delete[] longestWord;
}

void longestByString()
{
	string text;
	cout << "������ �����: ";
	getline(cin, text);
	cout << "�� �����: " << text << '\n';
	// ����������� �� ��������� ������ ����
	std::istringstream s(text);
	string word, maxWord;
	int maxL = 0;
	while (s >> word) // �������� �������� ������� ��������
	{
		int L = word.length();
		if (L > maxL)
		{
			maxL = L;
			maxWord = word;
		}
	}
	cout << "�������� �����: " << maxWord << '\n';
}

void printLongest()
{
	cout << "\n *³�������� ���������� � ����� �����*\n";
	cout << "\n-� ������������� ����� � ���� �-\n";
	longestByArray();
	cout << "\n-� ������������� �����-����������-\n";
	longestByString();
}