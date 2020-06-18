#include "game.h"

Game::Game(WINDOW *w) : w(w), score(0)
{
	getmaxyx(w, term_y, term_x);
	snake = new Snake(term_x/2, term_y/2, 5, Right);
	apple = new Apple(term_x, term_y, snake->getBody());

	state = READY;
}

Game::~Game()
{
	delete(snake);
	delete(apple);
}

int Game::start()
{
	state = RUNNING;
	loop();
	return score;
}

void Game::loop()
{
	do
	{
		getmaxyx(w, term_y, term_x);
		play(getch());
		if(apple->collidesWith(snake->head()))
		{
			apple->newPosition(term_x, term_y, snake->getBody());
			snake->grow(1);
			score++;
		}else if(snake->head().collidesWithAny(snake->getTail()))
		{
			state = FINISHED;
		}
		render();
		std::this_thread::sleep_for(std::chrono::nanoseconds(1000000000/FRAMERATE));
	} while(state == RUNNING);
}

void Game::play(char in)
{
	switch(in)
	{
		case QUIT	: state=FINISHED; break;
		case UP 	: snake->moveWrap(term_x, term_y, Up	); break;
		case DOWN 	: snake->moveWrap(term_x, term_y, Down	); break;
		case LEFT 	: snake->moveWrap(term_x, term_y, Left	); break;
		case RIGHT 	: snake->moveWrap(term_x, term_y, Right	); break;
		default : snake->moveWrap(term_x, term_y);
	}
}

void Game::render()
{
	snake->draw(w);
	apple->draw(w);
}


