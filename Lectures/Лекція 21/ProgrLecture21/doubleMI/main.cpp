#include <iostream>
using namespace std;
class Point
{
private:
	int x,y;
public:
	Point(int nx=0, int ny=0): x(nx), y(ny) {}
	virtual ~Point() {}
	int getX() const { return x; }
	int getY() const { return y; }
	void setXY(int,int);
	void show() const;
};
class HPoint: public Point
{
public:
	HPoint(int nx=0, int ny=0): Point(nx,ny) {}
};
class Rect: private Point, private HPoint
{
public:
	Rect(int ltX=0, int ltY=0, int rbX=10, int rbY=10): Point(ltX,ltY), HPoint(rbX,rbY) {}
	void show() const;
};
int main()
{
	Point A(10,20); HPoint B(100,50);
	cout<<"A = "; A.show(); cout<<'\n';
	cout<<"B = "; B.show(); cout<<'\n';
	Rect R(A.getX(),A.getY(),B.getX(),B.getY());
	R.show(); cin.get();
	return 0;
}

void Point::setXY(int nx, int ny)
{
	x = (nx<0)?-x:x;
	y = (ny<0)?-y:y;
}
void Point::show() const
{
	cout<<'('<<x<<','<<y<<')';
}
void Rect::show() const
{
	cout<<"Rectangle["; Point::show();
	cout<<"-->"; HPoint::show();
	cout<<"]\n";
}