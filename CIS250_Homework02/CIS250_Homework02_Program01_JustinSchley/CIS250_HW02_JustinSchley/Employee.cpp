#include "Employee.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Constructor
Employee::Employee()
{
	initEmployee();
}

//Initialize Basic Employee
void Employee::initEmployee()
{
	social = "";
	fName = "";
	lName = "";
	mInit = "";
	city = "";
	state = "";
	age = 0;
	gender = "";
	dept.setdeptID("");
	dept.setdeptName("");
	dept.setbLetter("");
	dept.setflrNum("");
	dept.setdeptPhNum("");
	numberLines = lines();
}

//Counting lines of text
int Employee::lines()
{
	ifstream inputFile;
	string fileName = "EmployeeList.txt";
	string lineOfText;
	int i = 0;

	inputFile.open(fileName);

	if (!inputFile)
	{
		cout << "Error: Could not open file" << endl;
	}

	if (inputFile.is_open())
	{
		while (!inputFile.eof())
		{
			getline(inputFile, lineOfText);
			i++;
		}
	}

	inputFile.close();
	numberLines = i;
	return i;
}

//Initialize Employee Array
Employee* Employee::newEmpArray()
{
	Employee* empArray = new Employee[numberLines];
	ifstream inputFile;
	string fileName = "EmployeeList.txt";
	string lineOfText;
	char delim = ',';
	int commaPos;
	int i = 0;

	inputFile.open(fileName);

	if (inputFile)
	{
		while (getline(inputFile, lineOfText))
		{
			commaPos = lineOfText.find(delim);
			empArray[i].setsocial(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);

			commaPos = lineOfText.find(delim);
			empArray[i].setfName(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);

			commaPos = lineOfText.find(delim);
			empArray[i].setlName(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);

			commaPos = lineOfText.find(delim);
			empArray[i].setmInit(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);

			commaPos = lineOfText.find(delim);
			empArray[i].setcity(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);

			commaPos = lineOfText.find(delim);
			empArray[i].setstate(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);

			commaPos = lineOfText.find(delim);
			empArray[i].setage(stoi(lineOfText.substr(0, commaPos)));
			lineOfText = lineOfText.substr(commaPos + 1);

			commaPos = lineOfText.find(delim);
			empArray[i].setgender(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);

			commaPos = lineOfText.find(delim);
			empArray[i].dept.setdeptID(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);

			commaPos = lineOfText.find(delim);
			empArray[i].dept.setdeptName(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);

			commaPos = lineOfText.find(delim);
			empArray[i].dept.setbLetter(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);

			commaPos = lineOfText.find(delim);
			empArray[i].dept.setflrNum(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);

			commaPos = lineOfText.find(delim);
			empArray[i].dept.setdeptPhNum(lineOfText);

			i++;
		}
		inputFile.close();
	}
	return empArray;
}

//Get Functions
string Employee::getSocial() const
{
	return social;
}
string Employee::getfName() const
{
	return fName;
}
string Employee::getlName() const
{
	return lName;
}
string Employee::getmInit() const
{
	return mInit;
}
string Employee::getcity() const
{
	return city;
}
string Employee::getstate() const
{
	return state;
}
string Employee::getgender() const
{
	return gender;
}
int Employee::getage() const
{
	return age;
}

//Set Functions
void Employee::setsocial(string i)
{
	social = i;
}
void Employee::setfName(string i)
{
	fName = i;
}
void Employee::setlName(string i)
{
	lName = i;
}
void Employee::setmInit(string i)
{
	mInit = i;
}
void Employee::setcity(string i)
{
	city = i;
}
void Employee::setstate(string i)
{
	state = i;
}
void Employee::setage(int i)
{
	age = i;
}
void Employee::setgender(string i)
{
	gender = i;
}

//Main Menu Function
void Employee::menu(Employee* empArray)
{
	string end;

	while (end != "-999")
	{
		empArray->display();
		end = choice(empArray);
	}
}

