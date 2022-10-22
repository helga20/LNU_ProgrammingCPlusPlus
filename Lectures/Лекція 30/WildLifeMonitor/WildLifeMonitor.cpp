#include <algorithm>
#include <ctime>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <map>

namespace std
{
	template<typename F, typename S>
	ostream& operator<<(ostream& os, const pair<F, S>& p)
	{
		return os << p.first << " : " << p.second;
	}
}

using namespace std;

// Опис спостереження поєднує координати і час
class DataPoint
{
	int x, y;                // координати 
	time_t time;             // час 
public:
	DataPoint() : x(0), y(0), time(0) {}
	DataPoint(int xx, int yy, time_t tm) : x(xx), y(yy), time(tm) {}
	int getX() const { return x; }
	int getY() const { return y; }
	const time_t* getTime() const { return &time; }
};

ostream& operator<<(ostream& os, const DataPoint& p)
{
	char time[30]; ctime_s(time, sizeof time, p.getTime());
	return os << "sighted at x=" << p.getX() << ", y="
		<< p.getY() << ", time=" << time;
}

// джерело назв видів тварин
vector<string> animals{ "chipmunk", "beaver", "marmot", "weasel", "squirrel", "bear",
	"ptarmigan", "eagle", "hawk", "vole", "deer", "otter", "hummingbird", "elk" };
    /* "бурундук", "бобер", "бабак", "ласка", "білка", "ведмідь",
       "рябчик", "орел", "яструб", "полівка", "олень", "видра", "колібрі", "лось"*/

// запис в журналі
typedef pair<string, DataPoint> Sighting;

/*ostream& operator<<(ostream& os, const Sighting& s)
{
	char time[30]; ctime_s(time, sizeof time, s.second.getTime());
	return os << s.first << " sighted at x=" << s.second.getX() << ", y="
		<< s.second.getY() << ", time=" << time;
}*/

// генератор для автоматичного наповнення журналу записами
class SightingGen
{
	vector<string>& animals;
	enum { D = 100 };
public:
	SightingGen(vector<string>& an): animals(an) {}
	Sighting operator()()
	{
		Sighting result;
		// вид тварини вибираємо з переліку випадково
		int select = rand() % animals.size();
		result.first = animals[select];
		// координати випадкові, час поточний
		result.second = DataPoint(rand() % D, rand() % D, time(0));
		return result;
	}
};

// текстове меню для вибору виду тварини
int menu()
{
	cout << "\nSELECT an animal or '-1' to quit:\n";
	for (size_t i = 0; i < animals.size(); i++)
	{
		cout << '[' << i << ']' << animals[i] << "    ";
		if ((i + 1) % 5 == 0) cout << '\n';
	}
	cout << endl;
	int i; cin >> i;
	if (i > 0) i %= animals.size();
	return i;
}

// тут усе відбувається
int main()
{
	typedef multimap<string, DataPoint> DataMap;
	typedef DataMap::iterator DMIter;
	// журнал спостережень
	DataMap sightings;
	srand(time(0));
	// записуємо в журнал 50 спостережень
	generate_n(inserter(sightings, sightings.begin()), 50, SightingGen(animals));
	// весь журнал - на екран
	cout << "\n\nSEE AT ALL SIGHTINGS HERE: \n";
	copy(sightings.begin(), sightings.end(), ostream_iterator<Sighting>(cout, ""));
	cout << "----------------------------\n";
	// отримання інформації про вибрану тварину
	for (int count = 0; count < 10; ++count)
	{
		int i = menu();
		if (i < 0) break;
		pair<DMIter, DMIter> range = sightings.equal_range(animals[i]);
		copy(range.first, range.second,	ostream_iterator<Sighting>(cout, ""));
	}
	return 0;
}
