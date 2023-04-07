//====================
// Name: Justin Schley
// Date:    04-04-2023
// Desc:   CIS250 HW04
//====================

This program reads from a text file containing census data.

In main, the lines of the text file must be set by the "size" variable.
The program then creates a reader object to read the file in.
Using the writeArray function, the reader object will create an array of the census data.
Using the display function, the reader object will ask the user if they would like to use 
bubble or insertion sort to sort the data by the ID variable.

**Reader

The Reader class contains variables and functions to read, write, and sort data.
The variables which contain Pos or Len change the position and length of the data to
accomodate differently parsed files. Variables ending in Temp are used to temporarily hold data
to pass to a Person object. The array is created using the Person class to create Person objects
for each position in the array.

**Person

The Person class contains variables for name, wage, ID, and deptID. The class uses an overloaded
constructor to accept data and create a Person object. There are also getters for each variable
to get the information from each object.