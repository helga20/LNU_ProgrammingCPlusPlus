#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include "noisy.h"
using namespace std;

// Налаштування лічильників для ведення статистики
// створення/знищення екземплярів Noisy
long Noisy::create = 0, Noisy::assign = 0,
	Noisy::copy = 0, Noisy::destroy = 0;
NoisyReport NoisyReport::nr;

int main()
{
	list<Noisy> L;
	ostream_iterator<Noisy>out(cout," ");
	// Наповнення списку сімома об'єктами
	generate_n(back_inserter(L),7,NoisyGen());
	// Друк початкового списку
	cout<<"\n Printing the list:\n";
	copy(L.begin(),L.end(),out);
	// Обертання списку і друк
	cout<<"\n Reversing the list:\n";
	L.reverse();
	copy(L.begin(),L.end(),out);
	// Впорядкування і друк
	cout<<"\n Sortinging the list:\n";
	L.sort();
	copy(L.begin(),L.end(),out);
	// Обмін двох елементів списку зовнішніми засобами
	cout<<"\n Swaping two elements:\n";
	list<Noisy>::iterator it1, it2;
	it1 = it2 = L.begin();
	++it2;
	swap(*it1,*it2);
	copy(L.begin(),L.end(),out);
	// Обеотання списку зовнішніми засобами
	cout<<"\n Using genering reverse:\n";
	reverse(L.begin(),L.end());
	copy(L.begin(),L.end(),out);
	cin.get(); cout << endl;

	// спеціальні операції зі списками	
	list<Noisy> A;
	generate_n(back_inserter(A), 5, NoisyGen());
	list<Noisy> B;
	generate_n(back_inserter(B), 7, NoisyGen());
	cout << "\nTwo lists were generated:\n";
	cout << " A: "; copy(A.begin(), A.end(), out); cout << endl;
	cout << " B: "; copy(B.begin(), B.end(), out); cout << endl;
	cin.get();
	// врізка списку
	cout << "\nLet's splice B into A.begin()+3\n";
	list<Noisy>::iterator i = A.begin();
	++i; ++i; ++i;
	A.splice(i, B); 
	cout << "\n   result\n";
	cout << " A: "; copy(A.begin(), A.end(), out); cout << endl;
	cout << " B: "; copy(B.begin(), B.end(), out); cout << endl;
	cin.get();
	// врізка підсписку, вставляння елемента
	cout << "\nLet's splice [A; A+2) into B, then push into front of B:\n";
	B.splice(B.begin(), A, A.begin(), ++(++(A.begin()))); cout << endl;
	B.push_front(Noisy()); cout << endl;
	cout << "\n   result\n";
	cout << " A: "; copy(A.begin(), A.end(), out); cout << endl;
	cout << " B: "; copy(B.begin(), B.end(), out); cout << endl;
	cin.get();
	// впорядкування
	cout << "\n Sort the lists!\n";
	A.sort();
	B.sort();
	cout << "\n   result\n";
	cout << " A: "; copy(A.begin(), A.end(), out); cout << endl;
	cout << " B: "; copy(B.begin(), B.end(), out); cout << endl;
	cin.get();
	// впорядковане злиття
	cout << "\n A.merge(B)\n";
	A.merge(B);
	cout << "\n   result\n";
	cout << " A: "; copy(A.begin(), A.end(), out); cout << endl;
	cout << " B: "; copy(B.begin(), B.end(), out); cout << endl;
	cin.get();
	cout << "\n Cleanup\n";
	return 0;
}
