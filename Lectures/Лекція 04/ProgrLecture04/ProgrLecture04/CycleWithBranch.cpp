#include <iostream>
using namespace std;

int main()
{
	/* ������ ������ ����� �����.
	   ������� �������� ���������� � ���.
	   (� ���� ���������� �����.)
	*/
	const int n = 10;
	cout << "Input " << n << " integers: ";
	int a;
	cin >> a; // �������� ������� ��������
	// ����� ����������: ������ - ���������
	int maxValue = a;
	int maxNum = 0;
	// �������� ����� �������
	for (int i = 1; i < n; ++i)
	{
		cin >> a;
		// �� �� ��������� �����?
		if (a > maxValue)
		{
			// �����'����� ��������!
			maxValue = a;
			maxNum = i;
		}
	}
	cout << "The maximal value is " << maxValue << endl;
	cout << "Sequence number of the value is " << maxNum << endl;
	system("pause");

	/* ������ ������ ����� �����.
	������ � ��� ��� ����� �� 15 ����� � ������ 7?
	*/
	cout << "Input " << n << " integers: ";
	int counter = 0; // ������ �������
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		// �� ������� ����� "���������"?
		if (a % 15 == 7) ++counter;
	}
	cout << "The quantity of 15k+7 numbers is " << counter << endl;
	system("pause");

	return 0;
}