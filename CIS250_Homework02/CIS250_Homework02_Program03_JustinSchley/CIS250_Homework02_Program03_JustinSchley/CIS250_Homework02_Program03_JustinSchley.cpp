//==================================================
// Name:                               Justin Schley
// Date:                                   2/28/2023
// Desc: CIS250 Homework 2 - Program 3 (Trivia Game)
//==================================================

#include <iostream>
#include "Question.h"

int main()
{
    Question baseQuestion;
    Question* qArray = baseQuestion.newQArray();
    qArray->game(qArray);
}