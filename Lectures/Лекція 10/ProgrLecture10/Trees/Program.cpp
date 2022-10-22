#include <iostream>
#include "TreeTools.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	cout << " **** Deel with binary trees\n-----------------------\n\n";
	/*9 5 14 3 2 1 7 6 4 8 12 10 11 13 17 15 16 19 18 20 f*/
	Tree_t Tree = buildTree();
	cout << "See on your tree:\n";
	writeTree(Tree);
	cout << "\n\n";
	//writeTree(Tree, 0);
	printInfix(Tree);
	cout << "\n\n";
	system("pause");
	cout << "\n The tree by levels:\n";
	printByLevel(Tree);
	cout << "\n The same tree separated by levels:\n";
	printByLevelInLines(Tree);
	cout << "\n\n";
	system("pause");
	cout << "\n The tree printed unrecurcively:\n";
	printPrefix(Tree);
	cout << "\n\n";
	int x;
	do
	{
		writeTree(Tree, 0);
		cout << "Input a value to remove: ";
		cin >> x;
	} while (withdrawRec(Tree, x));
	removeTree(Tree);
	return 0;
}
