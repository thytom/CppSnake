#include "main.h"

int main()
{
	std::srand(std::time(0));

	initscr();
	curs_set(0);
	noecho();
	timeout(0);

	Game g(stdscr);
	g.start();

	endwin();
}
