#include <iostream>
#include <string>
#include "list.h"
using namespace std;

int main()
{
    List<string> lst;
    lst.isEmpty();
    lst.getLength();

    lst.push_front("PMO-11");
    lst.push_front("Olia");
    lst.push_front("Kravets");
    lst.print();
    lst.getLength();

    lst.Front();
    lst.pop_front();
    lst.print();
    lst.getLength();

    lst.push_back("Applied");
    lst.push_back("Mathematics");
    lst.push_back("and");
    lst.push_back("Informatics");
    lst.print();
    lst.getLength();

    lst.Back();
    lst.pop_back();
    lst.pop_back();
    lst.Back();
    lst.print();
    lst.getLength();

    cout << "\n";
    system("pause");
    return 0;
}

