#include <ncurses.h>
#include <iostream>

#include "game.h"

int main()
{
	initscr();
	curs_set(0);
	noecho();
	timeout(0);

	Game g(stdscr);
	int score = g.start();

	endwin();
	std::cout << "Game Over! Final Score: " << score << std::endl;
}
