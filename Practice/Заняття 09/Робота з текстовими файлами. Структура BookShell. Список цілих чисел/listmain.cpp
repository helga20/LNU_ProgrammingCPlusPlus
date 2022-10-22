#include <iostream>
#include "intnode.h"
using namespace std;

int main()
{
	IntNode test(15);
	IntNode test2(25);
	test.nextNode = &test2;
	test2.nextNode = new IntNode(17, new IntNode(6));

	cout << "Int List\n";
	cout << test.value << "  "; // 15
	cout << test.nextNode->value << "  "; // 25
	cout << test.nextNode->nextNode->value << "  "; // 17
	cout << test.nextNode->nextNode->nextNode->value << "  "; // 6
	cout << "\n";

	cout << "Int List While\n";
	IntNode* curr = &test;
	while (curr != nullptr)
	{
		cout << curr->value << "  ";
		curr = curr->nextNode;
	}
	cout << "\n";

	IntList myList(&test);
	cout << "\nList: ";
	printList(myList);

	IntList fileList;
	readListFromFile("list.txt", fileList);
	cout << "\nFile list: ";
	printList(fileList);
	
	addFirst(15, fileList);
	cout << "\nFile list: ";
	printList(fileList);
	addFirst(27, fileList);
	cout << "File list: ";
	printList(fileList);

	removeFirst(fileList);
	cout << "\nFile list: ";
	printList(fileList);
	removeFirst(fileList);
	cout << "File list: ";
	printList(fileList);
	cout << "\n";

	insertAt(11, 3, fileList);
	cout << "File list: ";
	printList(fileList);
	insertAt(99, 6, fileList);
	cout << "File list: ";
	printList(fileList);
	cout << "\n";

	removeAt(6, fileList);
	cout << "File list: ";
	printList(fileList);
	removeAt(3, fileList);
	cout << "File list: ";
	printList(fileList);
	cout << "\n";

	system("pause");
	return 0;
}