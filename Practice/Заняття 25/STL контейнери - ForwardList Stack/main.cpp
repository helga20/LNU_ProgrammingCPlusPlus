#include <iostream>
#include <forward_list>
#include <stack>
#include <fstream>
#include "functions.h"
#include "apple.h"
#include "peach.h"
using namespace std;

int main()
{
	stack<Fruit*> fruitsBasket;
	ifstream fruitsFile("fruits.txt");
	while (!fruitsFile.eof())
	{
		char type; fruitsFile >> type;
		if (type == 'A')
		{
			Fruit* apple = new Apple();
			fruitsFile >> *apple;
			fruitsBasket.push(apple);
		}
		else
		{
			Fruit* peach = new Peach();
			fruitsFile >> *peach;
			fruitsBasket.push(peach);
		}
	}
	fruitsFile.close();

	// Task 1
	forward_list<Fruit*> applesBasket;
	forward_list<Fruit*> peachBasket;
	auto peachIt = peachBasket.before_begin();
	while (!fruitsBasket.empty())
	{
		if (fruitsBasket.top()->getType() == Apple::APPLE_TYPE)
		{
			applesBasket.push_front(fruitsBasket.top()->clone());
		}
		else
		{
			peachIt = peachBasket.insert_after(peachIt, fruitsBasket.top()->clone());
		}
		fruitsBasket.pop();
	}
	applesBasket.reverse();
	printFruitsBasket(applesBasket);
	cout << "----------------------------------\n\n";
	printFruitsBasket(peachBasket);
	cout << "----------------------------------\n\n";

	// Task 2
	forward_list<Fruit*> fruitsRow;
	auto rowIt = fruitsRow.before_begin();
	auto appleIt = applesBasket.begin();
	peachIt = peachBasket.begin();
	while (appleIt != applesBasket.end() && peachIt != peachBasket.end())
	{
		rowIt = fruitsRow.insert_after(rowIt, (*appleIt)->clone());
		rowIt = fruitsRow.insert_after(rowIt, (*peachIt)->clone());
		++appleIt;
		++peachIt;
	}

	if (appleIt != applesBasket.end())
	{
		while (appleIt != applesBasket.end())
		{
			rowIt = fruitsRow.insert_after(rowIt, (*appleIt)->clone());
			++appleIt;
		}
	}
	else if (peachIt != peachBasket.end())
	{
		while (peachIt != peachBasket.end())
		{
			rowIt = fruitsRow.insert_after(rowIt, (*peachIt)->clone());
			++peachIt;
		}
	}
	cout << "Fruits row\n";
	printFruitsBasket(fruitsRow);
	cout << "----------------------------------\n\n";


























	/*
	forward_list<int> myList_1;
	myList_1.push_front(10);
	myList_1.push_front(30);
	myList_1.push_front(80);
	myList_1.push_front(80);
	myList_1.push_front(20);
	myList_1.push_front(80);
	printListInRow<int>(myList_1);
	myList_1.reverse();
	printListInRow<int>(myList_1);
	myList_1.remove(80);
	printListInRow<int>(myList_1);
	myList_1.sort();
	printListInRow<int>(myList_1);
	
	cout << "\n";

	forward_list<int> myList_2;
	forward_list<int>::iterator listIt;
	listIt = myList_2.before_begin();
	listIt = myList_2.insert_after(listIt, 50);
	listIt = myList_2.insert_after(listIt, 50);
	listIt = myList_2.insert_after(listIt, 40);
	listIt = myList_2.insert_after(listIt, -10);
	listIt = myList_2.insert_after(listIt, 40);
	listIt = myList_2.insert_after(listIt, 70);
	listIt = myList_2.insert_after(listIt, 40);
	listIt = myList_2.insert_after(listIt, 70);
	myList_2.insert_after(listIt, 60);
	printListInRow<int>(myList_2);
	myList_2.sort();
	printListInRow<int>(myList_2);
	myList_2.unique();
	printListInRow<int>(myList_2);
	myList_2.remove(-10);
	printListInRow<int>(myList_2);
	cout << "\n";

	cout << "Before merge\n";
	cout << "MyList_1: "; printListInRow<int>(myList_1);
	cout << "MyList_2: "; printListInRow<int>(myList_2);
	myList_1.merge(myList_2);
	cout << "After merge\n";
	cout << "MyList_1: "; printListInRow<int>(myList_1);
	cout << "MyList_2: "; printListInRow<int>(myList_2);
	cout << "\n";

	stack<int> myStack_1;
	for (auto it = myList_1.cbegin(); it != myList_1.cend(); ++it)
		myStack_1.push(*it);
	cout << "Stack_1: "; printStackInRow(myStack_1);
	cout << "\n";
	
	stack<int> myStack_2;
	readStackFromFile(myStack_2, "data.txt");
	forward_list<int> evenList;
	forward_list<int> oddList;
	forward_list<int>::iterator oddIt = oddList.before_begin();
	cout << "Stack_2: ";
	while (!myStack_2.empty())
	{
		int topVal = myStack_2.top();
		cout << topVal << ' ';
		if (topVal % 2 == 0)
		{
			evenList.push_front(topVal);
		}
		else
		{
			oddIt = oddList.insert_after(oddIt, topVal);
		}
		myStack_2.pop();
	}
	cout << "\n";
	evenList.reverse();
	cout << "Even values: "; printListInRow<int>(evenList);
	cout << "Odd values:  "; printListInRow<int>(oddList);
	modifyList<int>(evenList, 2);
	modifyList<int>(oddList, 10);
	cout << "\nAfter modifications\n";
	cout << "Even values: "; printListInRow<int>(evenList);
	cout << "Odd values:  "; printListInRow<int>(oddList);
	cout << "\n";

	*/
	return 0;
}