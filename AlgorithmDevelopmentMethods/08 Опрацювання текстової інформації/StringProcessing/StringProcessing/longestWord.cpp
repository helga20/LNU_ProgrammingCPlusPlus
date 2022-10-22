#include "processProcedures.h"
#include <string>
#include <sstream>

using std::string;

void longestByArray()
{
	const int maxLength = 256;
	char text[maxLength] = { 0 }; // місце для майбутнього тексту
	cout << "Введіть текст (до 255 літер): ";
	cin.getline(text, maxLength);
	cout << "Ви ввели: " << text << '\n';
	// політерне опрацювання
	int start = 0;             // початок найдовшого слова
	int maxLen = 0;            // його довжина
	int curr = 0;              // початок тексту
	while (text[curr] != '\0') // опрацювання до термінального символа
	{
		int pos = curr;        // початок чергового слова
		while (text[curr] != '\0' && text[curr] != ' ')	++curr; // шукаємо його закінчення
		int len = curr - pos;  // довжина чергового слова
		if (len > maxLen)
		{                      // знайшли довше
			maxLen = len;
			start = pos;
		}
		while (text[curr] != '\0' && text[curr] == ' ') ++curr; // шукаємо наступне слово
	}
	// новий рядок міститиме найдовше слово
	char * longestWord = new char[maxLen + 1];
	for (int i = 0; i < maxLen; ++i) longestWord[i] = text[start + i];
	longestWord[maxLen] = '\0';
	cout << "Найдовше слово: " << longestWord << '\n';
	delete[] longestWord;
}

void longestByString()
{
	string text;
	cout << "Введіть текст: ";
	getline(cin, text);
	cout << "Ви ввели: " << text << '\n';
	// опрацювання за допомогою потоку літер
	std::istringstream s(text);
	string word, maxWord;
	int maxL = 0;
	while (s >> word) // оператор введення розпізнає пропуски
	{
		int L = word.length();
		if (L > maxL)
		{
			maxL = L;
			maxWord = word;
		}
	}
	cout << "Найдовше слово: " << maxWord << '\n';
}

void printLongest()
{
	cout << "\n *Відшукання найдовшого в тексті слова*\n";
	cout << "\n-З використанням рядка в стилі С-\n";
	longestByArray();
	cout << "\n-З використанням рядка-контейнера-\n";
	longestByString();
}