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
		bool collidesWith(const Node &a) const;
		bool collidesWithAny(const std::vector<Node> &vec, int start, int end) const;
		void move(int x, int y);
		void shift(int dx, int dy);
		int getX() const;
		int getY() const;
		void draw(WINDOW *win);
	private:
		char ch;
		int x,y;
};

#endif
