#pragma once
#include "Person.h"
#include <fstream>
#include <iomanip>
#include "time.h"
#include "chrono"

class Reader
{
private:
	//Temporary storage for data from the file
	string nameTemp;
	string dumpTemp;
	double wageTemp;
	int IDTemp;
	int deptIDTemp;
public:
	//Constructor
	Reader();
	//Read file and write to array
	Person* writeArray(int);
};

