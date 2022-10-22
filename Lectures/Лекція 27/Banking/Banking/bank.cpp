#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
#include <windows.h>
using namespace std;

const int MIN_PER_HR = 60;

bool newCustomer(double);

int main()
{
/*
	������������ ���������� �����������
*/
	SetConsoleOutputCP(1251);
	srand(time(0));
	cout<<"�������� ����������� �������������� ���������� ����� �볺���\n"
		<<"* ����� ����� * ����� 12, ��. 580-600\n"
		<<"  ����������� �����: Queue - �����, Customer - �볺��\n\n";
	int qs;
	cout<<"������ ������������ ����� �����: "; cin>>qs;
	Queue line(qs);
	int hours;
	cout<<"������ ������� ����� - ��������� ������ �����������: "; cin>>hours;
	long cycleLimit = MIN_PER_HR * hours;            //���� ������� - ���� ���� �����
	double perHour;
	cout<<"������ �볺��� � ���������� �� ������ ��������� �� ���������? "; cin>>perHour;
	double min_per_cust = MIN_PER_HR / perHour;     //������� ��� �� �������� �볺���
	Item temp;                 //�������� �볺��;   ���������:
	long turnAways = 0;        //     ���� �� ����� �����
	long customers = 0;        //     �������  ������
	long served = 0;           //     ���������� �볺���
	long sum_line = 0;         //     ������� ������� �����
	int wait_time = 0;         //     ���, ���� �������� �������
	long line_wait = 0;        //     ��������� ��� � ����
/*
	������ ������������ �����������
*/
	for (int cycle=0; cycle<cycleLimit; cycle++)
	{
		if (newCustomer(min_per_cust))
		{
			if (line.isFull())
				turnAways++;         // � ����� ����� �볺��� �� ������
			else
			{
				customers++;
				temp.set(cycle);     // cycle - ��� �������� (� ��.)
				line.enqueue(temp);  // �볺�� ���� �� �����
			}
		}
		if (wait_time<=0 && !line.isEmpty())
		{                            // �������� ������, � �����
			line.dequeue(temp);      // ������������ ���������� �볺���
			wait_time = temp.ptime();
			line_wait += cycle-temp.when(); //�볺�� ����� (���_�����-���_��������) ��.
			served++;
		}
		if (wait_time>0)             // �������� �������
			wait_time--;             // ����� ��������������
		sum_line += line.queueCount(); // ������� ������� �� �� �����
	}
/*
	��������� ��������� ��������Ҳ�
*/
	if (customers>0)
	{
		cout<<"\n --- ���������� ����������� ---\n"
			<<"   ����� � ����� �볺���: "<<customers<<'\n'
			<<"  �������� ��������������: "<<served<<'\n'
			<<"        �� ������ � ����: "<<line.queueCount()<<'\n'
			<<"               ���� ����: "<<turnAways<<'\n';
		cout.precision(2);
		cout.setf(ios_base::fixed,ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout<<"    ������� ������� �����: "<<double(sum_line)/cycleLimit<<'\n'
			<<"  ������� ��� ����������: "<<double(line_wait)/served<<" ��.\n\n";
		Customer::showCounters();
	}
	else
		cout << " N O    C U S T O M E R S !\n";
	system("pause");
	return 0;
}

bool newCustomer(double x)
{
	return rand()*x/RAND_MAX < 1;
}