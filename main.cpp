#include "main.h"

int main()
{
	initscr();
	curs_set(0);
	noecho();
	timeout(0);

	Game g(stdscr);
	g.start();

	endwin();
}