//Main Display Function
void Employee::display()
{
	cout << "               EMPLOYEE INFORMATION SCP HOLDINGS INC.\n"
		 << "---------------------------------------------------------------------\n"
		 << "   1. Display all employees\n"
		 << "   2. Display name of oldest employee\n"
		 << "   3. Display the building letter and floor for Computer Science Department\n"
		 << "   4. Display department names who are in building A\n"
		 << "   5. Find an employee and list their information\n"
		 << "   6. Average age of employees who live in Michigan\n"
		 << "  99. Return to Menu\n"
		 << "-999. Exit program\n";
}

//Determines what choice the user entered
string Employee::choice(Employee* empArray)
{
	string choice;

	while (choice != "1" || choice != "2" || choice != "3" || choice != "4" || choice != "5" || choice != "6" || choice != "99" || choice != "-999")
	{
		cout << "Enter your selection (99 for menu, -999 to exit): ";
		getline(cin, choice);

		if (choice == "-999")
		{
			system("cls");
			return "-999";
		}
		if (choice == "99")
		{
			system("cls");
			return "99";
		}
		if (choice == "1")
		{
			system("cls");
			allEmps(empArray);
		}
		if (choice == "2")
		{
			system("cls");
			oldest(empArray);
		}
		if (choice == "3")
		{
			system("cls");
			csbuilding(empArray);
		}
		if (choice == "4")
		{
			system("cls");
			abuilding(empArray);
		}
		if (choice == "5")
		{
			system("cls");
			ssnLookup(empArray);
		}
		if (choice == "6")
		{
			system("cls");
			averageage(empArray);
		}
		else
		{
			//do nothing
		}
	}
}

//Displays all employees
void Employee::allEmps(Employee* empArray)
{
	for (int i = 0; i < numberLines; i++)
	{
		cout << "EMPLOYEE";
		if (i < 10)
		{
			cout << "0" << i + 1 << endl;
		}

		else
		{
			cout << i + 1 << endl;
		}

		cout << "----------" << endl;
		cout << "SSN            : " << empArray[i].getSocial() << endl
			 << "First Name     : " << empArray[i].getfName() << endl
			 << "Last Name      : " << empArray[i].getlName() << endl
			 << "Middle Initial : " << empArray[i].getmInit() << endl
			 << "City           : " << empArray[i].getcity() << endl
			 << "State          : " << empArray[i].getstate() << endl
			 << "Age            : " << empArray[i].getage() << endl
			 << "Gender         : " << empArray[i].getgender() << endl
			 << "Department ID  : " << empArray[i].dept.getdeptID() << endl
			 << "Department Name: " << empArray[i].dept.getdeptName() << endl
			 << "Building Letter: " << empArray[i].dept.getbLetter() << endl
			 << "Building Floor : " << empArray[i].dept.getflrNum() << endl
			 << "Phone Number   : " << empArray[i].dept.getdeptPhNum() << endl
			 << endl << endl;
	}
}

//Displays oldest employee
void Employee::oldest(Employee* empArray)
{
	int age = 0;
	int oldest = 0;
	string fName;
	string lName;
	string mInit;

	for (int i = 0; i < numberLines; i++)
	{
		age = empArray[i].getage();

		if (age > oldest)
		{
			oldest = age;
			fName = empArray[i].getfName();
			lName = empArray[i].getlName();
			mInit = empArray[i].getmInit();
		}
	}

	cout << "Oldest Employee Name" << endl;
	cout << "--------------------" << endl;
	cout << lName << ", "
		 << fName << " "
		 << mInit << "."
		 << endl;

	cout << "Age: " << oldest << endl;
}

