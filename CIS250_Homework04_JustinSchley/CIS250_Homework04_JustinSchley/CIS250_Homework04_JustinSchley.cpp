#include <iostream>
#include <string>
#include "Reader.h"
#include "Person.h"

using namespace std;

int main()
{
    //use homework 1 for reading text file. use space as delimiter
    //read name, delim is space
    //read the rest of the data based on how far along it is in the list
    //using stoi, convert the string into int. It ignores spaces
    /*string x = "    123";
    int y = stoi(x);
    cout << y << endl;*/

    //take home notes 03/29
    //pass the int size, return an array of the Person class
    int size = 577;
    Reader r;
    r.writeArray(size);
    r.display();
    //Person* arr[size];



}

