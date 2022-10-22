#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::ostream;
using std::vector;

// велике число зображено послідовністю цифр
struct largeNumber
{
	static const int length = 302;
	char digits[length];           // масив цифр
	int last;                      // номер останньої цифри
};
// процедура подвоєння великого числа
void multByTwo(largeNumber& x);
// процедура виведення великого числа
void print(const largeNumber& x);
// програма піднесення 2 до степеня n, 1<=n<=1000
void powerLast();


// спискова структура для зображення великого числа
struct NumNode
{
	unsigned short num;
	NumNode* link;
	NumNode(unsigned short x, NumNode* p = nullptr) :num(x), link(p) {}
};
// процедура звільнення динамічної пам'яті
void eraseList(NumNode*& x);
// процедура подвоєння великого числа
void multByTwo(NumNode* x);
// процедура виведення великого числа
void print(const NumNode* x);
// програма піднесення 2 до степеня n
void powerList();



// клас для зображення великого числа
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
