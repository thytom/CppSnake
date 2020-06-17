#ifndef NODE_H_
#define NODE_H_

#include <ncurses.h>
#include <vector>

class Node {
	public:
		Node();
		Node(char ch);
		Node(int x, int y);
		Node(char ch, int x, int y);
		bool collidesWith(Node a);
		bool collidesWithAny(std::vector<Node> vec);
		void move(int x, int y);
		void shift(int dx, int dy);
		int getX();
		int getY();
		void draw(WINDOW *win);
	private:
		char ch;
		int x,y;
};

#endif
