#pragma once
namespace ListTools
{
	struct Node;
	typedef Node* List_t;
	struct Node
	{
		int value;
		List_t link;
		Node(int x, List_t p = nullptr) :value(x), link(p) {}
	};

	// ��������� � ������ ����������� ����� � ���������� �������
	List_t readList();
	// ��������� � ������ ����������� ����� � ���������� �������
	List_t reverseReadList();
	// ����������, ��������� � ������ ����������� ����� � ���������� �������
	void recursiveReadList(List_t& L);
	// ��������� � ���������� ����������� ����� �����
	List_t readSortedList();
	List_t readSortedLst();
	// �������� �������� ������ �� �������
	void writeList(List_t L);
	// ������ � ������������ ������ ����� �����
	int delFirst(List_t& L);
	// ������ ���� ������
	void removeList(List_t& List);
	// �������� ����� � ������������� ������
	void insert(int x, List_t& L);
	// ��'���� ��� ����������� ������ (����� �������� � �����)
	List_t merge(List_t a, List_t b);
}
