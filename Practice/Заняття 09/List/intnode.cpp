#include "intnode.h"
#include <fstream>

void printList(const IntList& list)
{
	IntNode* curr = list.head;
	while (curr != nullptr)
	{
		cout << curr->value << "  ";
		curr = curr->nextNode;
	}
	cout << "\n";
}

void readListFromFile(const string& fileName, IntList& list)
{
	ifstream iFile(fileName);

	int elem;
	iFile >> elem;
	list.head = new IntNode(elem);
	IntNode* curr = list.head;

	while (!iFile.eof())
	{
		iFile >> elem;
		curr->nextNode = new IntNode(elem);
		curr = curr->nextNode;
	}

	iFile.close();
}

void addFirst(int val, IntList& list)
{
	IntNode* firstNode = new IntNode(val);
	firstNode->nextNode = list.head;
	list.head = firstNode;
}

void removeFirst(IntList& list)
{
	IntNode* curr = list.head;
	list.head = curr->nextNode;
	curr->nextNode = nullptr;
	delete curr;
}

void insertAt(int val, int index, IntList& list)
{
	IntNode* curr = list.head;
	int count = 1;
	while (count != index - 1)
	{
		curr = curr->nextNode;
		++count;
	}

	IntNode* indexNode = new IntNode(val);
	indexNode->nextNode = curr->nextNode;

	curr->nextNode = indexNode;
}

void removeAt(int index, IntList& list)
{
	IntNode* curr = list.head;
	int count = 1;
	while (count != index - 1)
	{
		curr = curr->nextNode;
		++count;
	}
	IntNode* temp = curr->nextNode;
	curr->nextNode = temp->nextNode;

	temp->nextNode = nullptr;
	delete temp;
}