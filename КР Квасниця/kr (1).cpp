#include <iostream>
#include <fstream>
#include <string>
#include <exception>
using namespace std;

class monitor
{
protected:
	string model;
	double diagonal;

public:
	monitor(string m = "", double d = 0) :
		model(m), diagonal(d) { }
	~monitor(void) = default;

	string get_model(void) const
	{
		return this->model;
	}
	
	double get_diagonal(void) const
	{
		return this->diagonal;
	}

	bool operator>(const monitor &m)
	{
		return (this->diagonal > m.diagonal);
	}

	virtual ostream& print(ostream&) const abstract;
	virtual istream& read(istream&) abstract;

	friend ostream& operator<<(ostream &os, const monitor *p)
	{
		p->print(os);
		return os;
	}

	friend istream& operator>>(istream &is, monitor *p)
	{
		p->read(is);
		return is;
	}
};

class plasm : public monitor
{
private:
	int resolution;
	int angle;

public:
	plasm(string m = "", double d = 0, int r = 0, int a = 0) :
		monitor(m, d), resolution(r), angle(a) { }
	~plasm(void) = default;

	int get_resolution(void) const
	{
		return this->resolution;
	}

	int get_angle(void) const
	{
		return this->angle;
	}

	ostream& print(ostream& os) const override
	{
		os <<  this->model << " " << this->diagonal << " " << this->resolution << " " << this->angle << endl;
		return os;

	}
	istream& read(istream& is) override
	{
		is >> this->model >> this->diagonal >> this->resolution >> this->angle;
		return is;
	}
};

class promen: public monitor
{
private:
	int frequency;
	int rad;

public:
	promen(string m = "", double d = 0, int f = 0, int r = 0) :
		monitor(m, d), frequency(f), rad(r) { }
	~promen(void) = default;

	int get_frequency(void) const
	{
		return this->frequency;
	}
	int get_rad(void) const
	{
		return this->rad;
	}

	ostream& print(ostream& os) const override
	{
		os << this->model << " " << this->diagonal << " " << this->frequency << " " << this->rad << endl;
		return os;

	}
	istream& read(istream& is) override
	{
		is >> this->model >> this->diagonal >> this->frequency >> this->rad;
		return is;
	}
};

int main(void)
{
	try 
	{
		ifstream fin("Text.txt");
		if (!fin.good())
			throw exception("A file cannot be opened or it is damaged.");

		size_t size;
		fin >> size;

		monitor **mons = new monitor*[size];
		if (!mons)
			throw exception("Cannor create an array");

		bool type;
		for (int i = 0; i < size; ++i)
		{
			fin >> type;

			if (type)
				mons[i] = new promen();
			else
				mons[i] = new plasm();

			fin >> mons[i];
		}

		cout << "Unsorted mons: " << endl;
		for (int i = 0; i < size; ++i)
			cout << mons[i];

		for (int i = size / 2; i >= 1; i /= 2)
			for (int j = i; j < size; ++j)
				for (int k = j; k >= i && *mons[k - i] > *mons[k]; k -= i)
				{
					monitor *temp = mons[k];
					mons[k] = mons[k - i];
					mons[k - i] = temp;
				}

		cout << "\n\nSorted mons: " << endl;
		for (int i = 0; i < size; ++i)
			cout << mons[i];

		int res, freqmin, freqmax, count = 0;
		cout << "\n\nMin resolution to show: ";
		cin >> res;
		for (int i = 0; i < size; ++i)
			if (dynamic_cast<plasm*>(mons[i]))
			{
				plasm *temp = dynamic_cast<plasm*>(mons[i]);
				if (temp->get_resolution() >= res)
					cout << temp;
			}

		cout << "\n\nFrequency to show: ";
		cin >> freqmin >> freqmax;
		for (int i = 0; i < size; ++i)
			if (dynamic_cast<promen*>(mons[i]))
			{
				promen *temp = dynamic_cast<promen*>(mons[i]);
				if (temp->get_frequency() >= freqmin && temp->get_frequency() <= freqmax)
					++count;
			}
		cout << "Monitors with such a frequency: " << count << endl;

	}
	catch (const char* what)
	{
		cout << "A problem occured: " << what << endl;
		return EXIT_FAILURE;
	}
	catch (exception ex)
	{
		cout << "A problem occured: " << ex.what() << endl;
		return EXIT_FAILURE;
	}
	
	return 0;
}