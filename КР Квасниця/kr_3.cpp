#include <iostream>
#include <fstream>

#include <iterator>
#include <algorithm>
#include <numeric>

#include <vector>
#include <string>

#include <map>
using namespace std;

class medicine
{
private:
	string name;
	string rechovyna;
	string vyrobnyk;
	double price;
	int number;

public:
	medicine(/**/)
		 /*:*/ {}

	friend ostream& operator<<(ostream &os, const medicine &a)
	{
		os << a.name << ' ' << a.rechovyna << ' ' << a.vyrobnyk << ' ' << a.price << ' ' << a.number << endl;
		return os;
	}

	friend istream& operator>>(istream &is, medicine &a)
	{
		is >> a.name >> a.rechovyna >> a.vyrobnyk >> a.price >> a.number;
		return is;
	}

	bool operator<(const medicine &a)
	{
		if (this->name == a.name)
			if (this->vyrobnyk == a.vyrobnyk)
				return (this->rechovyna < a.rechovyna);
		return this->name < a.name;
	}

	string get_name(void) const
	{
		return this->name;
	}

	string get_vyrobnyk(void) const
	{
		return this->vyrobnyk;
	}

	string get_rechovyna(void) const
	{
		return this->rechovyna;
	}

	double get_price(void) const
	{
		return this->price;
	}

	int get_number(void) const
	{
		return this->number;
	}
};

int main(void)
{
	try
	{
		ifstream fin("Input.txt");
		if (!fin.good())
			throw "Cannot open an input file!";

		istream_iterator<medicine> start(fin), end;
		vector<medicine> vect(start, end);

		sort(vect.begin(), vect.end());

		ostream_iterator<medicine> out(cout, "\n");
		copy(vect.begin(), vect.end(), out);
		cout << endl << endl;

		vector<medicine> another;
		double pr;
		string v;
		cin >> pr >> v;
		copy_if(vect.begin(), vect.end(), another.begin(), [v, pr](medicine a) {return (a.get_vyrobnyk() == v && a.get_price() < pr); });
		copy(another.begin(), another.end(), out);
		cout << endl << endl;

		map<string, int> map_1;
		for (int i = 0; i < vect.size(); ++i)
			map_1[vect[i].get_vyrobnyk()] += vect[i].get_number();

		auto minimum = min_element(map_1.begin(), map_1.end(), [](pair<const string, int> a, pair<const string, int> b) { return a.second < b.second; });
		cout << minimum->first << ' ' << minimum->second << endl << endl;

		map<string, vector<string>> map_2;
		for (int i = 0; i < vect.size(); ++i)
			map_2[vect[i].get_vyrobnyk()].push_back(vect[i].get_name());

		for (auto it : map_2)
			sort(it.second.begin(), it.second.end());

		for (auto it : map_2)
		{
			cout << it.first << ": ";
			for (auto it_2 : it.second)
				cout << it_2 << ' ';
			cout << endl;
		}

		cout << endl;

		string r;
		cin >> r;
		double sum = 0;
		for (int i = 0; i < vect.size(); ++i)
			if (vect[i].get_rechovyna() == r)
				sum += vect[i].get_price();
		cout << sum << endl;

	}
	catch (const char* what)
	{
		cout << what << endl;
	}
	catch (...)
	{
		cout << "Unknown error!" << endl;
	}


	return 0;
}