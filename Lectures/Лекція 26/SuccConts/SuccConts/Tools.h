#pragma once
#include <iostream>
using std::cout;
using std::cin;

// ������ ������� ��� ��������� ����� ���������� ��� ��������
// ��������� (� ��� ������� - ����������)
template<typename Container>
void print(Container& c, char* title = "")
{
	cout << title << ':' << endl;
	if (c.empty())
	{
		cout << "(empty)" << endl;
		return;
	}
	// typename - ����'������ ������� ����������� ��� ��,
	// �� �� ������ Container::iterator �������� ���� ���,
	// � �� ��������� ���� �����
	typename Container::iterator it;
	for (it = c.begin(); it != c.end(); ++it)
		cout << *it << " ";
	cout << endl;
	cout << "size() " << c.size() << " max_size() " << c.max_size()
		<< " front() " << c.front() << " back() " << c.back() << endl;
	cin.get();
}

int test_Noisy();
int use_Inserters();
int use_algos();
int use_basicOps();
int compare();