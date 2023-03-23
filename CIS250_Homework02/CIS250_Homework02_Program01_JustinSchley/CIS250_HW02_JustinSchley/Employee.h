#pragma once
#include <string>
#include "Department.h"
using namespace std;

class Employee
{
private:
	string social;
	string fName;
	string lName;
	string mInit;
	string city;
	string state;
	string gender;
	int age;
	int numberLines;
public:
	Department dept;
	Employee();
	void initEmployee();
	Employee* newEmpArray();
	int lines();

	string getSocial() const;
	string getfName() const;
	string getlName() const;
	string getmInit() const;
	string getcity() const;
	string getstate() const;
	string getgender() const;
	int getage() const;

	void setsocial(string);
	void setfName(string);
	void setlName(string);
	void setmInit(string);
	void setcity(string);
	void setstate(string);
	void setage(int);
	void setgender(string);

	string choice(Employee*);
	void menu(Employee*);
	void display();
	void allEmps(Employee*);
	void oldest(Employee*);
	void csbuilding(Employee*);
	void abuilding(Employee*);
	void ssnLookup(Employee*);
	void averageage(Employee*);
};

