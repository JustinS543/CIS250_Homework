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
	//Constructor/Overloaded Constructor
	Person();
	Person(string, double, int, int);
	//Getters
	string getName();
	double getWage();
	int getID();
	int getDeptID();
};

