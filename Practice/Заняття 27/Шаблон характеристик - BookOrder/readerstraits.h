#pragma once
#include "readers.h"
#include "books.h"
#include "devices.h"
using namespace std;

template <typename Reader>
class ReaderTraits;

template<> class ReaderTraits<Kid>
{
public:
	//typedef FantasyBook book_type;
	using book_type = FantasyBook;
	using device_type = PaperBook;
};

template<> class ReaderTraits<Developer>
{
public:
	//typedef CppBook book_type;
	using book_type = CppBook;
	using device_type = PdfBook;
};

template<> class ReaderTraits<Tourist>
{
public:
	typedef LvivGuide book_type;
	typedef EBook device_type;
};

template<> class ReaderTraits<Student>
{
public:
	using book_type = CppBook;
	using device_type = PaperBook;
};