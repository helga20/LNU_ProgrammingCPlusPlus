#include "stepProcedures.h"

void average()
{
	cout << "\n *������ ����������� ����������� ������ ����� � ����������� ���������*\n\n"
		<<"������ ����������� �����, �� ���������� �����:\n";
	unsigned k = 0;
	double s = 0.0;
	double a; cin >> a;
	while (a != 0.0)
	{
		s += a;
		++k;
		cin >> a;
	}
	if (k == 0) cout << "����������� ���������� �����\n";
	else cout << "������ ����������� = " << s / k << '\n';
	return;
}