//====================
// Name: Justin Schley
// Date:    04-04-2023
// Desc:   CIS250 HW04
//====================


#include <iostream>
#include <string>
#include "Driver.h"

using namespace std;

int main()
{
    int size = 577; //This allows one value to change the length of the list
    Driver drive; //initialize Driver object
    drive.setSize(size); //sets the size in drive for creating the array
    drive.writeArray(); //writes data from the file into an array stored in drive
    drive.menu(); //display menu, calls sorts based on selection
}

