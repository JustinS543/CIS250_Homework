#include <iostream>
#include <string>
#include "Reader.h"
#include "Person.h"

using namespace std;

int main()
{
    int size = 577;
    Reader r;
    r.writeArray(size);
    r.display();
}

