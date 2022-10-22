#ifndef vector_h_1
#define vector_h_1

#include <iostream>
namespace VECTOR
{
	using std::ostream;
	class Vector
	{
	private:
		double x, y, mag, ang;
		char mode;
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
	public:
		Vector();
		Vector(double,double,char form='r');
		Vector(double);
		~Vector();
		void set(double, double, char form = 'r');
		double x_val() const { return x; }
		double y_val() const { return y; }
		double mag_val() const { return mag; }
		double ang_val() const { return ang; }
		void polar_mode() { mode = 'p'; }
		void rect_mode() { mode = 'r'; }
		Vector operator+(const Vector& b) const;
		Vector operator-(const Vector& b) const;
		Vector operator-() const;
		Vector operator*(double n) const;
		operator double() const { return mag; }
		friend Vector operator*(double n, const Vector& a);
		friend ostream & operator<<(ostream& os, const Vector& a);
	};
}
#endif