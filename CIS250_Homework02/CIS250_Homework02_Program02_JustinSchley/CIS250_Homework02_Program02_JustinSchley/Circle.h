#pragma once
class Circle
{
private:
	double radius;
	double const PI = 3.14159;

public:
	Circle();
	void initCircle();
	void display();
	void results();

	void setRadius(double);
	double getradius();
	double getArea();
	double getDiameter();
	double getCircumference();
};

