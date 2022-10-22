#pragma once
#include "readerstraits.h"
using namespace std;

template <typename Reader, typename Traits = ReaderTraits<Reader>>
class BookOrder
{
private:
	//typedef typename Traits::book_type BookType;
	using BookType = typename Traits::book_type;
	using DeviceType = typename Traits::device_type;

	Reader m_reader;
	BookType m_book;
	DeviceType m_device;

public:
	BookOrder(const Reader& R) : m_reader(R) {}
	void printOrderInfo() const
	{
		cout << "Reader info: " << m_reader << "\n";
		cout << "Book info:   " << m_book << "\n";
		cout << "Device info: " << m_device << "\n";
	}
};
