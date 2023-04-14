#include "Driver.h"

Driver::Driver()
{
	array = new Person[0];
	Reader r[1];
	timeSecond = 0;
	timeMinute = 0;
	size = 0;
}

void Driver::setSize(int s)
{
	size = s;
}

void Driver::writeArray()
{
	array = r.writeArray(size);
}

void Driver::menu()
{
	bool valid = false;
	string select;
	cout << "This program is going to read a very large text file and sort it." << endl;
	cout << "Which sort would you like to perform?" << endl;
	cout << "1. Bubble Sort" << endl;
	cout << "2. Insertion Sort" << endl;
	cout << "Make your selection: ";
	while (valid == false) //Checking for valid input, if not found it will loop to ask for valid input
	{
		cin >> select;

		if (select == "1")
		{
			valid = true;
			bubbleSort();
		}
		else if (select == "2")
		{
			valid = true;
			insertionSort();
		}
		else
		{
			cout << "Invalid option. Please try again." << endl;
			cout << "Make your selection: ";
		}

		if (valid == true)
		{
			cout << "FIRST 10" << endl;
			cout << "ID" << setw(18) << "Name" << setw(21) << "Hourly" << endl;
			cout << "=========================================" << endl;
			for (int i = 0; i < 10; i++)
			{
				cout << setw(16) << left << array[i].getID() << setw(19) << array[i].getName() << array[i].getWage() << endl;
			}

			cout << "LAST 10" << endl;
			cout << setw(16) << "ID" << setw(19) << "Name" << setw(22) << "Hourly" << endl; //I do not know why this is different than FIRST 10, but it works and I'm not touching it
			cout << "=========================================" << endl;
			for (int i = size - 10; i < size; i++)
			{
				cout << setw(16) << left << array[i].getID() << setw(19) << array[i].getName() << array[i].getWage() << endl;
			}

			cout << "It took: " << timeSecond << " seconds to complete." << endl;
			cout << "It took: " << timeMinute << " minutes to complete." << endl;
		}
	}
}

void Driver::bubbleSort()
{
	int counter = 0;
	bool swapped = false;
	Person lower;
	Person higher;
	chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now(); //Starting clock

	for (int i = 0; i < size; i++)
	{
		swapped = false;

		for (int j = 0; j < size - 1; j++)
		{
			if (array[j].getID() > array[j + 1].getID())
			{
				swapped = true;
				higher = array[j];
				lower = array[j + 1];
				array[j] = lower;
				array[j + 1] = higher;
			}
		}

		if (swapped == false) //Breaks out if no items have been swapped over the past 2 iterations
		{
			if (counter == 1)
			{
				break;
			}

			counter++;
		}
	}

	chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now(); //Stopping clock
	chrono::duration<double, milli> time = end - start;
	timeSecond = (time.count() / 1000);
	timeMinute = (time.count() / 1000) / 60;
}

void Driver::insertionSort()
{
	Person lower;
	Person higher;
	chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now(); //Starting clock

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

	chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now(); //Stopping clock
	chrono::duration<double, milli> time = end - start;
	timeSecond = time.count() / 1000;
	timeMinute = time.count() / 1000 / 60;
}