#include <iostream>
using std::cout;
using std::cin;
#include "studMI.h"

void set(Student& s, int n);
const int pupils = 3;
const int quizzes = 5;

int main()
{
	Student ada[pupils]={quizzes,quizzes,quizzes};
	int i;
	for (i=0; i<pupils; i++) set(ada[i],quizzes);
	for (i=0; i<pupils; i++)
		cout<<'\n'<<ada[i]<<" average = "<<ada[i].average()<<'\n';
	cin.get();
	Student* S = new Student(2);
	(*S)[0] = 5; (*S)[1] = 4;
	cout << *S << '\n';
	delete S;
	cout << "Bye!\n";
	system("pause");
	return 0;
}

void set(Student& s, int n)
{
	cout<<"Please enter the student's name: ";
	cin >> s;
	cout<<"Please enter "<<n<<" quiz scores: ";
	for (int i=0; i<n; i++) cin>>s[i];
	while (cin.get() !='\n') continue;
}