#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES

using namespace std;

class Figure {

public:

    virtual void calculate_square() const = 0;
    virtual void calculate_perimeter() const = 0;
};

class Circle : public Figure {

private:

    double r;

public:

    void calculate_square() const {
        const double M_PI = 3.14;
        cout << M_PI * r * r;
    }

    void calculate_perimeter() const {
        const double M_PI = 3.14;
        cout << 2 * M_PI * r;
    }

    Circle(double radius)
        : r(radius) {}
};

class Triangle : public Figure { 

private:

    double a, b, c;

public:

    void calculate_square() const {
        double p = a + b + c;
        cout << sqrt(p * (p - a) * (p - b) * (p - c));
    }

    void calculate_perimeter() const {
        cout << a + b + c;
    }


    Triangle(double side_a, double side_b, double side_c)
        : a(side_a), b(side_b), c(side_c) 
    {}
};

class Rectangle : public Figure { 

private:

    double a, b;

public:
 
    void calculate_square() const {
        cout << a * b;
    }

    void calculate_perimeter() const {
        cout << 2 * (a + b);
    }

    Rectangle(double side_a, double side_b)
        : a(side_a), b(side_b) {}
};

class Square : public Figure { 

private:

    double a;

public:

    void calculate_square() const {
        cout << a * a;
    }

    void calculate_perimeter() const {
        cout << 4 * a;
    }

    Square(double side_a)
        : a(side_a) {}
};

int main() {
    Figure** figure = new Figure * [4];

    cout << "\n\nCircle:";
    figure[0] = new Circle(1);
    cout << "\nSquare: ";
    figure[0]->calculate_square();
    cout << "\nPerimeter: ";
    figure[0]->calculate_perimeter();

    cout << "\nTriangle:";
    figure[1] = new Triangle(1, 2, 1);
    cout << "\nSquare: ";
    figure[1]->calculate_square();
    cout << "\nPerimeter: ";
    figure[1]->calculate_perimeter();

   
    cout << "\n\nRectangle:";
    figure[2] = new Rectangle(1, 3); 
    cout << "\nSquare: ";
    figure[2]->calculate_square();
    cout << "\nPerimeter: ";
    figure[2]->calculate_perimeter();

    cout << "\n\nSquare:";
    figure[3] = new Square(2); 
    cout << "\nSquare: ";
    figure[3] ->calculate_square();
    cout << "\nPerimeter: ";
    figure[3]->calculate_perimeter();

    delete figure[0];
    delete figure[1];
    delete figure[2];
    delete figure[3];
    delete[] figure;

    return 0;

}