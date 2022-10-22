#include <iostream>
#include <cctype>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <sstream>
#include "Procedures.h"
using namespace std;

void MapWordCount()
{
	cout << "\n*** Count words in the program\n\n";
	ifstream in("MultiSetWordCount.cpp");
	// відображення спочатку порожня, не містить жодного ключа
	map<string, int> wordmap;
	string line;
	while (getline(in, line))
	{
		transform(line.begin(), line.end(), line.begin(), replaceNotAlpha);
		istringstream is(line);
		string word;
		// оператор [] знаходить значення за ключем або
		// автоматично створює пару (ключ, значення за замовчуванням)
		while (is >> word) ++wordmap[word];
	}
	// словник можна вивести стандартним алгоритмом, якщо
	// перевантажено оператор виведення для pair
	copy(wordmap.begin(), wordmap.end(), ostream_iterator<pair<string, int>>(cout, "\n"));
	//for (auto it = wordmap.begin(); it != wordmap.end(); ++it)
	//{
	//	cout << *it << '\n';
	//}
	cout << '\n';
	system("pause");
	return;
}
