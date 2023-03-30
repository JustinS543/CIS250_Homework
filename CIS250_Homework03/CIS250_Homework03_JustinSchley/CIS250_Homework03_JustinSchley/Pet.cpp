#include "Pet.h"
#include <iostream>

using namespace std;

Pet::Pet()
{
	ID = 0;
	name = "";
	type = "";
	age = 0;
}
Pet::Pet(int id, string t, string n, int a)
{
	ID = id;
	name = n;
	type = t;
	age = a;
}
void Pet::setID(int newID)
{
	ID = newID;
}
int Pet::getID()
{
	return ID;
}
string Pet::getType()
{
	return type;
}
string Pet::getName()
{
	return name;
}
int Pet::getAge()
{
	return age;
}
