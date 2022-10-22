#include "Procedures.h"
#include <fstream>
#include <sstream>

//Випробування локального об'єкта - як працюють конструктор-деструктор
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

//Завантаження об'єктів з файла, запис до файла
int LoadPens(const char * fileName, Pen*& penal)
{
	std::ifstream fin(fileName);
	std::ofstream fout("Result.txt");
	int n;
	fin >> n;	//першою у файлі записана кількість
	penal = new Pen[n];
	for (int i = 0; i < n; ++i)
	{
		fin >> penal[i];
	}
	//об'єкти виводимо на консоль і записуємо до файла
	for (int i = 0; i < n; ++i)
	{
		cout << penal[i] << endl;
		fout << penal[i] << endl;
	}
	fin.close();
	fout.close();
	return n;
}

//Використання об'єктів для написання тексту, порівняння об'єктів 
Pen UsePens(Pen* penal, int n)
{
	//Готуємо до друку кожну ручку, виводимо "головну" фразу різними ручками
	for (int i = 0; i < n; ++i)
	{
		if (!penal[i].isReady()) penal[i].switchOn();
		penal[i].write("Hello, WORLD!");
		cout << endl;
	}
	//Знаходимо ручку з найменшим запасом чорнила
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

//Опрацювання винятків
void CatchException(Pen& pen)
{
	const char * sentence = "This article unfortunately will be quite long because of the scope of the code presented.";
	//Ручка майже списана, мають виникнути проблеми
	try
	{
		pen.write(sentence);
	}
	//Заправимо списану ручку і продовжимо з того ж місця
	catch (int pos)
	{
		pen.refill(Pen::GreenOnWhite, 'G');
		pen.write(sentence + pos);
		/*cout << "\n Upss - out of ink :(\n\n";
		pen.write(sentence);*/
	}
	cout << endl << pen << endl;
}

//Просте розпізнавання синтаксису срр-програми, відображення кольорами
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
		// Файл читаємо по одному рядку
		string line; getline(fin, line);
		int i = 0;
		while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') cout << line[i++];

		// Розберемо прочитаний рядок на окремі слова
		istringstream sin(line);
		while (!sin.eof())
		{
			string word; sin >> word;
			char term = sin.get();
			if (term == -1) term = '\n';

			Pen::ColorConstant color;
			int len = word.length();
			//Виберемо колір відповідно до синтаксичної категорії
			if (len > 1)
			{
				if (keyWords.find(word) != string::npos || word[0] == '#') color = Pen::BlueOnWhite;
				else if (types.find(word) != string::npos) color = Pen::RedOnWhite;
				else if (word[0] == '/' && word[1] == '/') color = Pen::GreenOnWhite;
				else color = Pen::BlackOnWhite;
			}
			else color = Pen::BlackOnWhite;
			if (color == Pen::GreenOnWhite) // Знайшли коментар
			{
				string rest; getline(sin, rest);
				word += term + rest;
				term = '\n';
			}

			//Пошук потрібної ручки
			int currentPen = 0;
			while (currentPen < n && pens[currentPen].whatColor() != color)
				++currentPen;

			//Власне виведення
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