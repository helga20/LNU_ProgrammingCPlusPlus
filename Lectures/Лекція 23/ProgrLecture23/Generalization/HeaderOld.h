#pragma once

//"Наївна" спроба узагальнити тип даних
typedef int ValueType;

void printMas(ValueType[], int);
int findValInMas(ValueType, ValueType[], int);

struct Node
{
	ValueType data;
	Node* next;
	Node(ValueType x, Node* ptr = nullptr) :data(x), next(ptr){}
};
void printList(Node*);
Node* buildList(ValueType[], int);
Node* findValInList(ValueType, Node*);