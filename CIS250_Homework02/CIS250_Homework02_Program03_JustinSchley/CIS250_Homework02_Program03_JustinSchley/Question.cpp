#include "Question.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Question::Question()
{
	initQuestion();
}

void Question::initQuestion()
{
	question = "";
	ans1 = "";
	ans2 = "";
	ans3 = "";
	ans4 = "";
	ans = "";
	numberLines = lines();
}

int Question::lines()
{
	ifstream inputFile;
	string fileName = "questions.txt";
	string lineOfText;
	int i = 0;

	inputFile.open(fileName);

	if (!inputFile)
	{
		cout << "Error: Could not open file" << endl;
	}

	if (inputFile.is_open())
	{
		while (!inputFile.eof())
		{
			getline(inputFile, lineOfText);
			i++;
		}
	}
	inputFile.close();
	return i;
}

Question* Question::newQArray()
{
	Question* qArray = new Question[numberLines];
	ifstream inputFile;
	string fileName = "questions.txt";
	string lineOfText;
	char delim = ',';
	int commaPos;
	int i = 0;

	inputFile.open(fileName);

	if (inputFile)
	{
		while (getline(inputFile, lineOfText))
		{
			commaPos = lineOfText.find(delim);
			qArray[i].setQuestion(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);

			commaPos = lineOfText.find(delim);
			qArray[i].setAns1(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);

			commaPos = lineOfText.find(delim);
			qArray[i].setAns2(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);

			commaPos = lineOfText.find(delim);
			qArray[i].setAns3(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);

			commaPos = lineOfText.find(delim);
			qArray[i].setAns4(lineOfText.substr(0, commaPos));
			lineOfText = lineOfText.substr(commaPos + 1);

			commaPos = lineOfText.find(delim);
			qArray[i].setAns(lineOfText);

			i++;
		}
		inputFile.close();
	}
	return qArray;
}

void Question::game(Question* qArray)
{
	int playerTurn = 0;
	int player1Points = 0;
	int player2Points = 0;
	int pointsOver;

	cout << "Welcome all to the SCP trivia contest!" << endl;
	cout << "Today, we will be testing your knowledge on the SCP Universe." << endl;
	cout << "We will need two players for this game, Player 1 & Player 2." << endl;
	cout << "Will both contestants please proceed to the keyboard!" << endl << endl;

	for (int i = 0; i < numberLines; i++)
	{
		string enteredAns;
		int player;

		cout << "Player ";
		if (playerTurn % 2 == 0)
		{
			player = 1;
			cout << player << endl;
		}
		else
		{
			player = 2;
			cout << player << endl;
		}
		
		cout << "Your Question Is" << ": ";
		cout << qArray[i].getQuestion() << endl;
		cout << "1. " << qArray[i].getAns1() << endl;
		cout << "2. " << qArray[i].getAns2() << endl;
		cout << "3. " << qArray[i].getAns3() << endl;
		cout << "4. " << qArray[i].getAns4() << endl;
		cout << "Answer: ";
		getline(cin, enteredAns);

		if (enteredAns == qArray[i].getAns())
		{
			if (i != numberLines - 1)
			{
				if (player == 1)
				{
					player1Points++;
				}
				else
				{
					player2Points++;
				}

				cout << "Congratulations Player " << player << "! That is the correct answer. Onto the next round!" << endl << endl;
			}
			else
			{
				if (player == 1)
				{
					player1Points++;
				}
				else
				{
					player2Points++;
				}

				cout << "Congratulations Player " << player << "! That is the correct answer." << endl << endl;
			}
			
		}
		else
		{
			if (i != numberLines - 1)
			{
				cout << "Sorry, that was the incorrect answer. The correct answer is: " << qArray[i].getAns() << ". Onto the next round!" << endl << endl;
			}
			else
			{
				cout << "Sorry, that was the incorrect answer. The correct answer is: " << qArray[i].getAns() << "." << endl << endl;
			}
			
		}
		playerTurn++;
	}

	cout << "Final Score" << endl;
	cout << "-----------" << endl;
	cout << "Player 1 points: " << player1Points << endl;
	cout << "Player 2 points: " << player2Points << endl << endl;

	if (player1Points > player2Points)
	{
		pointsOver = player1Points - player2Points;

		cout << "Congratulations Player 1! You have won the trivia contest by ";

		if (pointsOver == 1)
		{
			cout << pointsOver << " point!" << endl;
		}
		else
		{
			cout << "points!" << endl;
		}

	}
	if (player2Points > player1Points)
	{
		pointsOver = player2Points - player1Points;

		cout << "Congratulations Player 1! You have won the trivia contest by ";

		if (pointsOver == 1)
		{
			cout << pointsOver << " point!" << endl;
		}
		else
		{
			cout << "points!" << endl;
		}
	}
	if(player1Points == player2Points)
	{
		if (player1Points == 5)
		{
			cout << "It looks like this one is a tie! Both players are very knowledgable about the SCP Foundation." << endl;
		}
		if (player1Points == 4)
		{
			cout << "It looks like this one is a tie! Both players are pretty knowledgable about the SCP Foundation." << endl;
		}
		if (player1Points == 3)
		{
			cout << "It looks like this one is a tie! Both players are fairly knowledgable about the SCP Foundation." << endl;
		}
		if (player1Points == 2)
		{
			cout << "It looks like this one is a tie! Both of you may need some brushing up on the SCP Foundation." << endl;
		}
		if (player1Points == 1)
		{
			cout << "It looks like this one is a tie. Each of you only got 1 point each? A tad disappointing..." << endl;
		}
		if (player1Points == 0)
		{
			cout << "Welp, you managed to get every single answer wrong between both of you." << endl;
			cout << "Statistically, it doesn't add up. Even mashing one key the entire time should've given one of you at least one point." << endl;
			
		}
	}

}

string Question::getQuestion() const
{
	return question;
}

string Question::getAns1() const
{
	return ans1;
}

string Question::getAns2() const
{
	return ans2;
}

string Question::getAns3() const
{
	return ans3;
}

string Question::getAns4() const
{
	return ans4;
}

string Question::getAns() const
{
	return ans;
}

void Question::setQuestion(string q)
{
	question = q;
}

void Question::setAns1(string a1)
{
	ans1 = a1;
}

void Question::setAns2(string a2)
{
	ans2 = a2;
}

void Question::setAns3(string a3)
{
	ans3 = a3;
}

void Question::setAns4(string a4)
{
	ans4 = a4;
}

void Question::setAns(string a)
{
	ans = a;
}