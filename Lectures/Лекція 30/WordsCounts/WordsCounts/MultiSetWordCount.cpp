#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include "Procedures.h"
using namespace std;

char replaceNotAlpha(char c)
{
	return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == '_' ? c : ' ';
}

/* Обчислення кількості слів у файлі за допомогою мультимножини
   Зверніть увагу на те, як обчислюється кількість однакових елементів*/
void MultisetWordCount()
{
	cout << "\n*** Count words in the program with help of multiset\n\n";
	ifstream in ("MultiSetWordCount.cpp");
	multiset<string> wordmset;
	string line;
	while (getline(in, line)) // завантажуємо по одному рядку
	{                  // залишаємо в рядках лише латинські літери
		transform(line.begin(), line.end(), line.begin(), replaceNotAlpha);
		istringstream is(line);
		string word;   // читаємо слова і додаємо їх до контейнера
		while (is >> word) wordmset.insert(word);
	}
	// отриману мультимножину переберемо за допомогою ітераторів
	typedef multiset<string>::iterator MSIter;
	MSIter it = wordmset.begin();
	while (it != wordmset.end())
	{
		// метод equal_range повертає пару ітераторів [початок; кінець)
		pair<MSIter, MSIter> p = wordmset.equal_range(*it);
		// шаблонна функція для обчислення довжини інтервалу
		int count = distance(p.first, p.second);
		cout << *it << "  :  " << count << '\n';
		it = p.second; // перехід до наступного слова
	}
	system("pause");
	return;
}
