#pragma once

class Shape
{
public:
	virtual double sideSquare() const = 0;
	virtual double fullSquare() const abstract;
	virtual double volume() const abstract;
};