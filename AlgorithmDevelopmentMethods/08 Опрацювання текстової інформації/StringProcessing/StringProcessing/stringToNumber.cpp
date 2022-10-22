#include "processProcedures.h"
#include <string>
#include <sstream>

void stringToNumber()
{
	cout << "\n *������������ ����� - ������ ���� �� �����-���������� - �� �����*\n";

	cout << "\n-����� � ���� �-\n";
	const unsigned size = 256;  // ������� ������ ����� ������ ����
	char line[size] = { '\0' }; // ����� ���������� ������� � ����� 0
	cout << "������ ����������� ����, �� ������ �����:\n";
	cin.getline(line, size);        // �������� ����� ��������� ������� ������

	cout << "\n   ������������ ������� ��������\n";
	int ErrCode;
	int k = recognizeInteger(line, ErrCode);
	if (ErrCode == -1)
		cout << "������� �����: " << k << '\n';
	else
		cout << "����� ������ ������� � ������� " << ErrCode
		<< " ������� ��������� " << k << '\n';

	cout << "\n   ������������ ����������� ��������\n";
	k = std::atoi(line);
	if (errno == ERANGE) cout << "Error: ������� ������������\n";
	cout << "������� �����: " << k << "  ��� ������� " << errno << '\n';
	errno = 0;

	cout << "\n   ������������ ������, ����������� �� �����\n";
	std::string Line(line);
	std::istringstream stream(Line);
	stream >> k;                // ������������ ������ �������� ��������
	cout << "������� �����: " << k << '\n';
	return;
}

void intSuccession()
{
	cout << "\n *���������� ���� ����� �����, ��������� � �����*\n";
	char* succ = "25 -32 777 12 -98 -5 2018";
	cout << "������ �����������:\n" << succ << '\n';
	int sum = 0;
	int pos = 0;
	cout << "����� �����������:\n";
	do
	{
		int k = recognizeInteger(succ += pos, pos);
		cout << k << '\n';
		sum += k;
	} while (pos != -1);
	cout << " Summ = " << sum << '\n';
}

int recognizeInteger(const char* line, int& Pos)
{
	const int max = INT_MAX / 10;
	const char* curr = line;
	int result = 0;                  // �����, ��� ����� ����������
	Pos = -1;
	while (*curr == ' ' || *curr == '\t') ++curr;  // ���������� ��������
	bool sign = false;               // sign ���'��� ��� �������� �����
	if (*curr == '+') ++curr;        // ���� ����� ����������,
	if (*curr == '-')                // � ���� ����� �����'�����
	{
		sign = true;
		++curr;
	}
	while (*curr != '\0')            // ����������� ���� �����
	{
		if (*curr >= '0' && *curr <= '9')
		{                            // �������� ����� ������������ �� �����
			int k = *curr - '0';     // �� �� ������� ������������?
			if (max < result || max == result && k > 7)
			{                        // ���� ���, �� ���������� ����������
				Pos = curr - line;
				break;
			}
			result = result * 10 + k;// ������ ���� ����� �� ����������
			++curr;
		}
		else
		{                            // ������� ������� ����������� �������
			Pos = curr - line;
			break;
		}
	}
	return sign ? -result : result;
}