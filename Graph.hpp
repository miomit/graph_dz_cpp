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

		bool isReachesNodeToNode(Node* node1, Node* node2, bool* viewedNodes = nullptr);

		Node** getMaxNodeEdges(unsigned int* node_count);

		Node** getNodes() { return _nodes; }
		unsigned int getNodesSize() { return _nodesSize; }

		Edge** getEdges() { return _edges; }
		unsigned int getEdgesSize() { return _edgesSize; }

		void operator delete[](void* graph);

		Graph& operator+=(const Graph& graph);

		friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
		friend bool operator==(const Graph& graph1, const Graph& graph2);
		friend Graph& operator+=(Graph& graph1, const Graph& graph2);
	private:
		TypeEdge _typeEdge;

		Node** _nodes;
		unsigned int _nodesSize;

		Edge** _edges;
		unsigned int _edgesSize;
	};
}