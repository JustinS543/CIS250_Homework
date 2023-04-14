//====================
// Name: Justin Schley
// Date:    04-04-2023
// Desc:   CIS250 HW04
//====================

This program reads from a text file containing census data.

In main, the lines of the text file must be set by the "size" variable. The program then creates a driver object to read the file in through a Reader object. Using the writeArray function, the driver object will create an array of the census data through the reader object. Using the display function, the driver object will ask the user if they would like to use bubble or insertion sort to sort the data by the ID variable.

**Driver

The Driver class contains variables and functions to create a new array through the Reader class, sort through the array created, and to display two different sort algorithms.

**Reader

The Reader class contains variables and functions to read data from a text file. It will sort data based on line and spaces in between the data.

**Person

The Person class contains variables for name, wage, ID, and deptID. The class uses an overloaded constructor to accept data and create a Person object. There are also getters for each variable to get the information from each object.

**Issues

Rewriting a good chunk of the Reader and Driver classes because I hardcoded sizes into it as a stop gap, copy/pasting code back in so that the program would run properly, then spending 2 hours on Easter figuring out why I'm getting read access violations. Turns out, I had forgotten to put the line back in that modifies the private variable "size" in Reader that tells it what size the array should be. Reader was attempting to write to an array sized to null.