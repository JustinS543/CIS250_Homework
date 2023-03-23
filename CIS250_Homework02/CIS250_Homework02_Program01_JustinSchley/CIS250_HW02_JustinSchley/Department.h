#pragma once
#include <string>
using namespace std;

class Department
{
private:
	string deptID;
	string deptName;
	string bLetter;
	string flrNum;
	string deptPhNum;
public:
	Department();
	void initDepartment();

	string getdeptID() const;
	string getdeptName() const;
	string getbLetter() const;
	string getflrNum() const;
	string getdeptPhNum() const;

	void setdeptID(string);
	void setdeptName(string);
	void setbLetter(string);
	void setflrNum(string);
	void setdeptPhNum(string);
};

