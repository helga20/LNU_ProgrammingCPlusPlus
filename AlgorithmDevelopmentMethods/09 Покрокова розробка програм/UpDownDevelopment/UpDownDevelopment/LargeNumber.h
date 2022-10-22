#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::ostream;
using std::vector;

// ������ ����� ��������� ����������� ����
struct largeNumber
{
	static const int length = 302;
	char digits[length];           // ����� ����
	int last;                      // ����� �������� �����
};
// ��������� �������� �������� �����
void multByTwo(largeNumber& x);
// ��������� ��������� �������� �����
void print(const largeNumber& x);
// �������� ��������� 2 �� ������� n, 1<=n<=1000
void powerLast();


// �������� ��������� ��� ���������� �������� �����
struct NumNode
{
	unsigned short num;
	NumNode* link;
	NumNode(unsigned short x, NumNode* p = nullptr) :num(x), link(p) {}
};
// ��������� ��������� �������� ���'��
void eraseList(NumNode*& x);
// ��������� �������� �������� �����
void multByTwo(NumNode* x);
// ��������� ��������� �������� �����
void print(const NumNode* x);
// �������� ��������� 2 �� ������� n
void powerList();



// ���� ��� ���������� �������� �����
class LargePositiveInteger
{
private:
	vector<char> digits;
public:
	LargePositiveInteger() { digits.push_back(0); }
	LargePositiveInteger& operator=(unsigned);
	LargePositiveInteger& multByTwo();
	LargePositiveInteger& operator*=(unsigned);
	friend ostream& operator<<(ostream&, const LargePositiveInteger&);
};

void powerLastest();
