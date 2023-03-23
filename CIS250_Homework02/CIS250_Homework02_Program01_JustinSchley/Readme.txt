//=====================================================
// Name:                                  Justin Schley
// Date:                                      2/28/2023
// Desc: CIS250 Homework 2 - Program 1 (Employee Array)
//=====================================================

This program is designed to parse a csv file with employee and department information.
From here, the program displays a menu with various functions, such as:

1. Display all employees
2. Display the oldest employee
3. Display the building letter and floor number of the CS department
4. Display all departments in the A building
5. Lookup an employee based on entering their SSN (works with both dashes and non-dashes)
6. Display the average employee age in Michigan

The program uses a dynamic array. Additionally, there are two classes:

1. Employee
2. Department

When an Employee object is initialized, a nested Department object is also created.
This allows for an employee to have a department directly associated with them.

At any point in the program (excluding entering in an SSN), the user can enter "99" to
return to the main menu, or "-999" to exit the program.