#include "vector.h"
#include <cstdlib>
#include <ctime>
using std::cin;
using std::cout;
using VECTOR::Vector;

int main()
{
	double x = 3.0;
	Vector a = x;
	cout<<" vector "<<a<<" constructed by number "<<x<<'\n';
	Vector b(0.0,4.0);
	a = a + b;
	cout<<" vector b = "<<b<<"   and now vector a = a+b = "<<a<<'\n';
	a.polar_mode(); cout<<" or "<<a<<" in polar mode again\n\n";
	a = a + Vector(x);
	cout<<" number x = "<<x<<"   and now vector a = a+Vector(x) = "<<a<<'\n';
	a.polar_mode(); cout<<" or "<<a<<" in polar mode again\n\n";
	a = x + a;
	cout<<" number x = "<<x<<"   and now vector a = x + a = "<<a<<'\n';
	a.polar_mode(); cout<<" or "<<a<<" in polar mode again\n\n";
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0,0.0);
	unsigned long steps = 0;
	double target; double dstep;
	cout << "Enter target distance (or Q): ";
	while (cin >> target)
	{
		cout << "  Enter step length: ";
		if (!(cin >> dstep)) break;
		while (result.mag_val() < target)
		{
			direction = rand() % 360;
			step.set(dstep,direction,'p');
			result = result + step;
			++steps;
		}
		cout << "\n + After "<<steps<<" steps the subject has the folowing location:\n"
			<< result<<" in Cartezian\n";
		result.polar_mode();
		cout << " or\n"<<result<<" in polar\n"
			"Average outward distance per step = "<<result.mag_val()/steps<<'\n';
		steps = 0;
		result.set(0.0,0.0);
		cout << "\nEnter target distance (or Q): ";
	}
	cout<<"Bye!\n";
	return 0;
}