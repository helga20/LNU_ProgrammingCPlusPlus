#include <iostream>
#include "group.h"
#include "prof.h"
#include "student.h"
using namespace std;

int main()
{
	Group G1;
	Group G2("PMO-11");
	Group G3("PMA-12", new Prof("Yaroshko", "Serhii"), 2);

	Student S1("Igor", "Petrovych", 85.5);
	Student S2("Oksana", "Yaroshko", 76.1);
	Prof P3("Sviatoslav", "Tarasiuk");

	G1.readGroupFromFile("info.txt");
	G1.addMember(&S1);
	G1.addMember(&P3);

	G2.addMember(new Prof("Bohdan","Makarenko"));
	G2.addMember(&S2);
	G2.setLeader(&P3);

	G3.addMember(new Student("TestName", "TestSurname", 10));
	G3.addMember(new Student("Anna", "Koval", 76.5));
	G3.addMember(new Student("Nazar", "Ivanenko", 56.6));
	G3.addMember(&P3);

	cout << "All groups\n\n";
	G1.printGroupInfo();
	cout << "\n----------------------------------\n";
	G2.printGroupInfo();
	cout << "\n----------------------------------\n";
	G3.printGroupInfo();
	cout << "\n----------------------------------\n";

	G1.writeGroupToFile("test2.txt");
	cout << "Total mark: " << G1.totalMark() << "\n";
	cout << "Average mark: " << G1.averageTotalMark() << "\n";
	cout << "Best member\n";
	try
	{
		G1.findBestMember()->printPersonInfo();
	}
	catch (const char* msg)
	{
		cout << "ERROR. " << msg << "\n";
	}
	cout << "\n----------------------------------\n";

	G3.deleteMember("TestSurname");
	G3.printGroupInfo();
	cout << "\n----------------------------------\n";

	cout << "\nAll leaders\n";
	G1.getLeader()->printPersonInfo(); cout << "\n";
	G2.getLeader()->printPersonInfo(); cout << "\n";
	G3.getLeader()->printPersonInfo();
	cout << "\n----------------------------------\n";

	system("pause");
	return 0;
}