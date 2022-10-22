#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <windows.h>
using namespace std;

// Гра. Відгадайте слово по буквах за шість спроб.
// Найстарше покоління пам'ятає цю гру під назвою "Шибениця", середнє - телешоу "Поле чудес"
// Знайдіть у тексті програми всі випадки використання класу string,
// поясніть, які конструктори, які методи, які константи використано, і для чого

const int NUM = 31;
const string wordlist[NUM] = {
	"матуся", "молоко", "Україна", "університет", "навчання", "кохання",
	"програмування", "верифікація", "комп'ютер", "алгоритм", "шаблон", "інструкція",
	"родина", "дружба", "обов'язок", "робота", "досягнення", "нагорода",
	"відпочинок", "розвага", "мандрівка", "екскурсія", "автомобіль", "рюкзак",
	"програміст", "менеджер", "студент", "декан", "доцент", "лекція",
	"успіх"};

int main()
{
	SetConsoleOutputCP(1251); SetConsoleCP(1251);
	srand(time(0));
	char play;
	cout << "Спробуєте відгадати слово? (т/н) ";
	cin >> play;
	while (play=='т' || play=='Т')
	{
		string target = wordlist[rand()%NUM];   // слово "загадує" програма випадковим чином
		int len = target.length();
		string attempt(len,'*');                // приховане зображення загаданого слова
		string badChars;                        // програма запам'ятовує всі названі літери. хибні - також
		int guesses = 6;                        // кількість використаних спроб
		cout << "\nЗагадане слово має " << len << " букв.\n"
			<< "Ви вгадуєте по одній букві. У Вас " << guesses << " хибних спроб.\n";
		cout << "\n Ваше слово: " << attempt << "\n\n";
		while (guesses>0 && attempt!=target)    // гра триває до вичерпання спроб, або до відгадання
		{
			char letter;
			cout << " Скажіть букву: "; cin >> letter;
			if (badChars.find(letter)!=string::npos || attempt.find(letter)!=string::npos)
			{
				cout << " !!! Ви вже називали цю букву !!! Спробуйте ще раз.\n";
				continue;
			}
			int loc = target.find(letter);      // чи вгадав гравець букву
			if (loc==string::npos)
			{
				cout << "Не вгадали...\n"; --guesses;
				badChars += letter;
			}
			else
			{
				cout << "Є така буква!\n";
				attempt[loc] = letter;
				loc = target.find(letter,loc+1);
				while (loc != string::npos)     // відкриваємо вгадану букву
				{
					attempt[loc] = letter;
					loc = target.find(letter,loc+1);
				}
			}
			cout << "\n Ваше слово: " << attempt << "\n\n"; // оновлений вигляд слова
			if (attempt!=target)
			{
				if (badChars.size()>0) cout << "Неправильні букви: " << badChars << endl;
				
				switch (guesses)    // узгоджуємо закінчення слів
				{
				case 6: case 5: cout << "Залишилося " << guesses << " хибних спроб\n"; break;
				case 4: case 3: case 2: cout << "Залишилося " << guesses << " хибні спроби\n"; break;
				case 1: cout << "Залишилася " << guesses << " хибна спроба\n";
				case 0: cout << "Більше нема спроб\n";
				}
				cout << string(10,'-')+"\n\n"; // "деекоративний" розділювач
			}
		}
		if (guesses>0) cout << "\nВІТАЄМО! Ви вгадали!\n";
		else cout << "\nВибачте, загадане слово \"" << target << "\".\n";
		cout << "\n +++ Чи хочете зіграти ще раз? (т/н): ";
		cin >> play;
	}
	cout << " * Бувайте здорові *\n";
	cin.get();
	return 0;
}