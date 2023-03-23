#include "DoublyList.h"

void DoublyList::appendNode(Pet* pet)
{
	Node* node;
	node = new Node;
	node->setPet(pet);

	if (head == nullptr) //Tests for no list created
	{
		head = node;
	}
	else if(tail == nullptr) //Tests for only 1 item in list
	{
		tail = node;
		head->setNext(tail);
		tail->setPrevious(head);
	}
	else //Assign everything else to the end
	{
		tail->setNext(node);
		node->setPrevious(tail);
		tail = node;
	}
}
void DoublyList::insertNode(Pet* pet) 
{
	Node* node = new Node;
	node->setPet(pet);
	Node* tmpPtr = head; //tmpPtr is the temporary pointer to cycle through the list and find a matching ID, starts at head
	Node* takeItBackNowYall = tmpPtr; //Using previous node to insert if the matching node is the tail or in the middle
	bool found = false; //Flips if node is found, then ends while loop

	while (tmpPtr != nullptr && found == false)
	{
		
		if (node->getPet()->getID() < head->getPet()->getID() && found == false) //Position found before head
		{
			found = true;
			node->setNext(head);
			head->setPrevious(node);
			head = node;
		}
		else if (tmpPtr != head && node->getPet()->getID() < tmpPtr->getPet()->getID()) //Position found between head and tail
		{
			found = true;
			if (tmpPtr == tail) 
			{
				takeItBackNowYall = tail->getPrevious();
				node->setPrevious(takeItBackNowYall);
				takeItBackNowYall->setNext(node);
				node->setNext(tail);
				tail->setPrevious(node);
			}
			else
			{
				takeItBackNowYall = tmpPtr->getPrevious(); //This hurt the most to get right
				takeItBackNowYall->setNext(node);
				node->setPrevious(takeItBackNowYall);
				node->setNext(tmpPtr);
				tmpPtr->setPrevious(node);
			}
		}
		else if (node->getPet()->getID() > tail->getPet()->getID() && found == false) //position found after tail
		{
			found = true;
			node->setPrevious(tail);
			tail->setNext(node);
			tail = node;
		}
		tmpPtr = tmpPtr->getNext();
	}
}
void DoublyList::deleteNode(int id)
{
	Node* tmpPtr = head; //tmpPtr is the temporary pointer to cycle through the list and find a matching ID
	Node* takeItBackNowYall; //using previous node to insert if the matching node is the tail
	bool found = false; //Flips if node is found, then ends while loop

	while (tmpPtr != nullptr && found == false)
	{
		if (tmpPtr->getPet()->getID() == id)
		{
			if (tmpPtr == head) //If node is found at head
			{
				head = tmpPtr->getNext();
				head->setPrevious(nullptr);
			}
			else if (tmpPtr->getPet()->getID() > head->getPet()->getID() && tmpPtr->getPet()->getID() < tail->getPet()->getID()) //If the node is in the middle of the list
			{
				takeItBackNowYall = tmpPtr->getPrevious();
				tmpPtr = tmpPtr->getNext();
				takeItBackNowYall->setNext(tmpPtr);
				tmpPtr->setPrevious(takeItBackNowYall);
			}
			else if (tmpPtr == tail) //If node is found at tail
			{
				tail = tmpPtr->getPrevious();
				tail->setNext(nullptr);
			}
			
			found = true;
		}
		tmpPtr = tmpPtr->getNext();
	}
}
void DoublyList::displayForward()
{
	Node* disPtr = head;

	cout << "Forward Display\n";
	cout << "---------------\n";

	while (disPtr != nullptr)
	{
		cout << "ID:   " << disPtr->getPet()->getID() << endl;
		cout << "Name: " << disPtr->getPet()->getName() << endl;
		cout << "Type: " << disPtr->getPet()->getType() << endl;
		cout << "Age:  " << disPtr->getPet()->getAge() << endl << endl;
		disPtr = disPtr->getNext();
	}
}
void DoublyList::displayBackward()
{
	Node* disPtr = tail;

	cout << "Backward Display\n";
	cout << "----------------\n";

	while (disPtr != nullptr)
	{
		cout << "ID:   " << disPtr->getPet()->getID() << endl;
		cout << "Name: " << disPtr->getPet()->getName() << endl;
		cout << "Type: " << disPtr->getPet()->getType() << endl;
		cout << "Age:  " << disPtr->getPet()->getAge() << endl << endl;
		disPtr = disPtr->getPrevious();
	}
}