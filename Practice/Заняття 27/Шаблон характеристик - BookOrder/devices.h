#pragma once
#include <iostream>
using namespace std;

class PaperBook
{
public:
	void writeTo(ostream& out) const { out << "Paper Book by Staryy Lev"; }
};
ostream& operator<<(ostream& out, const PaperBook& P) { P.writeTo(out); return out; }

class PdfBook
{
public:
	void writeTo(ostream& out) const { out << "Pdf from Amazon"; }
};
ostream& operator<<(ostream& out, const PdfBook& Pdf) { Pdf.writeTo(out); return out; }

class EBook
{
public:
	void writeTo(ostream& out) const { out << "EBook for Kindle"; }
};
ostream& operator<<(ostream& out, const EBook& E) { E.writeTo(out); return out; }
