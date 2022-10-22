#include "dataProcedures.h"
#include "newTypes.h"

const char * inFileName = "data.txt";
const char * outFileName = "treedata.txt";

void sortByTree()
{
	cout << "\n *Сортування файла за допомогою дерева пошуку*\n\n";
	ifstream inFile(inFileName);
	treeNode * tree = nullptr;
	while (!inFile.eof())
	{
		dataEntry E; inFile >> E;
		insertTreeNode(tree, E);
	}
	inFile.close();
	// Друкуємо результати
	printTree(tree, cout);   // На екран
	ofstream result(outFileName);
	printTree(tree, result); // і до файла
	result.close();
	// Очищаємо динамічну пам'ять
	deleteTree(tree);
	return;
}