#include "dataProcedures.h"
#include "newTypes.h"

const char * fileName = "data.txt";
const char * newFileName = "chaindata.txt";

void sortByChain()
{
	cout << "\n *Сортування файла за допомогою списку*\n\n";
	ifstream inFile(fileName);
	// Порожній список містить лише заголовну ланку
	chainNode * chain = new chainNode();
	while (!inFile.eof())
	{
		dataEntry E; inFile >> E;
		insertNode(chain, E);
	}
	inFile.close();
	// Друкуємо результати
	printChain(chain->link, cout);
	ofstream result(newFileName);
	printChain(chain->link, result);
	result.close();
	deleteChain(chain);
	return;
}