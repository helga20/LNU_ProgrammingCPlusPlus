#pragma once
#include <iostream>
using namespace std;

// одна ланка в списку
struct IntNode
{
	int value;
	IntNode* nextNode;

	IntNode() : value(0), nextNode(nullptr) {}
	IntNode(int val) : value(val), nextNode(nullptr) {}
	IntNode(int val, IntNode* next) : value(val), nextNode(next) {}
};

struct IntList
{
	IntNode* head;

	IntList() : head(nullptr) {}
	IntList(IntNode* node) : head(node) {}
};

void printList(const IntList& list);
void readListFromFile(const string& fileName, IntList& list);
void addFirst(int val, IntList& list);
void removeFirst(IntList& list);
void insertAt(int val, int index, IntList& list);
void removeAt(int index, IntList& list);