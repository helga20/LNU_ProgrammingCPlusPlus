#include "dataProcedures.h"
#include <ctime>

void sortByMerge()
{
	cout << "\n *Зовнішнє сортування файла парним злиттям*\n\n";
	const char * fileName = "mergeDat.txt";
	cout << "Розмір файла? >>> "; int n; cin >> n;
	ofstream file(fileName);
	fillFile(file, n);
	showFile(fileName);
	sortFile(fileName);
	showFile(fileName);
	return;
}

void fillFile(ofstream& f, unsigned n)
{
	// заповнює файл випадковими цілими значеннями
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
	// виводить вміст файла на екран
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
	// Будуємо початковий розподiл записiв у тимчасових файлах
	ofstream u("_1.tmp");
	ofstream v("_2.tmp");
	long long ka, kb;
	distribute(a, u, v, ka, kb);
	a.close(); u.close(); v.close();
	long long k = 2; // початковий розмір впорядкованих відрізків
	bool odd = true;
	int x, y;
	// Виконаємо злиття, поки відрізки є в обох файлах
	while (ka > 0 && kb > 0)
	{
		// джерела відкрили для читання приймачі - для запису
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
		if (ka > kb) // ФАЙЛ a - ДОВШИЙ
		{
			if (kb % 2)
			{
				ka /= 2; kb = ka;
				while (!a.eof()) // копіюємо залишок файла a
				{
					a >> x; v << ' ' << x;
				}

			}
			else // усі пари вже об’єднано!
			{
				kb /= 2; ka = kb + 1;
				while (!a.eof()) // копіюємо залишок файла a
				{
					a >> x; u << ' ' << x;
				}
			}
		}
		else // ФАЙЛИ МІСТЯТЬ ОДНАКОВУ К-СТЬ ВІДРІЗКІВ
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
	// Вилучимо тимчасові файли
	if (odd)
	{
		remove(fileName);
		rename("_1.tmp", fileName);
	}
	else remove("_1.tmp");
	remove("_2.tmp"); remove("_3.tmp");
}

void distribute(ifstream & f, ofstream & a, ofstream & b, long long & ka, long long & kb)
	// розподіляє записи файла f до файлів a i b у відрізки по 2 записи
	// ka - кількість відрізків у файлі a, kb - у файлі b
{
	int x, y;		 // елементи даних, отримані з файла
	ka = 0; kb = 0;  // результуючі файли поки що порожні
	// цикл закінчимо процедурою break, коли досягнемо кінця файла
	while (true)
	{
		// *** Спочатку записуємо до файла a ***
		if (f.eof()) break;
		else
		{
			f >> x; ++ka;
			if (f.eof()) // прочитане число не має пари
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
		// *** Тепер повторимо все для файла b ***
		if (f.eof()) break;
		else
		{
			f >> x; ++kb;
			if (f.eof()) // прочитане число не має пари
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
	// об'єднує відрізки довжини k з файла a і з файла b і записує їх у файл c
	//
	int x, y;		 // елементи даних, отримані з файлів
	a >> x; b >> y;  // прочитали елементи перші відрізків
	long long i = 1; // лічильники прочитаного
	long long j = 1;
	while ( true )
	{
		if (x < y)
		{
			c << ' ' << x;
			if (i >= k || a.eof()) // файл а закінчився
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
			if (j >= k || b.eof()) // файл b закінчився
			{
				c << ' ' << x; break;
			}
			else
			{
				b >> y; ++j;
			}
		}
	}
	while (i < k && !a.eof()) // дописуємо "хвости"
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