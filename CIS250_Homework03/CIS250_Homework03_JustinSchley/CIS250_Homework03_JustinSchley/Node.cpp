#include "Node.h"

Node::Node()
{
	pet = new Pet;
	next = nullptr;
	previous = nullptr;
}
Node::Node(Pet* p, Node* n, Node* prev)
{
	pet = p;
	next = n;
	previous = prev;
}
Node* Node::getNext()
{
	return next;
}
Node* Node::getPrevious()
{
	return previous;
}
void Node::setNext(Node* n)
{
	next = n;
}
void Node::setPrevious(Node* prev)
{
	previous = prev;
}
void Node::setPet(Pet* p)
{
	pet = p;
}
Pet* Node::getPet()
{
	return pet;
}