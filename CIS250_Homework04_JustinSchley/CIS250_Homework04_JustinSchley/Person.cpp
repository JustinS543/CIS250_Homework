#include "Person.h"

Person::Person()
{
	name = " ";
	wage = 0;
	ID = 0;
	deptID = 0;
}
Person::Person(string n, double w, int id, int did)
{
	name = n;
	wage = w;
	ID = id;
	deptID = did;
}
void Person::setAll(string n, double w, int id, int did)
{
	name = n;
	wage = w;
	ID = id;
	deptID = did;
}
string Person::getName()
{
	return name;
}
double Person::getWage()
{
	return wage;
}
int Person::getID()
{
	return ID;
}
int Person::getDeptID()
{
	return deptID;
}
