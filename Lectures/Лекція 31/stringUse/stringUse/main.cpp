#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <windows.h>
using namespace std;

// ���. ³�������� ����� �� ������ �� ����� �����.
// ��������� �������� ���'��� �� ��� �� ������ "��������", ������ - ������� "���� �����"
// ������� � ����� �������� �� ������� ������������ ����� string,
// �������, �� ������������, �� ������, �� ��������� �����������, � ��� ����

const int NUM = 31;
const string wordlist[NUM] = {
	"������", "������", "������", "����������", "��������", "�������",
	"�������������", "�����������", "����'����", "��������", "������", "����������",
	"������", "������", "����'����", "������", "����������", "��������",
	"���������", "�������", "��������", "��������", "���������", "������",
	"���������", "��������", "�������", "�����", "������", "������",
	"����"};

int main()
{
	SetConsoleOutputCP(1251); SetConsoleCP(1251);
	srand(time(0));
	char play;
	cout << "�������� �������� �����? (�/�) ";
	cin >> play;
	while (play=='�' || play=='�')
	{
		string target = wordlist[rand()%NUM];   // ����� "������" �������� ���������� �����
		int len = target.length();
		string attempt(len,'*');                // ��������� ���������� ���������� �����
		string badChars;                        // �������� �����'����� �� ������ �����. ���� - �����
		int guesses = 6;                        // ������� ������������ �����
		cout << "\n�������� ����� �� " << len << " ����.\n"
			<< "�� ������� �� ���� ����. � ��� " << guesses << " ������ �����.\n";
		cout << "\n ���� �����: " << attempt << "\n\n";
		while (guesses>0 && attempt!=target)    // ��� ����� �� ���������� �����, ��� �� ���������
		{
			char letter;
			cout << " ������ �����: "; cin >> letter;
			if (badChars.find(letter)!=string::npos || attempt.find(letter)!=string::npos)
			{
				cout << " !!! �� ��� �������� �� ����� !!! ��������� �� ���.\n";
				continue;
			}
			int loc = target.find(letter);      // �� ������ ������� �����
			if (loc==string::npos)
			{
				cout << "�� �������...\n"; --guesses;
				badChars += letter;
			}
			else
			{
				cout << "� ���� �����!\n";
				attempt[loc] = letter;
				loc = target.find(letter,loc+1);
				while (loc != string::npos)     // ��������� ������� �����
				{
					attempt[loc] = letter;
					loc = target.find(letter,loc+1);
				}
			}
			cout << "\n ���� �����: " << attempt << "\n\n"; // ��������� ������ �����
			if (attempt!=target)
			{
				if (badChars.size()>0) cout << "���������� �����: " << badChars << endl;
				
				switch (guesses)    // ��������� ��������� ���
				{
				case 6: case 5: cout << "���������� " << guesses << " ������ �����\n"; break;
				case 4: case 3: case 2: cout << "���������� " << guesses << " ���� ������\n"; break;
				case 1: cout << "���������� " << guesses << " ����� ������\n";
				case 0: cout << "������ ���� �����\n";
				}
				cout << string(10,'-')+"\n\n"; // "�������������" ���������
			}
		}
		if (guesses>0) cout << "\n²�����! �� �������!\n";
		else cout << "\n�������, �������� ����� \"" << target << "\".\n";
		cout << "\n +++ �� ������ ������ �� ���? (�/�): ";
		cin >> play;
	}
	cout << " * ������� ������ *\n";
	cin.get();
	return 0;
}