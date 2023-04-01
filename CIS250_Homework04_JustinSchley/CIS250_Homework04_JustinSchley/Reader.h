#pragma once
#include "Person.h"
#include <fstream>
#include <iomanip>
#include "time.h"
#include "chrono"

class Reader
{
private:
	Person* array;
	//Chrono time storage
	double timeSecond;
	double timeMinute;
	int size;
	//Temporary storage for data from the file
	string nameTemp;
	double wageTemp;
	int IDTemp;
	int deptIDTemp;
	//The following values can be changed to adjust for different files
	int namePos = 0;
	int nameLen = 15;
	int wagePos = 21;
	int wageLen = 6;
	int IDPos = 29;
	int IDLen = 5;
	int deptIDPos = 36;
	int deptIDLen = 7;
public:
	Reader();
	void writeArray(int);
	void display();
	void bubbleSort();
	void insertionSort();
};

