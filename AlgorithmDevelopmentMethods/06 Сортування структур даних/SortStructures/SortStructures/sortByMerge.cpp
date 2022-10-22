#include "dataProcedures.h"
#include <ctime>

void sortByMerge()
{
	cout << "\n *������ ���������� ����� ������ �������*\n\n";
	const char * fileName = "mergeDat.txt";
	cout << "����� �����? >>> "; int n; cin >> n;
	ofstream file(fileName);
	fillFile(file, n);
	showFile(fileName);
	sortFile(fileName);
	showFile(fileName);
	return;
}

void fillFile(ofstream& f, unsigned n)
{
	// �������� ���� ����������� ������ ����������
	int x;
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		x = rand() % (n * 2);
		f << ' ' << x;
	}
	f.close();
}
void showFile(const char * fileName)
{
	// �������� ���� ����� �� �����
	ifstream f(fileName);
	int x;
	while (!f.eof())
	{
		f >> x;
		cout << ' ' << x;
	}
	cout << '\n' << '\n';
	f.close();
}

void sortFile(const char * fileName)
{
	ifstream a(fileName);
	if (!a.is_open())
	{
		cout << "File " << fileName << " don\'t exists.\n";
		return;
	}
	ifstream b;
	// ������ ���������� ������i� �����i� � ���������� ������
	ofstream u("_1.tmp");
	ofstream v("_2.tmp");
	long long ka, kb;
	distribute(a, u, v, ka, kb);
	a.close(); u.close(); v.close();
	long long k = 2; // ���������� ����� ������������� ������
	bool odd = true;
	int x, y;
	// �������� ������, ���� ������ � � ���� ������
	while (ka > 0 && kb > 0)
	{
		// ������� ������� ��� ������� �������� - ��� ������
		if (odd)
		{
			a.open("_1.tmp"); b.open("_2.tmp");
			u.open(fileName); v.open("_3.tmp");
		}
		else
		{
			a.open(fileName); b.open("_3.tmp");
			u.open("_1.tmp"); v.open("_2.tmp");
		}
		odd = !odd;
		for (long long kk = 0; kk < kb; ++kk)
		{
			if (kk % 2 == 0) mergeFile(a, b, u, k);
			else mergeFile(a, b, v, k);
		}
		if (ka > kb) // ���� a - ������
		{
			if (kb % 2)
			{
				ka /= 2; kb = ka;
				while (!a.eof()) // ������� ������� ����� a
				{
					a >> x; v << ' ' << x;
				}

			}
			else // �� ���� ��� �ᒺ�����!
			{
				kb /= 2; ka = kb + 1;
				while (!a.eof()) // ������� ������� ����� a
				{
					a >> x; u << ' ' << x;
				}
			}
		}
		else // ����� ̲����� �������� �-��� ²�в�ʲ�
		{
			if ((kb - 1) % 2)
			{
				ka /= 2; kb = ka;
			}
			else
			{
				kb /= 2; ka = kb + 1;
			}
		}
		k *= 2;
		a.close(); b.close(); u.close(); v.close();
	}
	// �������� �������� �����
	if (odd)
	{
		remove(fileName);
		rename("_1.tmp", fileName);
	}
	else remove("_1.tmp");
	remove("_2.tmp"); remove("_3.tmp");
}

void distribute(ifstream & f, ofstream & a, ofstream & b, long long & ka, long long & kb)
	// ��������� ������ ����� f �� ����� a i b � ������ �� 2 ������
	// ka - ������� ������ � ���� a, kb - � ���� b
{
	int x, y;		 // �������� �����, ������� � �����
	ka = 0; kb = 0;  // ����������� ����� ���� �� ������
	// ���� �������� ���������� break, ���� ��������� ���� �����
	while (true)
	{
		// *** �������� �������� �� ����� a ***
		if (f.eof()) break;
		else
		{
			f >> x; ++ka;
			if (f.eof()) // ��������� ����� �� �� ����
			{
				a << ' ' << x; break;
				//a.write((char*) &x, sizeof x); break;
			}
			else
			{
				f >> y;
				if (x < y) a << ' ' << x << ' ' << y;
				else a << ' ' << y << ' ' << x;
			}
		}
		// *** ����� ��������� ��� ��� ����� b ***
		if (f.eof()) break;
		else
		{
			f >> x; ++kb;
			if (f.eof()) // ��������� ����� �� �� ����
			{
				b << ' ' << x; break;
			}
			else
			{
				f >> y;
				if (x < y) b << ' ' << x << ' ' << y;
				else b << ' ' << y << ' ' << x;
			}
		}
	}
}

void mergeFile(ifstream & a, ifstream & b, ofstream & c, long long k)
{
	// ��'���� ������ ������� k � ����� a � � ����� b � ������ �� � ���� c
	//
	int x, y;		 // �������� �����, ������� � �����
	a >> x; b >> y;  // ��������� �������� ����� ������
	long long i = 1; // ��������� �����������
	long long j = 1;
	while ( true )
	{
		if (x < y)
		{
			c << ' ' << x;
			if (i >= k || a.eof()) // ���� � ���������
			{
				c << ' ' << y; break;
			}
			else
			{
				a >> x; ++i;
			}
		}
		else
		{
			c << ' ' << y;
			if (j >= k || b.eof()) // ���� b ���������
			{
				c << ' ' << x; break;
			}
			else
			{
				b >> y; ++j;
			}
		}
	}
	while (i < k && !a.eof()) // �������� "������"
	{
		a >> x; ++i;
		c << ' ' << x;
	}
	while (j < k && !b.eof())
	{
		b >> y; ++j;
		c << ' ' << y;
	}
}