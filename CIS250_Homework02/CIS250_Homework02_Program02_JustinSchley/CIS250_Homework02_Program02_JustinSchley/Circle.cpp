#include "Circle.h"
#include <iostream>
#include <string>

using namespace std;

Circle::Circle()
{
	initCircle();
}
void Circle::initCircle()
{
	setRadius(0.0);
}
void Circle::setRadius(double r)
{
	radius = r;
}
double Circle::getradius()
{
	return radius;
}
double Circle::getArea()
{
	double area = PI * radius * radius;
	return area;
}
double Circle::getDiameter()
{
	double diameter = radius * 2;
	return diameter;
}
double Circle::getCircumference()
{
	double circumference = 2 * PI * radius;
	return circumference;
}
void Circle::display()
{
	double radius;
	cout << "Please enter the radius of your circle: ";
	cin >> radius;
	setRadius(radius);
}
void Circle::results()
{
	cout << "Area:          " << getArea() << endl;
	cout << "Diameter:      " << getDiameter() << endl;
	cout << "Circumference: " << getCircumference() << endl;
}

