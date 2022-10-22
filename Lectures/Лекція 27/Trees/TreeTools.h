#pragma once

struct treeNode;
typedef treeNode* Tree_t;

struct treeNode
{
	int val;
	Tree_t left;
	Tree_t right;
	treeNode() : val(0), left(nullptr), right(nullptr) {}
	treeNode(int x, Tree_t l, Tree_t r) : val(x), left(l), right(r) {}
};

// вставляє одне значення в дерево пошуку
void searchIncl(Tree_t&, int);
// завантажує послідовність цілих в дерево пошуку
Tree_t buildTree();
// друкує дерево з відображенням структури
void writeTree(const Tree_t, unsigned);
// друкує дерево як послідовність
void writeTree(const Tree_t);

// друк - лівосторонній обхід за рівнями
void printByLevel(const Tree_t);
void printByLevelInLines(const Tree_t Tree);
// друк - нерекурсивний обхід
void printPrefix(const Tree_t);
void printInfix(Tree_t Tree);

// вилучає все дерево
void removeTree(Tree_t& Tree);
// вилучає один елемент дерева пошуку
bool withdrawRec(Tree_t& tree, int x);