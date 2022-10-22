#include <iostream>
#include <queue>
#include <string>
using namespace std;

class ToDoItem
{
	char primary;
	int secondary;
	string item;
public:
	ToDoItem(string td, char pri='A', int sec=1)
		: item(td), primary(pri), secondary(sec) {}
	friend bool operator<(const ToDoItem& x, const ToDoItem& y)
	{
		return x.primary>y.primary || 
			x.primary==y.primary && x.secondary>y.secondary;
	}
	friend ostream& operator<<(ostream& os, const ToDoItem& td)
	{
		return os<<td.primary<<td.secondary<<": "<<td.item;
	}
};
template <typename T>
void writeQueue(T& pq)
{
	while (!pq.empty())
	{
		cout << pq.top() << '\n';
		pq.pop();
	}
	cout << '\n';
}

int main()
{
	priority_queue<ToDoItem> toDoList;
	toDoList.push(ToDoItem("Empty trush",'C',4));
	toDoList.push(ToDoItem("Feed dog",'A',2));
	toDoList.push(ToDoItem("Feed caw", 'A', 2));
	toDoList.push(ToDoItem("Feed bird", 'B', 7));
	toDoList.push(ToDoItem("Mow lawn",'C',3));
	toDoList.push(ToDoItem("Water lawn",'A',1));
	toDoList.push(ToDoItem("Feed cat", 'B',1));
	toDoList.push(ToDoItem("Feed student",'A',2));
	toDoList.push(ToDoItem("Sleep child",'A',2));
	toDoList.push(ToDoItem("Empty gays",'D',16));
	toDoList.push(ToDoItem("Feed horse", 'A', 2));
	writeQueue(toDoList);
	return 0;
}
/*
A1: Water lawn
A2: Feed dog
A2: Feed caw
A2: Feed student
A2: Feed horse
A2: Sleep child
B1: Feed cat
B7: Feed bird
C3: Mow lawn
C4: Empty trush
D16: Empty gays
*/