#pragma once
#include <string>
using namespace std;

class Question
{
private:
	string question;
	string ans1;
	string ans2;
	string ans3;
	string ans4;
	string ans;
	int numberLines;

public:
	Question();
	void initQuestion(); //place qsize inside initQuestion
	int lines();
	Question* newQArray();
	void game(Question*);

	string getQuestion() const;
	string getAns1() const;
	string getAns2() const;
	string getAns3() const;
	string getAns4() const;
	string getAns() const;

	void setQuestion(string);
	void setAns1(string);
	void setAns2(string);
	void setAns3(string);
	void setAns4(string);
	void setAns(string);
};

