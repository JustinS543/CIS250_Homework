#include "Department.h"

Department::Department()
{
	initDepartment();
}

void Department::initDepartment()
{
	deptID = "";
	deptName = "";
	bLetter = "";
	flrNum = "";
	deptPhNum = "";
}

string Department::getdeptID() const
{
	return deptID;
}
void Department::setdeptID(string id)
{
	deptID = id;
}
string Department::getdeptName() const
{
	return deptName;
}
void Department::setdeptName(string n)
{
	deptName = n;
}
string Department::getbLetter() const
{
	return bLetter;
}
void Department::setbLetter(string bl)
{
	bLetter = bl;
}
string Department::getflrNum() const
{
	return flrNum;
}
void Department::setflrNum(string fnum)
{
	flrNum = fnum;
}
string Department::getdeptPhNum() const
{
	return deptPhNum;
}
void Department::setdeptPhNum(string phNum)
{
	deptPhNum = phNum;
}
