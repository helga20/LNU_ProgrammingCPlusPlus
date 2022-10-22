#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using std::cout;
using std::ios_base;
using std::ofstream;
using std::setw;
int main()
{
	// �������� ���� ��� ��������� ���������� ���������
	ofstream fout("table.dat", ios_base::out | ios_base::binary);
	double x, y;
	cout<<"    x    |    sin\n"
		<<"-----------------------\n";
	for (int i = 0; i<=31; i++)
	{
		x = i * 0.2;
		y = sin(x);
		// ����� �������� �������� �� �������
		cout<<setw(6)<<x<<"   |   "<<y<<'\n';
		// ����� ���������� �������� �� �����
		fout.write((char*) &x, sizeof x);
		fout.write((char*) &y, sizeof y);
	}
	// ������, ���� ����'������ ���������
	fout.close();
	system("pause");
	return 0;
}
/*
By C++ program

	x    |    sin
-----------------------
	 0   |   0
   0.2   |   0.198669
   0.4   |   0.389418
   0.6   |   0.564642
   0.8   |   0.717356
	 1   |   0.841471
   1.2   |   0.932039
   1.4   |   0.98545
   1.6   |   0.999574
   1.8   |   0.973848
	 2   |   0.909297
   2.2   |   0.808496
   2.4   |   0.675463
   2.6   |   0.515501
   2.8   |   0.334988
	 3   |   0.14112
   3.2   |   -0.0583741
   3.4   |   -0.255541
   3.6   |   -0.44252
   3.8   |   -0.611858
	 4   |   -0.756802
   4.2   |   -0.871576
   4.4   |   -0.951602
   4.6   |   -0.993691
   4.8   |   -0.996165
	 5   |   -0.958924
   5.2   |   -0.883455
   5.4   |   -0.772764
   5.6   |   -0.631267
   5.8   |   -0.464602
	 6   |   -0.279415
   6.2   |   -0.0830894


By Object Pascal program

	 x   |     sin
----------------------
   0.0   |    0.000000
   0.2   |    0.198669
   0.4   |    0.389418
   0.6   |    0.564642
   0.8   |    0.717356
   1.0   |    0.841471
   1.2   |    0.932039
   1.4   |    0.985450
   1.6   |    0.999574
   1.8   |    0.973848
   2.0   |    0.909297
   2.2   |    0.808496
   2.4   |    0.675463
   2.6   |    0.515501
   2.8   |    0.334988
   3.0   |    0.141120
   3.2   |   -0.058374
   3.4   |   -0.255541
   3.6   |   -0.442520
   3.8   |   -0.611858
   4.0   |   -0.756802
   4.2   |   -0.871576
   4.4   |   -0.951602
   4.6   |   -0.993691
   4.8   |   -0.996165
   5.0   |   -0.958924
   5.2   |   -0.883455
   5.4   |   -0.772764
   5.6   |   -0.631267
   5.8   |   -0.464602
   6.0   |   -0.279415
   6.2   |   -0.083089

*/