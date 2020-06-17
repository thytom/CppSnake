#ifndef SNAKE_H_
#define SNAKE_H_

#include <vector>
#include <optional>
#include <ncurses.h>

#include "node.h"

enum Direction {
	Up,
	Down,
	Left,
	Right
};

class Snake {
	public:
		Snake(int x, int y, int length, Direction d);
		void grow(int amount);
		void move();
		void move(Direction d);
		int length();
		Node head();
		std::vector<Node> getBody();
		void draw(WINDOW *win);
	private:
		bool valid_move(Direction d);
		Direction d;
		int last_x;
		int last_y;
		std::vector<Node> body;
};

#endif
