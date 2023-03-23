//======================================
// Name: Justin Schley
// Date: 2023-02-02
// Desc: HW01 - Employee Structured Data
//======================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Dept
{
    int deptID;
    string deptName;
    string bLetter;
    int flrNum;
    string deptPhNum;
};
struct Employee
{
    string social;
    string fName;
    string lName;
    string mInit;
    string city;
    string state;
    int age;
    string gender;
    Dept department;
};

void readTextFileVector(vector<Employee>&);
void display();
void allEmps(int, vector<Employee>&);
void oldest(int, vector<Employee>&);
void csbuilding(int, vector<Employee>&);
void abuilding(int, vector<Employee>&);
void social(int, vector<Employee>&);
void averageage(int, vector<Employee>&);
string choice(vector<Employee>&);

int main()
{
    string end;
    vector<Employee> listOfEmps;
    readTextFileVector(listOfEmps);

    while (end != "-999")
    {
        display();
        end = choice(listOfEmps);
    }
}

//=====================================
// Parsing each line from the text file
//=====================================

void readTextFileVector(vector<Employee>& listOfEmps) // I wish I could have found a better way, this seems ugly
{
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
            listOfEmps.push_back(Employee());

            commaPos = lineOfText.find(delim);
            listOfEmps.at(i).social = lineOfText.substr(0, commaPos);
            lineOfText = lineOfText.substr(commaPos + 1);

            commaPos = lineOfText.find(delim);
            listOfEmps.at(i).fName = lineOfText.substr(0, commaPos);
            lineOfText = lineOfText.substr(commaPos + 1);

            commaPos = lineOfText.find(delim);
            listOfEmps.at(i).lName = lineOfText.substr(0, commaPos);
            lineOfText = lineOfText.substr(commaPos + 1);

            commaPos = lineOfText.find(delim);
            listOfEmps.at(i).mInit = lineOfText.substr(0, commaPos);
            lineOfText = lineOfText.substr(commaPos + 1);

            commaPos = lineOfText.find(delim);
            listOfEmps.at(i).city = lineOfText.substr(0, commaPos);
            lineOfText = lineOfText.substr(commaPos + 1);

            commaPos = lineOfText.find(delim);
            listOfEmps.at(i).state = lineOfText.substr(0, commaPos);
            lineOfText = lineOfText.substr(commaPos + 1);

            commaPos = lineOfText.find(delim);
            listOfEmps.at(i).age = stoi(lineOfText.substr(0, commaPos));
            lineOfText = lineOfText.substr(commaPos + 1);

            commaPos = lineOfText.find(delim);
            listOfEmps.at(i).gender = lineOfText.substr(0, commaPos);
            lineOfText = lineOfText.substr(commaPos + 1);

            commaPos = lineOfText.find(delim);
            listOfEmps.at(i).department.deptID = stoi(lineOfText.substr(0, commaPos));
            lineOfText = lineOfText.substr(commaPos + 1);

            commaPos = lineOfText.find(delim);
            listOfEmps.at(i).department.deptName = lineOfText.substr(0, commaPos);
            lineOfText = lineOfText.substr(commaPos + 1);

            commaPos = lineOfText.find(delim);
            listOfEmps.at(i).department.bLetter = lineOfText.substr(0, commaPos);
            lineOfText = lineOfText.substr(commaPos + 1);

            commaPos = lineOfText.find(delim);
            listOfEmps.at(i).department.flrNum = stoi(lineOfText.substr(0, commaPos));
            lineOfText = lineOfText.substr(commaPos + 1);

            commaPos = lineOfText.find(delim);
            listOfEmps.at(i).department.deptPhNum = lineOfText;

            i++;
        }
        inputFile.close();
    }
}

//==========
// Main Menu
//==========

