#include "apple.h"
#include <ncurses.h>
#include <random>

Apple::Apple(int maxX, int maxY, const std::vector<Node> &exclude)
	: Node(APPLECHAR)
{
	newPosition(maxX, maxY, exclude);
}

void Apple::newPosition(int maxX, int maxY, const std::vector<Node> &exclude)
{
	std::uniform_int_distribution<int> distX(0, maxX-1);
	std::uniform_int_distribution<int> distY(0, maxY-1);
	do
	{
		move(distX(generator), distY(generator));
	} while(this->collidesWithAny(exclude, 0, exclude.size()));
}
