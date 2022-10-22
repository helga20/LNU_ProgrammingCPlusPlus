#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
#include "Tools.h"
using namespace std;

int compare()
{
	ifstream in("testV.txt"); // 1.76 MB
	vector<string> vstrings;
	deque<string> dstrings;
	string line;

// Завантаження даних до вектора:
	auto begin = std::chrono::steady_clock::now();
	while (getline(in, line)) vstrings.push_back(line);
	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	cout << "Read into vector: " << elapsed_ms.count() << " ms ellapsed\n";
	in.close();
// Те саме для дека:
	ifstream in2("testD.txt"); // 1.76 MB
	begin = std::chrono::steady_clock::now();
	while (getline(in2, line)) dstrings.push_back(line);
	end = std::chrono::steady_clock::now();
	elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	cout << "Read into deque: " << elapsed_ms.count() << " ms ellapsed\n";
	in2.close();

// Тепер випробуємо індексування для вектора
	begin = std::chrono::steady_clock::now();
	for (size_t i = 0; i<vstrings.size(); ++i)
	{
		ostringstream ss;
		ss << i;
		vstrings[i] = ss.str()+": "+vstrings[i];
	}
	end = std::chrono::steady_clock::now();
	elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	cout << "Indexing vector: " << elapsed_ms.count() << " ms ellapsed\n";
// і для дека
	begin = std::chrono::steady_clock::now();
	for (size_t j = 0; j<dstrings.size(); ++j)
	{
		ostringstream ss;
		ss << j;
		dstrings[j] = ss.str()+": "+dstrings[j];
	}
	end = std::chrono::steady_clock::now();
	elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	cout << "Indexing deque: " << elapsed_ms.count() << " ms ellapsed\n";

// Порівняння перебору для вектора
	ofstream tmp1("tmp1.txt"), tmp2("tmp2.txt");
	begin = std::chrono::steady_clock::now();
	copy(vstrings.begin(), vstrings.end(), ostream_iterator<string>(tmp1, "\n"));
	end = std::chrono::steady_clock::now();
	elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	cout << "Iterating vector: " << elapsed_ms.count() << " ms ellapsed\n";
// і для дека
	begin = std::chrono::steady_clock::now();
	copy(dstrings.begin(), dstrings.end(), ostream_iterator<string>(tmp2, "\n"));
	end = std::chrono::steady_clock::now();
	elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	cout << "Iterating deque: " << elapsed_ms.count() << " ms ellapsed\n";
	tmp1.close(); tmp2.close();
	vstrings.clear(); vstrings.shrink_to_fit();
	dstrings.clear(); dstrings.shrink_to_fit();

// Завантаження в контейнер копіюванням
	ifstream fin("testV.txt");
	istream_iterator<string> FsIt(fin);
	begin = std::chrono::steady_clock::now();
	deque<string> newcont(FsIt, istream_iterator<string>());
	end = std::chrono::steady_clock::now();
	elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	cout << "Loading deque by copy: " << elapsed_ms.count() << " ms ellapsed\n";
	fin.close(); newcont.clear();
	system("pause");
	return 0;
}
/* Давні результати, виміряні в "тіках"
Read into vector: 766
Read into deque: 531
Indexing vector: 1531
Indexing deque: 2219
Iterating vector: 328
Iterating deque: 297

Read into vector: 9655
Read into deque: 2077
Indexing vector: 1231
Indexing deque: 1388
Iterating vector: 85
Iterating deque: 100
*/