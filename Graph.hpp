#include <iostream>

#include "Edge.hpp"

namespace gne
{
	class Graph
	{
	public:
		Graph(char name[50]);

		void add(Node* node);

		void remove(Node* node);

		char* getName() { return _name; }
		Node** getNodes() { return _nodes; }
		unsigned int getNodesSize() { return _nodesSize; }

		friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
	private:
		char _name[50];

		Node** _nodes;
		unsigned int _nodesSize;
	};
}