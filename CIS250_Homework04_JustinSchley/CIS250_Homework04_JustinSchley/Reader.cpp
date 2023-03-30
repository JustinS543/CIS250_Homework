#include "Reader.h"

Reader::Reader()
{
	
}
void Reader::writeArray(int s)
{
	size = s;
	int i = 0;
	Person* arrayNew = new Person[size];
	ifstream inputFile;
	string fileName = "CensusSmall.txt";
	string lineOfText;

	inputFile.open(fileName);

	if (inputFile)
	{
		while (getline(inputFile, lineOfText))
		{
			nameTemp = lineOfText.substr(namePos, nameLen);
			wageTemp = stod(lineOfText.substr(wagePos, wageLen));
			IDTemp = stoi(lineOfText.substr(IDPos, IDLen));
			deptIDTemp = stoi(lineOfText.substr(deptIDPos, deptIDLen));
			arrayNew[i].setAll(nameTemp, wageTemp, IDTemp, deptIDTemp);
			i++;
		}
		inputFile.close();
	}
	array = arrayNew; //no clue why I need to do this, figure out later
}
void Reader::display()
{
	bool valid = false;
	string select;
	cout << "This program is going to read a very large text file and sort it." << endl;
	cout << "Which sort would you like to perform?" << endl;
	cout << "1. Bubble Sort" << endl;
	cout << "2. Insertion Sort" << endl;
	cout << "Make your selection: ";
	while (valid == false)
	{
		cin >> select;

		if (select == "1")
		{
			valid = true;
			bubbleSort();

			cout << "FIRST 10" << endl;
			cout << "ID" << setw(18) << "Name" << setw(21) << "Hourly" << endl;
			cout << "=========================================" << endl;
			for (int i = 0; i < 10; i++)
			{
				cout << setw(16) << left << array[i].getID() << setw(19) << array[i].getName() << setw(21) << array[i].getWage() << endl;
			}

			cout << "LAST 10" << endl;
			cout << "ID" << setw(18) << "Name" << setw(21) << "Hourly" << endl;
			cout << "=========================================" << endl;
			for (int i = size - 1; i > size - 10; i--)
			{
				cout << setw(16) << left << array[i].getID() << setw(19) << array[i].getName() << setw(21) << array[i].getWage() << endl;
			}

			cout << "It took: " << timeSecond << " second to complete." << endl;
			cout << "It took: " << timeMinute << " minutes to complete." << endl;
		}
		else if (select == "2")
		{
			valid = true;
			insertionSort();

			cout << "FIRST 10" << endl;
			cout << "ID" << setw(18) << "Name" << setw(21) << "Hourly" << endl;
			cout << "=========================================" << endl;
			for (int i = 0; i < 10; i++)
			{
				cout << setw(16) << left << array[i].getID() << setw(19) << array[i].getName() << setw(21) << array[i].getWage() << endl;
			}

			cout << "LAST 10" << endl;
			cout << "ID" << setw(18) << "Name" << setw(21) << "Hourly" << endl;
			cout << "=========================================" << endl;
			for (int i = size - 1; i > size - 10; i--)
			{
				cout << setw(16) << left << array[i].getID() << setw(19) << array[i].getName() << setw(21) << array[i].getWage() << endl;
			}

			cout << "It took: " << timeSecond << " seconds to complete." << endl;
			cout << "It took: " << timeMinute << " minutes to complete." << endl;
		}
		else
		{
			cout << "Invalid option. Please try again." << endl;
			cout << "Make your selection: ";
		}
	}
}
void Reader::bubbleSort()
{
	Person lower;
	Person higher;
	chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (array[j].getID() > array[j + 1].getID())
			{
				higher = array[j];
				lower = array[j + 1];
				array[j] = lower;
				array[j + 1] = higher;
			}
		}
	}
	chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> time = end - start;
	timeSecond = time.count() / 1000;
	timeMinute = time.count() / 1000 / 60;
}
void Reader::insertionSort()
{
	Person lower;
	Person higher;
	chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();


	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (array[i].getID() < array[j].getID())
			{
				higher = array[j];
				lower = array[i];
				array[j] = lower;
				array[i] = higher;
			}
		}
	}
	chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> time = end - start;
	timeSecond = time.count() / 1000;
	timeMinute = time.count() / 1000 / 60;
}