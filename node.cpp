#include "node.h"

Node::Node() : ch ('#'){}
Node::Node(int x, int y) : ch('#'), x (x), y (y){}
Node::Node(char ch, int x, int y) : ch(ch), x (x), y (y){}

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

void Node::draw(WINDOW *win)
{
	mvwaddch(win, y, x, ch);
}
