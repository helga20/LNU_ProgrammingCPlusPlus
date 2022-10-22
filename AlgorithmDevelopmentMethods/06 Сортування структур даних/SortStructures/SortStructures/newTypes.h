#ifndef _TYPES_GUARD_
#define _TYPES_GUARD_

#include <string>
#include <fstream>

using std::string;
using std::ifstream;
using std::ofstream;

struct dataEntry
{
	int key;
	string value;  // для значення можна вказати довільний тип
};
// Для зручності роботи з даними перевантажимо оператори введення-виведення
std::istream& operator>>(std::istream& is, dataEntry& E);
std::ostream& operator<<(std::ostream& os, const dataEntry& E);

struct chainNode
{
	chainNode * link;
	dataEntry elem;
	chainNode(): link(0), elem() {}
	chainNode(const dataEntry& E, chainNode* L = 0): link(L), elem(E) {}
};

void printChain(chainNode* head, std::ostream& os);
void insertNode(chainNode* head, const dataEntry& E);
void deleteChain(chainNode*& head);

struct treeNode
{
	treeNode * left;
	treeNode * right;
	dataEntry elem;
	treeNode(): left(0), right(0), elem() {}
	treeNode(const dataEntry& E, treeNode* L = 0, treeNode* R = 0): left(L), right(R), elem(E) {}
};

void printTree(treeNode* root, std::ostream& os);
void insertTreeNode(treeNode*& root, const dataEntry& E);
void deleteTree(treeNode*& root);

#endif