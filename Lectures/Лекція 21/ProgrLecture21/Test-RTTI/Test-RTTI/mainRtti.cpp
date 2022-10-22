#include <iostream>
using namespace std;
//#include <cstdlib>
#include <ctime>
//#include <typeinfo>

class Grand
{
private:
	int hold;
public:
	Grand(int h=0): hold(h) {}
	virtual ~Grand() {}
	virtual void speak() const { cout<<"I am a grand class!\n"; }
	virtual int value() const { return hold; }
};
class Superb : public Grand
{
public:
	Superb(int h=0): Grand(h) {}
	virtual void speak() const { cout<<"I am a superb class!!\n"; }
	virtual void say() const { cout<<"I hold the grand value of "<<value()<<" !\n"; }
};
class Magnificent : public Superb
{
private:
	char ch;
public:
	Magnificent(int h=0, char c='A'): Superb(h), ch(c) {}
	virtual void speak() const { cout<<"I am a magnificent class!!!\n"; }
	virtual void say() const { cout<<"I hold the caracter '"<<ch
		<<"' and the integer "<<value()<<" !\n"; }
};

Grand* GetOne();

int main()
{
	srand(time(0));
	Grand* G;
	Superb* S;
	for (int i=0; i<7; i++)
	{
		G = GetOne();
		cout<<"\n--- MAIN : now processing type ["<<typeid(*G).name()<<"].\n";
		G->speak();
		if (S=dynamic_cast<Superb*>(G)) S->say();
		if (typeid(Magnificent)==typeid(*G))
			cout<<"--- MAIN : Yes, you're really magnificent.\n";
		delete G;
	}
	system("pause");
	return 0;
}
Grand* GetOne()
{
	Grand* p;
	switch (rand() % 3)
	{
		case 0: p = new Grand(rand() % 100); break;
		case 1: p = new Superb(rand() % 100); break;
		case 2: p = new Magnificent(rand() % 100, 'A' + rand() % 26); break;
		default: p = nullptr;
	}
	return p;
}
/*

--- MAIN : now processing type [class Grand].
I am a grand class!

--- MAIN : now processing type [class Superb].
I am a superb class!!
I hold the grand value of 88 !

--- MAIN : now processing type [class Magnificent].
I am a magnificent class!!!
I hold the caracter 'K' and the integer 44 !
--- MAIN : Yes, you're really magnificent.

--- MAIN : now processing type [class Grand].
I am a grand class!

--- MAIN : now processing type [class Superb].
I am a superb class!!
I hold the grand value of 28 !

--- MAIN : now processing type [class Grand].
I am a grand class!

--- MAIN : now processing type [class Magnificent].
I am a magnificent class!!!
I hold the caracter 'P' and the integer 62 !
--- MAIN : Yes, you're really magnificent.
*/