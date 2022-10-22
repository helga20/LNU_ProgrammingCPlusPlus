//������� �������
#include <iostream>
#include <vector>
using namespace std;
void print(vector<int>& array);
int main()
{
	const int SIZE = 10;
	vector<int> array; // ������� ������
	// ���������� ������ �� ��������� �������-����� push_back()

	for (int i = 0; i < SIZE; i++) array.push_back(i);
	// �������� ������ �� �����
	printf("�������� ������\n");
	print(array);
	// ��������� 5-� ������� �������

	array.erase(array.begin() + 4);
	printf("ϳ��� ��������� ����� 4\n");
	print(array);
	// ��������� ������� [6,9)
	array.erase(array.begin() + 5, array.begin() + 8);
	printf("ϳ��� ��������� ����� 6, 7 � 8\n");
	print(array);
	// �������� �� ������� �������������� ����� �������
	int arrayMaxSize = array.max_size();
	printf("������������ ����� ������� = %d\n", arrayMaxSize);

	// �������� �� ������� ����� �������
	int arraySize = array.size();
	printf("����� ������� = %d\n", arraySize);
	// �������� �� ������� ������ �������
	int arrayCapacity = array.size();
	printf("������ ������� = %d\n", arrayCapacity);
	// ���������� � ������� [1,5) ������ �'����� � �������� ������ �� �������
	array.insert(array.begin() + 1, 4, 5);
	printf("ϳ��� ������� �������� �'����� � ������� [1,5) \n");
	print(array);
	// ��������� ������� �������
	printf("ϳ��� ��������� ���������� ��������\n");
	array.pop_back();
	print(array);
	// ����������� ����� ������. ������� � ����� ���� ������� array
	vector<int> newArray(array.begin(), array.end());
	printf("������ newArray\n");
	print(newArray);
	// ���������� ������ newArray ������
	newArray.insert(newArray.begin(), newArray.size(), 7);
	printf("ϳ��� ������� ����\n");
	print(newArray);
	// �������� � ������ newArray ���� ������� newArray
	newArray.assign(array.begin(), array.end());
	printf("ϳ��� ��������� ������� array\n");
	print(newArray);
	// ������� ������ newArray
	newArray.clear();
	printf("������ ������� ������� ������\n");
	print(newArray);
	// ��������� �������
	array.clear();
	for (i = 0; i < SIZE; i++)
	{
		array.push_back(i);
		newArray.push_back(i + 1);
	}
	printf("������ array: ");
	print(array);
	printf("������ newArray: ");
	print(newArray);
	if (array == newArray) printf("array == newArray\n");
	if (array > newArray) printf("array > newArray\n");
	if (array >= newArray) printf("array >= newArray\n");
	if (array < newArray) printf("array < newArray\n");
	if (array <= newArray) printf("array <= newArray\n");
	return 0;
}
void print(vector<int>& array)
{
	if (array.empty())
	{
		printf("%s \n", "������ �������");
		return;
	}

	vector<int>::iterator iter;
	for (iter = array.begin(); iter != array.end(); iter++)
		printf("%d ", *iter);
	printf("\n");