#ifndef GAME_H_
#define GAME_H_

#include <ncurses.h>
#include <chrono>
#include <thread>

#include "snake.h"

enum Controls {
	QUIT='q',
	UP='w',
	DOWN='s',
	LEFT='a',
	RIGHT='d'
};

enum State {
	READY,
	RUNNING,
	FINISHED
};

class Game {
	public:
		Game(WINDOW *w);
		void start();
	private:
		static constexpr int FRAMERATE = 25;
		int term_y, term_x;
		void loop();
		void play(char in);
		void render();
		WINDOW *w;
		Snake *snake;
		int score;
		State state;
};

#endif