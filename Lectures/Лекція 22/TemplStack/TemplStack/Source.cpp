#include <iostream>
#include "Header.h"

std::ostream& operator<<(std::ostream& os, const Time& t)
{
	os << t.hour << ':';
	if (t.min < 10) os << '0';
	os << t.min;
	return os;
}
int main()
{
	using std::cout;
	Stack<int> si;
	si.push(5); si.push(7); si.push(13);
	cout << '\t' << si.pop() << '\t' << si.pop() << '\t' << si.pop() << '\n';
	Stack<double> sd;
	sd.push(5.1); sd.push(7.5); sd.push(13.9);
	cout << '\t' << sd.pop() << '\t' << sd.pop() << '\t' << sd.pop() << '\n';
	Stack<Time> st;
	st.push(Time(5, 10)); st.push(Time(7, 15)); st.push(Time(13, 9));
	cout << '\t' << st.pop() << '\t' << st.pop() << '\t' << st.pop() << '\n';
	system("pause");
	st.push(Time(1, 20));
	Time lect = st.pop();
	cout << " Before: " << lect << '\n';
	st.push(Time(3, 45));
	cout << "After: " << lect << '\n';
	system("pause");
	if (!st.isEmpty()) st.pop() = Time(0, 20);
	system("pause");
	si.push(5); int k = si.pop(); si.push(10); cout << " k = " << k << '\n';
	system("pause");
	return 0;
}