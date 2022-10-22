#pragma once
#include <string>
#include <iostream>
using namespace std;

template <typename TPresent>
class PresentBox
{
private:
	string recipientName;
	TPresent present;

public:
	PresentBox();
	PresentBox(const string& name, const TPresent& P);
	PresentBox(const PresentBox& PB);
	~PresentBox();

	void printPresentBoxInfo() const;
	double getPresentBoxPrice() const;

	void setRecipient(const string& name);
	void setPresent(const TPresent& P);

	void setPresentDiscount(int discount);

	void readPresentBox(istream& in);
	void writePresentBox(ostream& out) const;
};

template <typename TPresent>
PresentBox<TPresent>::PresentBox()
	: recipientName(), present()
{}

template <typename TPresent>
PresentBox<TPresent>::PresentBox(const string& name, const TPresent& P)
	: recipientName(name), present(P)
{}

template <typename TPresent>
PresentBox<TPresent>::PresentBox(const PresentBox& PB)
	: recipientName(PB.recipientName), present(PB.present)
{}

template <typename TPresent>
PresentBox<TPresent>::~PresentBox()
{}

template <typename TPresent>
void PresentBox<TPresent>::printPresentBoxInfo() const
{
	cout << "Present for: " << recipientName << "\n";
	present.print();
}

template <typename TPresent>
double PresentBox<TPresent>::getPresentBoxPrice() const
{
	return present.getPrice() + 50.5;
}

template <typename TPresent>
void PresentBox<TPresent>::setRecipient(const string& name)
{
	recipientName = name;
}

template <typename TPresent>
void PresentBox<TPresent>::setPresent(const TPresent& P)
{
	present = P;
}

template <typename TPresent>
void PresentBox<TPresent>::setPresentDiscount(int discount)
{
	present.setDiscount(discount);
}

template <typename TPresent>
void PresentBox<TPresent>::readPresentBox(istream& in)
{
	in >> recipientName >> present;
}

template <typename TPresent>
void PresentBox<TPresent>::writePresentBox(ostream& out) const
{
	out << recipientName << ' ';
	present.writeTo(out);
}

template <typename TPresent>
istream& operator>>(istream& in, PresentBox<TPresent>& P)
{
	P.readPresentBox(in);
	return in;
}

template <typename TPresent>
ostream& operator<<(ostream& out, const PresentBox<TPresent>& P)
{
	P.writePresentBox(out);
	return out;
}