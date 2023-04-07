//====================
// Name: Justin Schley
// Date:    04-04-2023
// Desc:   CIS250 HW04
//====================


#include <iostream>
#include <string>
#include "Reader.h"

using namespace std;

int main()
{
    int size = 577; //This allows one value to change the length of the list
    Reader r; //Assignment of the reader
    r.writeArray(size); //Writes the array from the list
    r.display(); //Displays the list forward & backward
}

