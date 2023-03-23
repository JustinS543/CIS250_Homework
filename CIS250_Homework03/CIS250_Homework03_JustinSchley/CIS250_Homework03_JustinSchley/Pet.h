#pragma once
#include <iostream>
using namespace std;

class Pet
{
private:
    int ID;
    string type;
    string name;
    int age;
public:
    Pet();
    Pet(int, string, string, int);
    void setID(int);
    int getID();
    string getType();
    string getName();
    int getAge();
};