//Displays floor number and building letter of the CS building
void Employee::csbuilding(Employee* empArray)
{
	string buildingletter;
	int buildingfloor;

	for (int i = 0; i < numberLines; i++)
	{
		if (empArray[i].dept.getdeptName() == "Computer Science")
		{
			buildingletter = empArray[i].dept.getbLetter();
			buildingfloor = stoi(empArray[i].dept.getflrNum());
		}
	}

	cout << "Computer Science Employees" << endl;
	cout << "--------------------------" << endl;
	cout << "Building: " << buildingletter << endl;
	cout << "Floor   : " << buildingfloor << endl;
}

//Displays departments in the A building
void Employee::abuilding(Employee* empArray)
{
	int counter = 0;
	string* bldgA = new string[numberLines];
	string* bldgAPrint = new string[numberLines];
	bool found = false;

	for (int i = 0; i < numberLines; i++)
	{
		bldgA[i] = "";
		bldgAPrint[i] = "";
	}

	for (int i = 0; i < numberLines; i++)
	{
		if (empArray[i].dept.getbLetter() == "A")
		{
			bldgA[i] = empArray[i].dept.getdeptName();
			counter++;
		}
	}

	counter = 0;

	for (int i = 0; i < numberLines; i++)
	{
		found = false;

		for (int j = 0; j < numberLines; j++)
		{
			if (bldgA[i] == bldgAPrint[j])
			{
				found = true;
			}
		}

		if (found == false)
		{
			bldgAPrint[counter] = bldgA[i];
			counter++;
		}
	}

	cout << "Building A Departments" << endl;
	cout << "----------------------" << endl;

	for (int i = 0; i < numberLines; i++)
	{
		if (bldgAPrint[i] != "")
		{
			cout << bldgAPrint[i] << endl;
		}
	}

}

//Searches for employee based on SSN (disregards dashes if entered)
void Employee::ssnLookup(Employee* empArray)
{
	string social;
	bool found = false;
	int position;
	string* ssnArray = new string[numberLines];


	cout << "Find Employee By Social Security Number" << endl;
	cout << "---------------------------------------" << endl;
	cout << "Enter the ssn for the employee: ";
	getline(cin, social);

	for (int i = 0; i < numberLines; i++)
	{
		string oldssn = empArray[i].getSocial();
		string newssn;
		int ssnSize = oldssn.size();

		for (int j = 0; j < ssnSize; j++)
		{

			if (oldssn.at(j) != '-')
			{
				newssn += oldssn.at(j);
			}
		}
		ssnArray[i] = newssn;
	}

	for (int i = 0; i < numberLines; i++)
	{
		if (social == empArray[i].getSocial() || social == ssnArray[i])
		{
			found = true;
			position = i;
		}
	}

	if (found == true)
	{
		cout << "SSN            : " << empArray[position].getSocial() << endl
			 << "First Name     : " << empArray[position].getfName() << endl
			 << "Last Name      : " << empArray[position].getlName() << endl
			 << "Middle Initial : " << empArray[position].getmInit() << endl
			 << "City           : " << empArray[position].getcity() << endl
			 << "State          : " << empArray[position].getstate() << endl
			 << "Age            : " << empArray[position].getage() << endl
			 << "Gender         : " << empArray[position].getgender() << endl
			 << "Department ID  : " << empArray[position].dept.getdeptID() << endl
			 << "Department Name: " << empArray[position].dept.getdeptName() << endl
			 << "Building Letter: " << empArray[position].dept.getbLetter() << endl
			 << "Building Floor : " << empArray[position].dept.getflrNum() << endl
			 << "Phone Number   : " << empArray[position].dept.getdeptPhNum() << endl;
	}

	else
	{
		cout << "The employee with the ssn of " << social << " does not exist" << endl;
	}
}

//Displays average age of employees in Michigan
void Employee::averageage(Employee* empArray)
{
	int totalages = 0;
	int count = 0;

	for (int i = 0; i < numberLines; i++)
	{
		if (empArray[i].getstate() == "MI")
		{
			totalages += empArray[i].getage();
			count++;
		}
	}

	cout << "Average age for employees who live in MI" << endl;
	cout << "----------------------------------------" << endl;
	cout << totalages / count << endl;
}