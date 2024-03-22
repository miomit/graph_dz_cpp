#include <iostream>

#include "Edge.hpp"

namespace gne
{
	class Graph
	{
	public:
		Graph(char name[50]);

		void add(Node* node);
		void add(Edge* edge);

		void remove(Node* node);
		void remove(Edge* edge);

		char* getName() { return _name; }

		Node** getNodes() { return _nodes; }
		unsigned int getNodesSize() { return _nodesSize; }

		Edge** getEdges() { return _edges; }
		unsigned int getEdgesSize() { return _edgesSize; }

		friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
	private:
		char _name[50];

		Node** _nodes;
		unsigned int _nodesSize;

		Edge** _edges;
		unsigned int _edgesSize;
	};
}