#pragma once
#include "Person.h"
#include <fstream>
#include <iomanip>
#include "time.h"
#include "chrono"

class Reader
{
private:
	//Person array & size
	Person* array;
	int size;
	//Chrono time storage
	double timeSecond;
	double timeMinute;
	//Temporary storage for data from the file
	string nameTemp;
	string dumpTemp;
	double wageTemp;
	int IDTemp;
	int deptIDTemp;
public:
	Reader();
	void writeArray(int);
	void display();
	void bubbleSort();
	void insertionSort();
};

