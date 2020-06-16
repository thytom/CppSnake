#ifndef NODE_H_
#define NODE_H_

class Node {
	public:
		Node(int x, int y);
		static bool collide(Node a, Node b);
		static bool collide(std::vector<Node> a, Node b);
		void move(int x, int y);
		bool isEmpty();
		void setEmpty(bool);
	private:
		bool empty;
		int x,y;
};

#endif
