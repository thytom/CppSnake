#include "snake.h"


Snake::Snake(int x, int y, int length, Direction d)
{
	body.resize(length + 1);
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
	int i = length();
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
	return this->body.size() - 1;
}

Node Snake::head()
{
	return this->body[0];
}

void Snake::draw(WINDOW *win)
{
	int i;
	for(i = 0; i <= length(); i++)
		body[i].draw(win);
}
