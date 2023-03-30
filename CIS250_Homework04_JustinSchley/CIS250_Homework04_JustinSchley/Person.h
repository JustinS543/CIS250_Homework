#pragma once
#include <string>
#include <iostream>
using namespace std;

class Person
{
private:
	string name;
	double wage;
	int ID;
	int deptID;
public:
	Person();
	Person(string, double, int, int);
	void setAll(string, double, int, int);

	string getName();
	double getWage();
	int getID();
	int getDeptID();

};

