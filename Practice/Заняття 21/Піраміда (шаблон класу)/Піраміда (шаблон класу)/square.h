#pragma once
#include <iostream>

class Square
{
private:
    double side;

public:
    Square();
    Square(double a);
    Square(const Square& S);
    ~Square();

    void printInfo() const;

    double getPerimeter() const;
    double getSquare() const;
    char getType() const;

    void readFrom(std::istream& in);
    void writeTo(std::ostream& out) const;
};

std::istream& operator>>(std::istream& in, Square& S);
std::ostream& operator<<(std::ostream& out, const Square& S);


