#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <list>
#include <set>
#include <algorithm>
#include <sstream>
using namespace std;

int main()
{
	// файлові потоки для заданого файла і результатів
	ifstream fin("OldmanAndSea.txt"); // заданий
	ofstream fout("result.txt");      // отриманий
	// доступ до фалів буде через ітератори
	istream_iterator <string> begin(fin), end;
	ostream_iterator <string> out(fout,"\n");

	// список для накопичення слів
	list <string> L;
	// всю роботу виконає алгоритм, ітератор потоку читання, і оператор введення з потоку
	// саме оператор введення "вміє" виокремлювати групи літер, відокремлених пропусками
	// нові слова дописуємо в кінець списку
	copy(begin, end, back_inserter(L));
	// якщо розкоментувати наступні два рядки, побачимо список відразу після створення
	//*out++ = "----------------------------- list after copy";
	//copy(L.begin(), L.end(), out);
	// вилучення повторних входжень слів - двоетапне
	L.sort();
	L.unique();
	// тепер можна зберегти отриманий результат
	*out++ = "----------------------------- list after sort & unique";
	// всю роботу знову виконує алгоритм
	copy(L.begin(),L.end(),out);
	// загальна кількість знайдених слів
	cout << "There are " << L.size() << " words\n";
	fin.clear(); fin.seekg(0);
	// множина для накопичення слів
	set <string> S;
	// вставляння в множину завжди починають з початку
	copy(begin, end, inserter(S, S.begin()));
	// все готово - можна зберігати результат
	*out++ = "----------------------------- set after copy";
	copy(S.begin(), S.end(), out);
	// загальна кількість знайдених слів
	cout << "There are " << S.size() << " words\n";

	// повертаємо файл і множину до початкового стану
	S.clear();
	fin.clear(); fin.seekg(0);
	// знаки, що підлягають вилученню помістимо в множину
	set<char> punct = { '.', ',', '!', '?', ':', ';', '-', '(', ')', '\"', '[', ']' };
	string line;
	// читатимемо з файла по одному рядку
	while (getline(fin, line))
	{
		// вилучення розділових знаків (нелітерних символів)
		transform(line.begin(), line.end(), line.begin(), [&punct](char c){ return punct.find(c) == punct.end() ? c : ' '; });
		// виокремлення слів і додавання до множини
		istringstream is(line);
		string word;
		while (is >> word) S.insert(word);
	}
	// все готово - можна зберігати результат
	*out++ = "----------------------------- set after input & wiping";
	copy(S.begin(), S.end(), out);
	// загальна кількість знайдених слів
	cout << "There are " << S.size() << " words\n";

	fin.close();
	fout.close();
	system("pause");
	return 0;
}
