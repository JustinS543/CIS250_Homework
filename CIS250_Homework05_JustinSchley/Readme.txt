//====================
// Name: Justin Schley
// Date:    04-06-2023
// Desc:   Homework 05
//====================

This program contains 5 functions & 1 overloaded function:

1. multiply
2. sum
3. triangle
4. power
5. countX

**Multiply

The multiply function will first check if either of the values are equal to zero. Since either value being zero would return zero, to save computational time, the function returns zero. If both are greater than zero, it will take the first value and add recursively to itself. The number of times it is added recursively is determined by the second number.

**Sum

The sum function first checks if the value is less than ten. If the number is less than ten, the sum will be the value passed and will return the original value. If it is greater than ten, the function will perform modulus of ten with the value (returning the last digit of the number). This value will then be added recursively to itself divided by ten (since c++ rounds down, it will eliminate the last digit).

**Triangle

The triangle function first checks to see if the value is equal to one. If the value is one, it will return itself since one would indicate there are no other layers. If the value is greater than one, it will recursively add itself to the triangle function, but subtracting one from the value. This will add all of the values until the function reaches the value of one, which will then return up the total value of the triangle.

**Power

The power function first checks if the exponent is zero. Since any number raised to the zeroth power is one, it will return one. Otherwise, the function will multiply the base value recursively, using the exponent value to determine how many times to recursively multiply. To count down to zero, it will subtract one each time the function is recursively called.

**CountX

The countX function only needs to be passed a string. From there, an overloaded function will take over, passing the string, an int for iterations, and a counter. The overloaded function will check each function call to see if the value of i equals the string length. Untill then, it will use i as a position in the string and check for the character 'x'. If 'x' is found, it will increment the count variable by one. Once i is equal to the string length, it will return the count of how many 'x''s were found.

