#include "snake.h"

Snake::Snake(int x, int y, int length, Direction d)
{
	body = std::vector<Node>(length, Node(x, y));
	this->d = d;
}

void Snake::grow(int amount)
{
	for(int i = 0; i < amount; i++)
	{
		body.push_back(Node(body.back().getX(), body.back().getY()));
	}
}

bool Snake::valid_move(Direction d)
{
	return !
		(  (this->d == Up	 && d == Down)
		|| (this->d == Down  && d == Up)
		|| (this->d == Left  && d == Right)
		|| (this->d == Right && d == Left));
}

void Snake::move()
{
	this->move(d);
}

void Snake::move(Direction d)
{
	if(!valid_move(d))
		return;

	this->d = d;

	last_x = body[length() - 1].getX();
	last_y = body[length() - 1].getY();

	for(int i = length() - 1; i>0; i--)
	{
		body[i].move(body[i-1].getX(), body[i-1].getY());
	}

	int dx = 0, dy = 0;
	switch(d)
	{
		case Up		: dy = -1; break;
		case Down	: dy =  1; break;
		case Left	: dx = -1; break;
		case Right	: dx =  1; break;
		default: break;
	}

	body[0].shift(dx, dy);
}

void Snake::moveWrap(int maxX, int maxY)
{
	moveWrap(maxX, maxY, this->d);
}

void Snake::moveWrap(int maxX, int maxY, Direction d)
{
	move(d);

	Node* head = &body[0];

	if(head->getX() < 0)
		head->move(maxX - 1, head->getY());
	else if(head->getX() >= maxX)
		head->move(0, head->getY());

	if(head->getY() < 0)
		head->move(head->getX(), maxY - 1);
	else if(head->getY() >= maxY)
		head->move(head->getX(), 0);
}

int Snake::length()
{
	return this->body.size();
}

Node Snake::head()
{
	return this->body[0];
}

std::vector<Node> Snake::getBody()
{
	return this->body;
}

std::vector<Node> Snake::getTail()
{
	return std::vector<Node>(body.begin() + 1, body.end());
}

void Snake::draw(WINDOW *win)
{
	// Remove last tail
	mvwaddch(win, last_y, last_x, ' ');
	int i;
	for(i = 0; i < length(); i++)
		body[i].draw(win);
}
