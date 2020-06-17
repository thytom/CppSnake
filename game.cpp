#include "game.h"

Game::Game(WINDOW *w) : w(w), score(0)
{
	getmaxyx(w, term_y, term_x);
	snake = new Snake(term_x/2, term_y/2, 10, Right);

	state = READY;
}

void Game::start()
{
	state = RUNNING;
	loop();
}

void Game::loop()
{
	do
	{
		getmaxyx(w, term_y, term_x);
		play(getch());
		render();
		std::this_thread::sleep_for(std::chrono::nanoseconds(1000000000/FRAMERATE));
	} while(state == RUNNING);
}

void Game::play(char in)
{
	switch(in)
	{
		case QUIT	: state=FINISHED; break;
		case UP 	: snake->move(Up	); break;
		case DOWN 	: snake->move(Down	); break;
		case LEFT 	: snake->move(Left	); break;
		case RIGHT 	: snake->move(Right	); break;
		default : snake->move();
	}
}

void Game::render()
{
	snake->draw(w);
}


