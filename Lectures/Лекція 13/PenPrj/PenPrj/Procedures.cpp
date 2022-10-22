#include "Procedures.h"
#include <fstream>
#include <sstream>

//������������ ���������� ��'���� - �� �������� �����������-����������
void Proc()
{
	cout << "------- Proc -----\n";
	Pen P;
	for (int i = 0; i < 5; ++i)
	{
		P.write(string((i + 2) * 2, '*'));
		cout << endl;
	}
	cout << P << endl;
}

//������������ ��'���� � �����, ����� �� �����
int LoadPens(const char * fileName, Pen*& penal)
{
	std::ifstream fin(fileName);
	std::ofstream fout("Result.txt");
	int n;
	fin >> n;	//������ � ���� �������� �������
	penal = new Pen[n];
	for (int i = 0; i < n; ++i)
	{
		fin >> penal[i];
	}
	//��'���� �������� �� ������� � �������� �� �����
	for (int i = 0; i < n; ++i)
	{
		cout << penal[i] << endl;
		fout << penal[i] << endl;
	}
	fin.close();
	fout.close();
	return n;
}

//������������ ��'���� ��� ��������� ������, ��������� ��'���� 
Pen UsePens(Pen* penal, int n)
{
	//������ �� ����� ����� �����, �������� "�������" ����� ������ �������
	for (int i = 0; i < n; ++i)
	{
		if (!penal[i].isReady()) penal[i].switchOn();
		penal[i].write("Hello, WORLD!");
		cout << endl;
	}
	//��������� ����� � ��������� ������� �������
	int minNo = 0;
	for (int i = 1; i < n; ++i)
	{
		if (penal[minNo] > penal[i]) minNo = i;
	}
	cout << "The minimal pen is " << penal[minNo] << endl;
	ofstream fout("Result.txt", ios::app);
	fout << "The minimal pen is " << penal[minNo] << endl;
	fout.close();
	return penal[minNo];
}

//����������� �������
void CatchException(Pen& pen)
{
	const char * sentence = "This article unfortunately will be quite long because of the scope of the code presented.";
	//����� ����� �������, ����� ��������� ��������
	try
	{
		pen.write(sentence);
	}
	//��������� ������� ����� � ���������� � ���� � ����
	catch (int pos)
	{
		pen.refill(Pen::GreenOnWhite, 'G');
		pen.write(sentence + pos);
		/*cout << "\n Upss - out of ink :(\n\n";
		pen.write(sentence);*/
	}
	cout << endl << pen << endl;
}

//������ ������������ ���������� ���-��������, ����������� ���������
void ShowColoredText(const char * filename)
{
	const int n = 5;
	Pen pens[n] = { Pen(Pen::BlackOnWhite, 'P'), Pen(Pen::BlueOnWhite, 'G'), Pen(Pen::RedOnWhite, 'G'),
		Pen(Pen::GreenOnWhite, 'O'), Pen(Pen::BlueOnWhite, 'I') };
	cout << "\n\n";
	string keyWords = "if-else-switch-break-case-default-for-while-do-goto-return-try-catch-new-delete-throw";
	string types = "const-void-int-double-char-bool-float-string-cin-cout";
	for (int i = 0; i < n; ++i) pens[i].switchOn();

	ifstream fin(filename);
	while (!fin.eof())
	{
		// ���� ������ �� ������ �����
		string line; getline(fin, line);
		int i = 0;
		while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') cout << line[i++];

		// ��������� ���������� ����� �� ����� �����
		istringstream sin(line);
		while (!sin.eof())
		{
			string word; sin >> word;
			char term = sin.get();
			if (term == -1) term = '\n';

			Pen::ColorConstant color;
			int len = word.length();
			//�������� ���� �������� �� ����������� �������
			if (len > 1)
			{
				if (keyWords.find(word) != string::npos || word[0] == '#') color = Pen::BlueOnWhite;
				else if (types.find(word) != string::npos) color = Pen::RedOnWhite;
				else if (word[0] == '/' && word[1] == '/') color = Pen::GreenOnWhite;
				else color = Pen::BlackOnWhite;
			}
			else color = Pen::BlackOnWhite;
			if (color == Pen::GreenOnWhite) // ������� ��������
			{
				string rest; getline(sin, rest);
				word += term + rest;
				term = '\n';
			}

			//����� ������� �����
			int currentPen = 0;
			while (currentPen < n && pens[currentPen].whatColor() != color)
				++currentPen;

			//������ ���������
		rep:
			try
			{
				pens[currentPen].write(word);
			}
			catch (...)
			{
				cout << " --- UPPSSS\n";
				pens[currentPen].refill();
				goto rep;
			}
			cout << term;
		}
	}
	fin.close();
	cout << "\n\n";
}