#include "apple.h"
#include <ncurses.h>
#include <cstdlib>
#include <ctime>

Apple::Apple(int maxX, int maxY, const std::vector<Node> &exclude)
	: Node(APPLECHAR)
{
	newPosition(maxX, maxY, exclude);
}

void Apple::newPosition(int maxX, int maxY, const std::vector<Node> &exclude)
{
	do
	{
		move(std::rand() % maxX, std::rand() % maxY);
	} while(this->collidesWithAny(exclude, 0, exclude.size()));
}
