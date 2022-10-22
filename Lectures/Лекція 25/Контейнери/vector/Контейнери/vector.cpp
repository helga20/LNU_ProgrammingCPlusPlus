/*#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

void printOn(vector<int>& Vector);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int size = 11;

	vector<int> Vector; 
	for (int i = 0; i < size; i++) Vector.push_back(i);
	cout << "������: \n";
	printOn(Vector);
	cout << "\n";
	system("pause");

	// ������� 2
	Vector.erase(Vector.begin() + 2);
	cout << "ϳ��� ��������� ����� 2: \n";
	printOn(Vector);
	cout << "\n";
	system("pause");

	// ������� ������� [4,9)
	Vector.erase(Vector.begin() + 3, Vector.begin() + 8);
	cout << "ϳ��� ��������� �������� [4,9): \n";
	printOn(Vector);
	cout << "\n";
	system("pause");

	// ������� ������������ ����� �������
	int vectorMaxSize = Vector.max_size();
	cout << "������������ ����� �������: " << vectorMaxSize << endl;

	// ������� ����� �������
	int vectorSize = Vector.size();
	cout << "����� �������: " << vectorSize << endl;

	// ������� ������ �������
	int vectorCapacity = Vector.size();
	cout << "������ �������: " << vectorCapacity << endl;
	cout << "\n";
	system("pause");

	//  ����� � ������� [2,5) ��� �����
	Vector.insert(Vector.begin() + 2, 3, 8);
	cout << "ϳ��� ������� ����� ����� � ������� [2,5): \n";
	printOn(Vector);
	cout << "\n";
	system("pause");

	// ������� ������� �������
	cout << "ϳ��� ��������� ���������� ��������: \n";
	Vector.pop_back();
	printOn(Vector);
	cout << "\n";
	system("pause");

	// ������� ����� ������ � ����� � ����� ���� ����������� ������� 
	vector<int> newVector(Vector.begin(), Vector.end());
	cout << "����� ������: \n";
	printOn(newVector);
	cout << "\n";
	system("pause");

	// �������� ����� ������ ����������
	newVector.insert(newVector.begin(), newVector.size(), 1);
	cout << "ϳ��� ������� ��������: \n";
	printOn(newVector);
	cout << "\n";
	system("pause");

	// ������� � ������ newVector ���� ������� 
	newVector.assign(Vector.begin(), Vector.end());
	cout << "ϳ��� ��������� ����� �������: \n";
	printOn(newVector);
	cout << "\n";
	system("pause");

	// ������� ������ newVector
	newVector.clear();
	cout << "������ ������� ������� ������: \n";
	printOn(newVector);
	cout << "\n";
	system("pause");

	// ������� �������
	Vector.clear();
	for (int i = 0; i < size; i++)
	{
		Vector.push_back(i);
		newVector.push_back(i + 1);
	}
	cout << "������: ";	  printOn(Vector);
	cout << "����� ������: ";	printOn(newVector);
	if (Vector == newVector) cout << "������ == ����� ������\n";
	if (Vector > newVector) cout << "������ > ����� ������\n";
	if (Vector >= newVector) cout << "������ >= ����� ������\n";
	if (Vector < newVector) cout << "������ < ����� ������\n";
	if (Vector <= newVector) cout << "������ <= ����� ������\n";

	cout << "\n";
	system("pause");
	return 0;
}
void printOn(vector<int>& Vector)
{
	if (Vector.empty())
	{
		cout << "������ �������\n";
		return;
	}
	vector<int>::iterator iter;
	for (iter = Vector.begin(); iter != Vector.end(); iter++)
		cout << " " << *iter;
		cout << "\n";
}*/