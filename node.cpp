#include "node.h"

Node::Node() : ch ('#'){}
Node::Node(char ch) : ch (ch){}
Node::Node(int x, int y) : ch('#'), x (x), y (y){}
Node::Node(char ch, int x, int y) : ch(ch), x (x), y (y){}

bool Node::collidesWith(const Node &a) const
{
	if(this->x == a.getX() && this->y == a.getY())
		return true;
	else
		return false;
}

bool Node::collidesWithAny(const std::vector<Node> &vec, int start, int end) const
{
	while(start++<end)
		if(this->collidesWith(vec[start]))
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

int Node::getX() const
{
	return x;
}

int Node::getY() const
{
	return y;
}

void Node::draw(WINDOW *win)
{
	mvwaddch(win, y, x, ch);
}
