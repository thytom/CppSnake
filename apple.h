#ifndef APPLE_H_
#define APPLE_H_

#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "node.h"

class Apple : public Node {
	public:
		Apple(int maxX, int maxY, std::vector<Node> exclude);
		void newPosition(int maxX, int maxY, std::vector<Node> exclude);
	private:
		static constexpr char APPLECHAR = '@';
};

#endif
