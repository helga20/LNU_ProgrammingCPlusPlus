#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
using std::cout;
int main()
{
	srand(time(0));
	Queue A;
	A.show();
	cout<<'\n';
	Customer B;
	for(int i=1; i<=12; i++)
	{
		B.set(rand()%10 + i * 10);
		if (!A.enqueue(B)) cout<<"Full queue - Customer: "<<B<<" go away!\n";
	}
	A.show();
	return 0;
}
