#include "Pen.h"
#include "Procedures.h"
#include <fstream>

int main()
{
	Pen::Init();
	SetConsoleOutputCP(1251);
	cout << " *** Випробування конструкторів для звичайних змінних\n\n";
	Pen A;
	Pen B(Pen::RedOnWhite, 'O');
	Pen C(B);
	C.write("Hello"); cout << endl;
	A.show(cout);
	B.show(cout);
	C.show(cout);
	cout << endl;
	cout << " *** Порівняння об'єктів\n\n";
	cout << "A = " << A << endl;
	cout << "B = " << B << endl;
	if (A > B)
	{
		cout << "max=" << A << endl;
	}
	else
	{
		cout << "max=" << B << endl;
	}
	system("pause");
	cout << "\n *** Динамічний об'єкт\n\n";
	Pen * D = new Pen(C);
	D->write("Bye"); cout << endl;
	D->show(cout); cout << endl;
	delete D;
	system("pause");

	cout << "\n *** Локальні об'єкти в тілі процедури\n\n";
	Proc();
	system("pause");
	cout << "\n *** Завантаження об'єктів з файла до масиву\n\n";
	Pen * pens;
	int n = LoadPens("Pens.txt", pens);
	cout << "\n *** Використання завантажених об'єктів\n\n";
	Pen penny = UsePens(pens, n);
	delete[] pens;
	system("pause");
	cout << "\n *** Випробування винятків\n\n";
	CatchException(penny);
	system("pause");

	cout << "\n *** Виведення тексту різними кольорами\n\n";
	ShowColoredText("Procedures.cpp");
	system("pause");
	return 0;
}