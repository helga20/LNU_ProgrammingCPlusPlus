#include "dataProcedures.h"
#include "newTypes.h"

const char * fileName = "data.txt";
const char * newFileName = "chaindata.txt";

void sortByChain()
{
	cout << "\n *���������� ����� �� ��������� ������*\n\n";
	ifstream inFile(fileName);
	// ������� ������ ������ ���� ��������� �����
	chainNode * chain = new chainNode();
	while (!inFile.eof())
	{
		dataEntry E; inFile >> E;
		insertNode(chain, E);
	}
	inFile.close();
	// ������� ����������
	printChain(chain->link, cout);
	ofstream result(newFileName);
	printChain(chain->link, result);
	result.close();
	deleteChain(chain);
	return;
}