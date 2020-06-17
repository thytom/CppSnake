#include "main.h"

int main()
{
	initscr();
	curs_set(0);
	noecho();
	timeout(0);

	int term_y, term_x;
	char input;

	getmaxyx(stdscr, term_y, term_x);

	Snake *s = new Snake(term_x/2, term_y/2, 10, Right);

	while((input = getch()) != 'q')
	{
		clear();

		s->move();
		s->draw(stdscr);
		std::this_thread::sleep_for(std::chrono::nanoseconds(1000000000/25));
	}

	endwin();
}
