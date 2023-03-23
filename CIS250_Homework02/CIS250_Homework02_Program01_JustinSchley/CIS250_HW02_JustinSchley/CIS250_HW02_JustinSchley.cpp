//=====================================================
// Name:                                  Justin Schley
// Date:                                      2/28/2023
// Desc: CIS250 Homework 2 - Program 1 (Employee Array)
//=====================================================

#include <iostream>
#include <fstream>
#include <string>
#include "Employee.h"
#include "Department.h"

using namespace std;

int main()
{
    Employee baseEmployee; //Creates Employee object
    Employee* empArray = baseEmployee.newEmpArray(); //Creates array of Employee objects, including calculating how many lines of text
    empArray->menu(empArray); //Starts the menu function
}
