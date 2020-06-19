#ifndef APPLE_H_
#define APPLE_H_

#include <vector>
#include <random>
#include "node.h"

class Apple : public Node {
	public:
		Apple(int maxX, int maxY, const std::vector<Node> &exclude);
		void newPosition(int maxX, int maxY, const std::vector<Node> &exclude);
	private:
		std::default_random_engine generator;
		static constexpr char APPLECHAR = '@';
};

#endif
