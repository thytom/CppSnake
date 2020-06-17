#include "node.h"

Node::Node() : empty (true){}
Node::Node(int x, int y) :  empty (false), x (x), y (y){}

bool Node::collidesWith(Node a)
{
	if(this->x == a.getX() && this->y == a.getY())
		return true;
	else
		return false;
}

bool Node::collidesWithAny(std::vector<Node> vec)
{
	for(Node a : vec)
		if(this->collidesWith(a))
			return true;
	return false;
}

void Node::move(int x, int y)
{
	empty = false;
	this->x = x;
	this->y = y;
}

void Node::shift(int dx, int dy)
{
	this->x += dx;
	this->y += dy;
}

int Node::getX()
{
	return x;
}

int Node::getY()
{
	return y;
}

bool Node::isEmpty()
{
	return empty;
}

void Node::makeEmpty()
{
	empty = true;
}
