#include "dataProcedures.h"
#include "newTypes.h"

const char * inFileName = "data.txt";
const char * outFileName = "treedata.txt";

void sortByTree()
{
	cout << "\n *���������� ����� �� ��������� ������ ������*\n\n";
	ifstream inFile(inFileName);
	treeNode * tree = nullptr;
	while (!inFile.eof())
	{
		dataEntry E; inFile >> E;
		insertTreeNode(tree, E);
	}
	inFile.close();
	// ������� ����������
	printTree(tree, cout);   // �� �����
	ofstream result(outFileName);
	printTree(tree, result); // � �� �����
	result.close();
	// ������� �������� ���'���
	deleteTree(tree);
	return;
}