#ifndef _PEN_GUARD_
#define _PEN_GUARD_

#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Pen
{
public:
	enum ColorConstant { BlackOnWhite = 0xF0, BlueOnWhite, GreenOnWhite, CyanOnWhite, RedOnWhite, MagentaOnWhite, BrownOnWhite, GreyOnWhite };
private:
	static HANDLE hConsole;
private:
	ColorConstant color; // колір чорнила
	char type;           // тип чорнила: G-gel, I-ink, O-oil, P-paste
	int length;          // запас чорнила, заданий кількістю букв, які можна написати
	bool ready;          // чи можна писати ручкою
	void setLength();
public:
	static void Init();
	Pen();
	Pen(const Pen&);
	Pen(ColorConstant, char);
	~Pen();
	void switchOn() { ready = true; }
	void switchOff() { ready = false; }
	void write(const char *);
	void write(const string&);
	void refill(ColorConstant, char);
	void refill() { this->setLength(); };
	bool isReady() const { return ready && length > 0; }
	void show(ostream&) const;
	void load(istream&);
	bool operator>(Pen&);
	ColorConstant whatColor() const { return color; }
};
ostream& operator<<(ostream&, const Pen &);
istream& operator>>(istream&, Pen &);
		 	
#endif