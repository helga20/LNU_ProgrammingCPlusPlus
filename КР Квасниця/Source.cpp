#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class automobile
{
private:
	string marka;
	string color;
	int price;
	int year;
public:
	automobile(string m = "", int y = 0, int p = 0, string c = ""):
		marka(m), year(y), price(p), color(c) {}
	automobile(const automobile &a)
	{
		this->marka = a.marka;
		this->price = a.price;
		this->year = a.year;
		this->color = a.color;
	}

	string get_marka(void) const
	{
		return this->marka;
	}
	
	string get_color(void) const
	{
		return this->color;
	}
	
	int get_year(void) const
	{
		return this->year;
	}
	
	int get_price(void) const
	{
		return this->price;
	}

	automobile operator+(const int &n)
	{
		this->price += n;
		return (*this);
	}

	automobile operator-(const int &n)
	{
		this->price -= n;
		return (*this);
	}

	friend bool operator==(const automobile&, const automobile&);
	friend ostream& operator<<(ostream&, const automobile&);
	friend istream& operator>>(istream&, automobile&);
};

bool operator==(const automobile &a, const automobile &b)
{
	bool ismarka = (a.marka == b.marka);
	bool iscolor = (a.color == b.color);
	bool isprice = (a.price == b.price);
	bool isyear = (a.year == b.year);
	return (ismarka && iscolor && isprice && isyear);
}

ostream& operator<<(ostream &os, const automobile &a)
{
	os << a.marka << ' ' << a.year << ' ' << a.price << ' ' << a.color;
	return os;
}

istream& operator>>(istream &is, automobile &a)
{
	is >> a.marka >> a.year >> a.price >> a.color;
	return is;
}

int main(void)
{
	ifstream readfile("automobiles.txt");
	int n;
	readfile >> n;
	
	automobile *autos = new automobile[n];
	for (int i = 0; i < n; ++i)
		readfile >> autos[i];

	cout << "Automobiles in the base: " << endl;
	for (int i = 0; i < n; ++i)
		cout << autos[i] << endl;

	cout << "\n\nChoose color: " << endl;
	string mycolor;
	cin >> mycolor;
	cout << "From year: ";
	int from;
	cin >> from;
	cout << "To year: ";
	int to;
	cin >> to;

	cout << "\n\nSuch an automobiles in the base: " << endl;
	ofstream writefile("output.txt");
	for (int i = 0; i < n; ++i)
		if (autos[i].get_color() == mycolor)
			if (autos[i].get_year() >= from && autos[i].get_year() <= to)
			{
				cout << autos[i] << endl;
				writefile << autos[i] << endl;
			}

	int *markas = new int[n] {0};
	int *arcount = new int[n] {0};
	int count = 0;
	for (int i = 0; i < n; ++i)
		if (!markas[i])
		{
			for (int j = i + 1; j < n; ++j)
				if (autos[i].get_marka() == autos[j].get_marka())
				{
					++markas[j];
					++arcount[i];
					++count;
				}
		}
	cout << "Different marks in the base:" << --count << endl;
	cout << "Every mark have: ";
	for (int i = 0; i < count + 2; ++i)
		cout << arcount[i] + 1 << ' ';
	cout << " autos" << endl;

	automobile maxprice = autos[0];
	for (int i = 1; i < n; ++i)
		if (maxprice.get_price() < autos[i].get_price())
			maxprice = autos[i];
	cout << "The most expensive car is: " << maxprice << endl;
	return 0;
}