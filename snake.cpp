#include "snake.h"


Snake::Snake(int x, int y, int length, Direction d)
{
	body.resize(length);
	body[0].move(x, y);
	this->d = d;
}

void Snake::grow(int amount)
{
	body.resize(body.size() + amount);
}

void Snake::move()
{
	this->move(d);
}

void Snake::move(Direction d)
{
	this->d = d;

	// Find the last node that's still
	int i = length() - 1;
	while(!body[i--].isEmpty());

	for(; i>0; i--)
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
	for(Node a : body)
		a.draw(win);
}
