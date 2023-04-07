//====================
// Name: Justin Schley
// Date:    04-06-2023
// Desc:   Homework 05
//====================

#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
    int multOne = 5;
    int multTwo = 11;
    int sumInput = 77776;
    int triInput = 12;
    int base = 7;
    int exponent = 5;
    string xInput = "XFjhgxXXHGFxx";

    cout << "GIVEN " << multOne << ", " << multTwo << " MULT: " << multiply(multOne, multTwo) << endl;
    cout << "GIVEN " << sumInput << " NUM-SUM: " << sum(sumInput) << endl;
    cout << "Given " << triInput << " NUM-BLOCKS: " << triangle(triInput) << endl;
    cout << "BASE " << base << " POWER " << exponent << " ANSWER: " << power(base, exponent) << endl;
    cout << "GIVEN " << xInput << " NUM-Xs: " << countX(xInput) << endl;
}