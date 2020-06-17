#include "main.h"

int main()
{
	initscr();
	curs_set(0);

	int term_y, term_x;

	getmaxyx(stdscr, term_y, term_x);

	Snake *s = new Snake(term_x/2, term_y/2, 10, Right);

	s->draw(stdscr);

	getch();

	endwin();
}
