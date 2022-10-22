#pragma once
#define _USE_MATH_DEFINES
#include <iostream>

class Circle
{
private:
    double radius;

public:
    Circle();
    Circle(double r);
    Circle(const Circle& C);
    ~Circle();

    void printInfo() const;

    double getPerimeter() const;
    double getSquare() const;
    char getType() const;

    void readFrom(std::istream& in);
    void writeTo(std::ostream& out) const;
};

std::istream& operator>>(std::istream& in, Circle& Ñ);
std::ostream& operator<<(std::ostream& out, const Circle& Ñ);
