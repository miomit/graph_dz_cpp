#include <iostream>

#include "Edge.hpp"

namespace gne
{
	class Graph
	{
	public:
		Graph(TypeEdge typeEdge);

		void add(Node* node);
		void add(Edge* edge);

		void remove(Node* node);
		void remove(Edge* edge);

		Node** getNodes() { return _nodes; }
		unsigned int getNodesSize() { return _nodesSize; }

		Edge** getEdges() { return _edges; }
		unsigned int getEdgesSize() { return _edgesSize; }

		friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
	private:
		TypeEdge _typeEdge;

		Node** _nodes;
		unsigned int _nodesSize;

		Edge** _edges;
		unsigned int _edgesSize;
	};
}