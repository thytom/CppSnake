#ifndef NODE_H_
#define NODE_H_

#include <vector>

class Node {
	public:
		Node();
		Node(int x, int y);
		bool collidesWith(Node a);
		bool collidesWithAny(std::vector<Node> vec);
		void move(int x, int y);
		void shift(int dx, int dy);
		int getX();
		int getY();
		bool isEmpty();
		void makeEmpty();
	private:
		bool empty;
		int x,y;
};

#endif
