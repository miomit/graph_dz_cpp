#include <iostream>

#include "Edge.hpp"

namespace gne
{
	class Graph
	{
	public:
		Graph(TypeEdge typeEdge);

		bool add(Node* node);
		bool add(Edge* edge);

		void remove(Node* node);
		void remove(Edge* edge);

		Node* findNode(Node* node);
		Edge** findEdgesByNode(Node* node, unsigned int* count);

		Node** getMaxNodeEdges(unsigned int* node_count);

		Node** getNodes() { return _nodes; }
		unsigned int getNodesSize() { return _nodesSize; }

		Edge** getEdges() { return _edges; }
		unsigned int getEdgesSize() { return _edgesSize; }

		void operator delete[](void* graph);

		friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
	private:
		TypeEdge _typeEdge;

		Node** _nodes;
		unsigned int _nodesSize;

		Edge** _edges;
		unsigned int _edgesSize;
	};
}