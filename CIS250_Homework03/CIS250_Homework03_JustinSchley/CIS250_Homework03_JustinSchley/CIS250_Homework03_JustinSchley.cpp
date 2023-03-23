//==========================
// Name:       Justin Schley
// Date:          03/22/2023
// Desc: CIS 250 Homework 03
//==========================

#include <iostream>
#include "DoublyList.h"
using namespace std;

int main()
{
    DoublyList* d;
    d = new DoublyList;

    //Appending
    Pet* pet = new Pet(10, "Labrador Retriever", "McPlaceholder", 20);
    d->appendNode(pet);
    pet = new Pet(20, "German Shepherd", "Book", 12);
    d->appendNode(pet);
    pet = new Pet(30, "Golden Retriever", "Psycho", 7);
    d->appendNode(pet);
    pet = new Pet(40, "Bulldog", "Princess", 3);
    d->appendNode(pet);
    pet = new Pet(50, "Poodle", "Brick", 9);
    d->appendNode(pet);

    //Displaying after appending
    cout << "Appending\n";
    d->displayForward();
    d->displayBackward();

    //Inserting
    pet = new Pet(5, "Dolphin", "Shamu", 6);
    d->insertNode(pet);
    pet = new Pet(35, "Corgie", "Lamppost", 37);
    d->insertNode(pet);
    pet = new Pet(55, "Pitbull", "Rosie", 13);
    d->insertNode(pet);

    //Displaying after inserting
    cout << "Inserting\n";
    d->displayForward();
    d->displayBackward();

    ////Deleting
    d->deleteNode(5);
    d->deleteNode(20);
    d->deleteNode(55);

    //Displaying after deleting
    cout << "Deleting\n";
    d->displayForward();
    d->displayBackward();
}