void display()
{
    string choice;

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

//=========================
// Displaying all employees
//=========================

void allEmps(int size, vector<Employee> &listOfEmps)
{
    for (int i = 0; i < size; i++)
    {
        cout << "EMPLOYEE";
        if (i < 10)
        {
            cout << "0" << i << endl;
        }

        else
        {
            cout << i << endl;
        }

        cout << "----------" << endl;
        cout << "SSN            : " << listOfEmps.at(i).social << endl
             << "First Name     : " << listOfEmps.at(i).fName << endl
             << "Last Name      : " << listOfEmps.at(i).lName << endl
             << "Middle Initial : " << listOfEmps.at(i).mInit << endl
             << "City           : " << listOfEmps.at(i).city << endl
             << "State          : " << listOfEmps.at(i).state << endl
             << "Age            : " << listOfEmps.at(i).age << endl
             << "Gender         : " << listOfEmps.at(i).gender << endl
             << "Department ID  : " << listOfEmps.at(i).department.deptID << endl
             << "Department Name: " << listOfEmps.at(i).department.deptName << endl
             << "Building Letter: " << listOfEmps.at(i).department.bLetter << endl
             << "Building Floor : " << listOfEmps.at(i).department.flrNum << endl
             << "Phone Number   : " << listOfEmps.at(i).department.deptPhNum << endl
             << endl << endl;           
    }
}

//========================
// Finding oldest employee
//========================

void oldest(int size, vector<Employee> &listOfEmps)
{
    int age = 0;
    int oldest = 0;
    string fName;
    string lName;
    string mInit;
    for (int i = 0; i < size; i++)
    {
        age = listOfEmps.at(i).age;

        if (age > oldest)
        {
            oldest = age;
            fName = listOfEmps.at(i).fName;
            lName = listOfEmps.at(i).lName;
            mInit = listOfEmps.at(i).mInit;
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

//=====================================================
// Finding which building Computer Science is housed in
//=====================================================

void csbuilding(int size, vector<Employee>& listOfEmps)
{
    string buildingletter;
    int buildingfloor;

    for (int i = 0; i < size; i++)
    {
        if (listOfEmps.at(i).department.deptName == "Computer Science")
        {
            buildingletter = listOfEmps.at(i).department.bLetter;
            buildingfloor = listOfEmps.at(i).department.flrNum;
        }
    }
    cout << "Computer Science Employees" << endl;
    cout << "--------------------------" << endl;
    cout << "Building: " << buildingletter << endl; 
    cout << "Floor   : " << buildingfloor << endl;
}

//================================================
// Finding which departments are in the A building
//================================================

void abuilding(int size, vector<Employee>& listOfEmps)
{
    int counter = 0;
    vector<string> bldgA;
    vector<string> bldgAPrint;

    for (int i = 0; i < size; i++)
    {
        if (listOfEmps.at(i).department.bLetter == "A")
        {
            bldgA.push_back(listOfEmps.at(i).department.deptName);
            counter++;
        }
    }

    int aSize = bldgA.size();
    bool found = false;
    bldgAPrint.push_back(bldgA[0]);
    int printSize = bldgAPrint.size();

    for (int i = 0; i < aSize; i++)
    {
        found = false;

        for (int j = 0; j < printSize; j++)
        {
            if (bldgA[i] == bldgAPrint[j])
            {
                found = true;
            }
        }

        if (found == false)
        {
            bldgAPrint.push_back(bldgA[i]);
        }
        printSize = bldgAPrint.size();
    }

    cout << "Building A Departments" << endl;
    cout << "----------------------" << endl;

    for (int i = 0; i < printSize; i++)
    {
        cout << bldgAPrint[i] << endl;
    }
}

//===========================
// Find employee based on SSN
//===========================

void social(int size, vector<Employee>& listOfEmps)
{
    string social;
    bool found = false;
    int position;

    vector<string> ssnDashRem;

    cout << "Find Employee By Social Security Number" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Enter the ssn for the employee: ";
    getline(cin, social);

    // This next section is filled with pain & misery

    for (int i = 0; i < size; i++)
    {
        int currentSize = listOfEmps.at(i).social.size();
        //int counter = 0;
        string newssn;

        for (int j = 0; j < currentSize; j++)
        {
            
            if (listOfEmps.at(i).social[j] != '-')
            {
                newssn += listOfEmps.at(i).social.at(j);
                //counter++;
            }
        }
        //counter = 0;
        ssnDashRem.push_back(newssn);
    }

    for (int i = 0; i < size; i++)
    {
        if (social == listOfEmps.at(i).social || social == ssnDashRem.at(i))
        {
            found = true;
            position = i;
        }
    }

    if (found == true)
    {
        cout << "SSN            : " << listOfEmps.at(position).social << endl
             << "First Name     : " << listOfEmps.at(position).fName << endl
             << "Last Name      : " << listOfEmps.at(position).lName << endl
             << "Middle Initial : " << listOfEmps.at(position).mInit << endl
             << "City           : " << listOfEmps.at(position).city << endl
             << "State          : " << listOfEmps.at(position).state << endl
             << "Age            : " << listOfEmps.at(position).age << endl
             << "Gender         : " << listOfEmps.at(position).gender << endl
             << "Department ID  : " << listOfEmps.at(position).department.deptID << endl
             << "Department Name: " << listOfEmps.at(position).department.deptName << endl
             << "Building Letter: " << listOfEmps.at(position).department.bLetter << endl
             << "Building Floor : " << listOfEmps.at(position).department.flrNum << endl
             << "Phone Number   : " << listOfEmps.at(position).department.deptPhNum << endl
             ;
    }

    else
    {
        cout << "The employee with the ssn of " << social << " does not exist" << endl;
    }
}

//=================================================
// Calculates average age for employees in Michigan
//=================================================

void averageage(int size, vector<Employee>& listOfEmps)
{
    int totalages = 0;
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (listOfEmps.at(i).state == "MI")
        {
            totalages += listOfEmps.at(i).age;
            count++;
        }
    }

    cout << "Average age for employees who live in MI" << endl;
    cout << "----------------------------------------" << endl;
    cout << totalages / count << endl;
}

//=============================
// parses user input for choice
//=============================

string choice(vector<Employee>& listOfEmps)
{
    string choice;
    int size = listOfEmps.size();

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
            allEmps(size, listOfEmps);
        }

        if (choice == "2")
        {
            system("cls");
            oldest(size, listOfEmps);
        }

        if (choice == "3")
        {
            system("cls");
            csbuilding(size, listOfEmps);
        }

        if (choice == "4")
        {
            system("cls");
            abuilding(size, listOfEmps);
        }

        if (choice == "5")
        {
            system("cls");
            social(size, listOfEmps);
        }

        if (choice == "6")
        {
            system("cls");
            averageage(size, listOfEmps);
        }

        else
        {
            //https://www.youtube.com/watch?v=A2VpR8HahKc
        }
    }
}