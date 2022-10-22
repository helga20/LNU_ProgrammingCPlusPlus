#include "time.h"

int main()
{
	Time A;
	Time B(5,40);
	Time C(2,55);
	cout << " --- Creation\n";
	cout << "A = "; A.Show(cout);
	cout << "B = "; B.Show(cout);
	cout << "C = "; C.Show(cout); cout << '\n';
	cout << " --- Adding & printing by method\n";
	A = B.Sum(C);
	cout << "A = "; A.Show(cout);
	cout << "B = "; B.Show(cout);
	cout << "C = "; C.Show(cout); cout << '\n';
	cout << " --- Adding & printing by operators\n";
	A = B + C;
	cout << B << " + " << C << " = " << A << "\n\n";
	cout << " --- Multiplying witn number\n";
	Time D(A);
	B = A * 0.5;
	C = 0.5 * D;
	cout << "B = " << B << "   C = " << C << '\n';
	cout << " --- Type convertion\n";
	int t = B;
	A = Time(t*2);
	C = int(A) + 2012;	// A + 2012 не працює через двозначність
	cout << "t = " << t << "\nA = " << A << "   C = " << C << '\n';
	cout << " --- Object modification\n";
	Time T;
	T.AddMin(80).Show(cout);
	T.AddMin(20).AddHr(1).AddMin(20).Show(cout);
	cout << " --- Deeling with array\n";
	Time Tour[7] = { Time(3, 40), Time(1, 30), Time(90), Time(5, 0), Time(4, 25) };
	Tour[6] = 120;
	for (int i = 0; i < 7; ++i) cout << '\t' << Tour[i];
	cout << '\n';
	int indOfMax = 0;
	for (int i = 1; i < 7; ++i)
		if (Tour[i]>Tour[indOfMax]) indOfMax = i;
	cout << "Max Tour[" << indOfMax << "] = " << Tour[indOfMax] << '\n';
	Time Total = Tour[0];
	for (int i = 1; i < 7; ++i) Total = Total + Tour[i];
	int total = Total;
	cout << "Duration = " << total << " minutes or ";
	Total.Show(cout);
	system("pause");
	return 0;
}