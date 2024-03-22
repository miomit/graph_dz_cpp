#include <iostream>

#include "Edge.hpp"

namespace gne
{
	class Graph
	{
	public:
		Graph(char name[50]);

		void add(Node* node);

		char* getName() { return _name; }
		unsigned int getNodesSize() { return _nodesSize; }

		friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
	private:
		char _name[50];

		Node** _nodes{nullptr};
		unsigned int _nodesSize;
	};
}