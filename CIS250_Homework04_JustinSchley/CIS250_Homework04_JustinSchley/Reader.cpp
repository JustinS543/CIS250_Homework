#include "Reader.h"

Reader::Reader()
{
	nameTemp = "";
	dumpTemp = "";
	wageTemp = 0;
	IDTemp = 0;
	deptIDTemp = 0;
}
Person* Reader::writeArray(int s)
{
	//size = s;
	Person* array = new Person[s];
	ifstream inputFile;
	string fileName = "CensusSmall.txt";
	string lineOfText;
	char delim = ' ';
	int spacePos;
	int i = 0;

	inputFile.open(fileName);

	if (inputFile)
	{
		while (getline(inputFile, lineOfText))
		{
			spacePos = lineOfText.find(delim); //find the next space
			nameTemp = lineOfText.substr(0, spacePos); //assign the data between the beginning to the space to the variable
			lineOfText = lineOfText.substr(spacePos + 1); //eliminate the data just read in
			while (lineOfText.at(0) == ' ') //eliminate all spaces leading up to the next data
			{
				lineOfText = lineOfText.substr(1);
			}

			spacePos = lineOfText.find(delim);
			dumpTemp = lineOfText.substr(0, spacePos); //get rid of unwanted data
			lineOfText = lineOfText.substr(spacePos + 1);
			while (lineOfText.at(0) == ' ')
			{
				lineOfText = lineOfText.substr(1);
			}

			spacePos = lineOfText.find(delim);
			wageTemp = stod(lineOfText.substr(0, spacePos));
			lineOfText = lineOfText.substr(spacePos + 1);
			while (lineOfText.at(0) == ' ')
			{
				lineOfText = lineOfText.substr(1);
			}

			spacePos = lineOfText.find(delim);
			IDTemp = stoi(lineOfText.substr(0, spacePos));
			lineOfText = lineOfText.substr(spacePos + 1);
			while (lineOfText.at(0) == ' ')
			{
				lineOfText = lineOfText.substr(1);
			}

			spacePos = lineOfText.find(delim);
			deptIDTemp = stoi(lineOfText);

			array[i] = Person(nameTemp, wageTemp, IDTemp, deptIDTemp); //pass all temp variables to Person in array

			i++;
		}
		inputFile.close();
	}
	return array; //returns the new array of Person type
}