#include <string>
#include "functions.h"
using namespace std;

int multiply(int first, int second)
{
    if (second == 0 || first == 0)
    {
        return 0;
    }
    else
    {
        return first + multiply(first, second - 1);
    }
}
int sum(int num)
{
    if (num < 10) {
        return num;
    }
    else
    {
        return num % 10 + sum(num / 10); //since c++ rounds down with ints, this will eliminate the last digit
    }
}
int triangle(int num)
{
    if (num == 1)
    {
        return 1;
    }
    else
    {
        return num + triangle(num - 1); //Add the current num, then add the smaller row behind it, then repeat until it reaches one
    }
}
int power(int base, int exponent) {
    if (exponent == 0) //Any number raised to the 0th power is 1
    {
        return 1;
    }
    else
    {
        return base * power(base, exponent - 1); //Keep multiplying the base against itself based on the value of the exponent
    }

}
int countX(string xString)
{
    return countX(xString, 0, 0);
}
int countX(string xString, int i, int count)
{
    if (i == xString.length())
    {
        return count; //End of the line
    }

    if (xString[i] == 'x')
    {
        count++;
    }

    return countX(xString, i + 1, count);
}




