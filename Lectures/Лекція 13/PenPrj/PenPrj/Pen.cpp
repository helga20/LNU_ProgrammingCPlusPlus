#include "Pen.h"

static const char* ColorNames[8] = { "Black", "Blue", "Green", "Cyan", "Red", "Magenta", "Brown", "Grey" };

void Pen::setLength()
{
	switch (type)
	{
	case 'G': length = 500; break;
	case 'O': length = 1000; break;
	case 'I':
	case 'P': length = 1200; break;
	default: length = 0;
	}
}

Pen::Pen() : color(BlueOnWhite), type('G'), length(5000), ready(false)
{
	cout << "Default construction\n";
}

Pen::Pen(const Pen& p) : color(p.color), type(p.type), length(p.length), ready(p.ready)
{
	cout << "Copy construction\n";
}

Pen::Pen(ColorConstant c, char t) : color(c), ready(false)
{
	type = (t == 'G' || t == 'I' || t == 'O' || t == 'P') ? t : 'G';
	setLength();
	cout << "Parameter construction\n";
}

Pen::~Pen()
{
	cout << "Destruction " << *this << endl;
}

void Pen::write(const char * line)
{
	int sl = strlen(line);
	SetConsoleTextAttribute(hConsole, color);
	if (length >= sl)
	{
		cout << line;
		SetConsoleTextAttribute(hConsole, 0xF0);
		length -= sl;
	}
	else
	{
		int ex = length;
		for (int i = 0; i < length; ++i) cout << line[i];
		SetConsoleTextAttribute(hConsole, 0xF0);
		length = 0;
		throw ex;
	}
}

void Pen::write(const string& line)
{
	// Дублювання колу - ознака поганої архітектури класу.
	// Правильне рішення: звести все до виклику одного методу
	this->write(line.c_str());
}

void Pen::refill(ColorConstant c, char t)
{
	type = (t == 'G' || t == 'I' || t == 'O' || t == 'P') ? t : 'G';
	color = c;
	setLength();
}

void Pen::show(ostream& os) const
{
	if (&os == &cout)
	{
		SetConsoleTextAttribute(hConsole, MagentaOnWhite);
		os << "Pen(" << ColorNames[color - BlackOnWhite] << ',' << type << ',' << length << ',' << ready << ')';
		SetConsoleTextAttribute(hConsole, BlackOnWhite);
	}
	else
		os << "Pen(" << ColorNames[color - BlackOnWhite] << ',' << type << ',' << length << ',' << ready << ')';
}

void Pen::load(istream& is)
{
	string colorStr;
	is >> colorStr >> type >> length >> ready;
	int i = 0;
	while (i < 8 && ColorNames[i] != colorStr) ++i;
	color = (i < 8) ? ColorConstant(BlackOnWhite + i) : BlackOnWhite;
}

ostream& operator<<(ostream& os, const Pen & P)
{
	P.show(os);
	return os;
}
istream& operator>>(istream& is, Pen & P)
{
	P.load(is);
	return is;
}
bool Pen::operator>(Pen& Q)
{
	return this->length > Q.length;
}

// Статичні члени для налаштування консолі
HANDLE Pen::hConsole = 0;
void Pen::Init()
{
	if (hConsole == 0)
	{
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, BlackOnWhite);
		system("cls");
	}
}