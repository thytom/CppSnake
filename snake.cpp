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

void Snake::move()
{
	this->move(d);
}

void Snake::move(Direction d)
{
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

int Snake::length()
{
	return this->body.size();
}

Node Snake::head()
{
	return this->body[0];
}

void Snake::draw(WINDOW *win)
{
	// Remove last tail
	mvwaddch(win, last_y, last_x, ' ');
	int i;
	for(i = 0; i < length(); i++)
		body[i].draw(win);
}
