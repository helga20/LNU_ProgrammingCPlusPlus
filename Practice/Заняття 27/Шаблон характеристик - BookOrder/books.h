#pragma once
#include <iostream>
#include <string>
using namespace std;

class FantasyBook
{
public:
	void writeTo(ostream& out) const { out << "Harry Potter"; }
};
ostream& operator<< (ostream& out, const FantasyBook& F) { F.writeTo(out); return out; }

class CppBook
{
public:
	void writeTo(ostream& out) const { out << "C++ Handbook"; }
};
ostream& operator<< (ostream& out, const CppBook& C) { C.writeTo(out); return out; }

class LvivGuide
{
public:
	void writeTo(ostream& out) const { out << "Lviv Guide book"; }
};
ostream& operator<< (ostream& out, const LvivGuide& L) { L.writeTo(out); return out; }