#include <fstream>
#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// реалізацію можна змінити, змінивши коментарі
typedef stack<string> Stack;
typedef queue<string> Queue;
//typedef stack<string, vector<string> > Stack;
//typedef stack<string, list<string> > Stack;
//typedef queue<string, vector<string> > Queue;
//typedef queue<string, list<string> > Queue;

// ітератори стека та черги
template<typename T>
class StackIter: public std::iterator<
	std::input_iterator_tag,std::string,std::ptrdiff_t>
{
private:
	stack<T>& s;
public:
	StackIter() :s(stack<T>()){}
	StackIter(stack<T>& st) :s(st){}
	T operator*(){ return s.top(); }
	bool operator==(const StackIter& SI){ return s.empty(); }
	bool operator!=(const StackIter& SI){ return !s.empty(); }
	StackIter& operator++() { s.pop(); return *this; }
};
template<typename T>
class QueueIter : public std::iterator<
	std::input_iterator_tag, std::string, std::ptrdiff_t>
{
private:
	queue<T>& q;
public:
	QueueIter() :q(queue<T>()){}
	QueueIter(queue<T>& qt) :q(qt){}
	T operator*(){ return q.front(); }
	bool operator==(const QueueIter& QI){ return q.empty(); }
	bool operator!=(const QueueIter& QI){ return !q.empty(); }
	QueueIter& operator++() { q.pop(); return *this; }
};

int main()
{
	stack<int, vector<double>> err;
	ifstream in("Stacks.cpp");
	Stack textLines;
	Queue directiveLines;
	string line;
	while (getline(in, line))
	{
		if (line[0] == '#')
			directiveLines.push(line + "\n");
		else
			textLines.push(line + "\n");
	}
	in.close();
	while (!textLines.empty())
	{
		cout << textLines.top();
		textLines.pop();
	}
	while (!directiveLines.empty())
	{
		cout << directiveLines.front();
		directiveLines.pop();
	}
	cin.get();

	ifstream fs("Stacks.cpp");
	while (getline(in, line))
	{
		if (line[0] == '#')
			directiveLines.push(line + "\n");
		else
			textLines.push(line + "\n");
	}
	copy(StackIter<string>(textLines), StackIter<string>(), ostream_iterator<string>(cout, "\n"));
	copy(QueueIter<string>(directiveLines), QueueIter<string>(), ostream_iterator<string>(cout, "\n"));
	cin.get();
	return 0;
}
