#pragma once
#include "Pet.h"

class Node
{
private:
    Pet* pet;
    Node* next;
    Node* previous;
public:
    Node();
    Node(Pet*, Node*, Node*);
    Pet* getPet();
    Node* getNext();
    Node* getPrevious();
    void setNext(Node*);
    void setPrevious(Node*);
    void setPet(Pet*);
};

