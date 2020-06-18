#include "main.h"

int main()
{
	std::srand(std::time(0));

	initscr();
	curs_set(0);
	noecho();
	timeout(0);

	Game g(stdscr);
	int score = g.start();

	endwin();
	std::cout << "Game Over! Final Score: " << score << std::endl;
}
