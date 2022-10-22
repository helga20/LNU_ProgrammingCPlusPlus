#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES

using namespace std;

class Figure 
{
public:
    virtual void calculate_square() const = 0;
    virtual void calculate_perimeter() const = 0;
};

class Circle : public Figure 
{
private:
    double r;
public:
    void calculate_square() const
    {
        const double M_PI = 3.14;
        cout << M_PI * r * r;
    }
    void calculate_perimeter() const
    {
        const double M_PI = 3.14;
        cout << 2 * M_PI * r;
    }
    Circle(double rad)
        : r(rad) {}
};

class Triangle : public Figure 
{
private:
    double a, b, angle;
public:
    void calculate_square() const
    {
        const double M_PI = 3.14;
        cout << sqrt(0.5 * a * b * sin(angle));
    }
    void calculate_perimeter() const
    {
        double  p = a*a + b*b - (2 * (a * b * cos(angle)));
        cout <<p;
    }
    Triangle(double side_a, double side_b)
        : a(side_a), b(side_b) {}
};


class Rectangle : public Figure
{
private:
    double a, b;
public:
    void calculate_square() const
    {
        cout << a * b;
    }
    void calculate_perimeter() const 
    {
        cout << 2 * (a + b);
    }
    Rectangle(double side_a, double side_b)
        : a(side_a), b(side_b) {}
};

class Square : public Figure
{
private:
    double a;
public:
    void calculate_square() const 
    {
        cout << a * a;
    }
    void calculate_perimeter() const 
    {
        cout << 4 * a;
    }
    Square(double side_a)
        : a(side_a) {}
};
