//==========================
// Name:       Justin Schley
// Date:          03/22/2023
// Desc: CIS 250 Homework 03
//==========================

The program is designed to house a list of pets. It allows appending, inserting, and deleting pets by utilizing a node for each pet.

There are 3 classes utilized in this program:
1. DoublyList
2. Node
3. Pet

##DoublyList

Doublylist houses the list of nodes. 

The private values stored are:

1. head (Node)
2. tail (Node)

These values store the head and tail of the doubly linked list. These are accessed through appendNode, insertNode, and deleteNode.

DoublyList has 5 public functions:

void appendNode(Pet*)
void insertNode(Pet*)
void deleteNode(int)
void displayForward()
void displayBackward()

These functions allow appending, inserting, and deleting of nodes. It also allows forward and backward printing of the list to the console. appendNode and insertNode require a Pet object to be passed to it. deleteNode only requires the ID of the node to be deleted.

##Node

Node creates a node object for use in the list. 

The private values stored are:

1. pet (Pet)
2. next (Node)
3. previous (Node)

These values store the pet object assigned to the node, in addition to the next and previous node. These are accessed through setNext, setPrevious, and setPet.

Node has 8 public functions:

1. Node()
2. Node(Pet*, Node*, Node*)
3. Pet* getPet()
4. Node* getNext()
5. Node* getPrevious()
6. void setNext(Node*)
7. void setPrevious(Node*)
8. void setPet(Pet*)

Node is a constructor, creating a blank slate of pet, next, and previous. 
The overloaded Node constructor takes a Pet object and 2 nodes (one for next, another for previous).
getPet returns the Pet object stored within the node. 
getNext returns a pointer to the next node.
getPrevious returns a pointer to the previous node.
setNext takes a Node object to set the next node in the list.
setPrevious takes a node object to set the previous node in the list.
setPet takes a Pet object to set the pet in the node.

##Pet

Pet creates a pet object for use in a node. The private values are:

1. ID
2. type
3. name
4. age

These values store the ID, name, type, and age of the pet.

Pet has 7 public functions:

1. Pet()
2. Pet(int, string, string, int)
3. void setID(int)
4. int getID()
5. string getType()
6. string getName()
7. int getAge()

Pet is a constructor, creating a blank slate of ID, type, name, and age.
The overloaded Pet constructor takes a Pet object and assigns the values given to the private values.
setID allows setting the ID for the pet object.
getID returns the int value ID.
getType returns the string value of type.
getName returns the string value of name.
getAge returns the int value of age.

##List Creation

To create a new list, include the following code:

DoublyList* {list name} = new DoublyList;

To add an item to the list, first create a Pet object through the following code:

Pet* pet = new Pet({int ID}, {string type}, {string name}, {int age});

After the Pet object is created, you can choose to append, insert, or delete through the following code:

{list name}->appendNode(pet);
{list name}->insertNode(pet);
{list name}->deleteNode({int ID});

There are 2 options to display the list:

{list name}->displayForward();
{list name}->displayBackward();

Both options will display the list; displayForward will start at the lowest value ID, displayBackward starting at the highest value ID.