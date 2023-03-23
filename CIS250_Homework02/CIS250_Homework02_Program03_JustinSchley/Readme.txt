//==================================================
// Name:                               Justin Schley
// Date:                                   2/28/2023
// Desc: CIS250 Homework 2 - Program 3 (Trivia Game)
//==================================================

This program reads a text document (questions.txt), parses through the included data,
and uses the class Question to create an array of Question objects. The program then plays
a trivia game designed for two players, asking 5 questions each, and displaying different 
results if the two opponents tie or one of them wins.

The Question class includes functions to read through the text file, create a new object 
array, and get/set each question, possible answers, and the correct answer. the game() 
function is the heart of the program, displaying an introduction, each question, and 
parsing through each answer the players give. 