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
	¬—“јЌќ¬Ћ≈ЌЌя ѕќ„ј“ ќ¬»’ ЌјЋјЎ“”¬јЌ№
*/
	SetConsoleOutputCP(1251);
	srand(time(0));
	cout<<"ѕрограма моделюванн€ обслуговуванн€ банкоматом черги кл≥Їнт≥в\n"
		<<"* —т≥вен ѕрата * √лава 12, ст. 580-600\n"
		<<"  ¬икористано класи: Queue - черга, Customer - кл≥Їнт\n\n";
	int qs;
	cout<<"¬вед≥ть максимальний розм≥р черги: "; cin>>qs;
	Queue line(qs);
	int hours;
	cout<<"¬вед≥ть к≥льк≥сть годин - тривал≥сть пер≥оду моделюванн€: "; cin>>hours;
	long cycleLimit = MIN_PER_HR * hours;            //одна хвилина - один крок циклу
	double perHour;
	cout<<"—к≥льки кл≥Їнт≥в у середньому за годину приходить до банкомата? "; cin>>perHour;
	double min_per_cust = MIN_PER_HR / perHour;     //середн≥й час м≥ж п≥дходами кл≥Їнт≥в
	Item temp;                 //черговий кл≥Їнт;   л≥чильники:
	long turnAways = 0;        //     втеч в≥д повноњ черги
	long customers = 0;        //     ставань  вчергу
	long served = 0;           //     обслужених кл≥Їнт≥в
	long sum_line = 0;         //     сумарна довжина черги
	int wait_time = 0;         //     час, поки банкомат зайн€то
	long line_wait = 0;        //     загальний час в черз≥
/*
	ѕ–ќ÷≈— ѕќ’¬»Ћ»ЌЌќ√ќ ћќƒ≈Ћё¬јЌЌя
*/
	for (int cycle=0; cycle<cycleLimit; cycle++)
	{
		if (newCustomer(min_per_cust))
		{
			if (line.isFull())
				turnAways++;         // в повну чергу кл≥Їнти не стають
			else
			{
				customers++;
				temp.set(cycle);     // cycle - час прибутт€ (в хв.)
				line.enqueue(temp);  // кл≥Їнт став до черги
			}
		}
		if (wait_time<=0 && !line.isEmpty())
		{                            // банкомат в≥льний, Ї черга
			line.dequeue(temp);      // обслуговують наступного кл≥Їнта
			wait_time = temp.ptime();
			line_wait += cycle-temp.when(); //кл≥Їнт чекав (час_тепер-час_прибутт€) хв.
			served++;
		}
		if (wait_time>0)             // банкомат зайн€то
			wait_time--;             // триваЇ обслуговуванн€
		sum_line += line.queueCount(); // сумарна довжина на цю хвилю
	}
/*
	¬»¬≈ƒ≈ЌЌя ќ“–»ћјЌ»’ –≈«”Ћ№“ј“≤¬
*/
	if (customers>0)
	{
		cout<<"\n --- –≈«”Ћ№“ј“» ћќƒ≈Ћё¬јЌЌя ---\n"
			<<"   стали в чергу кл≥Їнт≥в: "<<customers<<'\n'
			<<"  отримали обслуговуванн€: "<<served<<'\n'
			<<"        ще сто€ть в черз≥: "<<line.queueCount()<<'\n'
			<<"               п≥шли геть: "<<turnAways<<'\n';
		cout.precision(2);
		cout.setf(ios_base::fixed,ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout<<"    середн€ довжина черги: "<<double(sum_line)/cycleLimit<<'\n'
			<<"  середн≥й час оч≥куванн€: "<<double(line_wait)/served<<" хв.\n\n";
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