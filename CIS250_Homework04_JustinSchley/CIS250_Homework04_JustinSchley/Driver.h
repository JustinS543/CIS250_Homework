#pragma once
#include "Reader.h"
class Driver
{
private:
	Person* array;
	Reader r;
	double timeSecond;
	double timeMinute;
	int size;
public:
	//Constructor
	Driver();
	//Sets size, used for initializing array
	void setSize(int);
	//Calls Reader to write to array
	void writeArray();
	//Displays menu, calls sorting functions
	void menu();
	//Sort algorithms
	void bubbleSort();
	void insertionSort();
};

