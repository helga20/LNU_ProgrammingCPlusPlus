#pragma once

class Stock
{
private:
	enum { Len = 30 };
	char company[Len];          // ����� ������
	int shares;                 // ������� ����� � �����
	double share_val;           // ���� ���� �����
	double total_val;           // �������� ���� ������
	static Stock default_stock; // ������� ��'��� - ����� ����� ����� ��������� ������
	static int Counter;         // �������� ��������� ��'����
	void set_tot() { total_val = shares * share_val; } // ����� ���������� ���� ������
public:
	Stock();      // ����������� �� ������������� ����������� �������� default_stock
	Stock(const char* co, int n, double pr); // ����������� � �����������
	~Stock();     // ����������
	Stock& buy(int num, double price);  // ����� ����� num ����� �� ����� price
	Stock& sell(int num, double price); // ����� ������� num ����� �� ����� price
	void update(double price);          // ����� ���� ���� ���� �����
	void show() const;                  // ����� ��������� ��'���� �� �������
	const Stock& topval(const Stock& s) const;  // ��������� ���� ������: ����� ������� �������
	static void set_default(const char*,int,double); // ������� ����������� ������ �����
	static int getCounter()  { return Counter; }     // ��������� ���������� ��� ������� ���������
};