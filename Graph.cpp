#include "Graph.hpp"
#include "MySTL.hpp"

#include <cstring>

gne::Graph::Graph(TypeEdge typeEdge)
{
	this->_typeEdge = typeEdge;

	this->_nodesSize = 0;
	this->_nodes = nullptr;

	this->_edgesSize = 0;
	this->_edges = nullptr;
}

bool gne::Graph::add(Node* node)
{
	for (int i = 0; i < this->_nodesSize; i++)
	{
		if (*this->_nodes[i] == *node) return false;
	}

	auto newNodes = new Node*[this->_nodesSize + 1];

	for (int i = 0; i < this->_nodesSize; i++)
	{
		newNodes[i] = this->_nodes[i];
	}

	newNodes[this->_nodesSize] = node;

	if (this->_nodes != nullptr) delete[] this->_nodes;

	this->_nodes = newNodes;
	this->_nodesSize++;

	return true;
}

bool gne::Graph::add(Edge* edge)
{
	if (edge->getTypeEdge() != this->_typeEdge) return false;

	for (int i = 0; i < this->_edgesSize; i++)
	{
		if (*this->_edges[i] == *edge) return false;
	}

	auto node1 = findNode(edge->getNode1());
	auto node2 = findNode(edge->getNode2());
	char label[50];

	strcpy(label, edge->getLabel());

	if (node1 == nullptr || node2 == nullptr) return false;

	delete edge;

	edge = new Edge(node1, node2, this->_typeEdge, label);

	auto newEdges = new Edge *[this->_edgesSize + 1];

	for (int i = 0; i < this->_edgesSize; i++)
	{
		newEdges[i] = this->_edges[i];
	}

	newEdges[this->_edgesSize] = edge;

	if (this->_edges != nullptr) delete[] this->_edges;

	this->_edges = newEdges;
	this->_edgesSize++;

	return true;
}

void gne::Graph::remove(Node* node)	
{
	for (int i = 0; i < this->_nodesSize; i++)
	{
		if (*this->_nodes[i] == *node)
		{
			for (int i = 0; i < this->_edgesSize; i++)
			{
				if (this->_edges[i]->isNodeExist(*node))
				{
					this->remove(this->_edges[i]);
					i--;
				}
			}

			auto newNodes = new Node*[this->_nodesSize - 1];
			
			for (int j = 0; j < this->_nodesSize; j++) 
			{
				if (j < i) newNodes[j] = this->_nodes[j];
				if (j > i) newNodes[j - 1] = this->_nodes[j];
			}

			delete this->_nodes[i];
			delete[] this->_nodes;

			this->_nodes = newNodes;
			this->_nodesSize--;

			break;
		}
	}
}

void gne::Graph::remove(Edge* edge)
{
	for (int i = 0; i < this->_edgesSize; i++)
	{
		if (*this->_edges[i] == *edge)
		{
			auto newEdges = new Edge*[this->_edgesSize - 1];

			for (int j = 0; j < this->_edgesSize; j++)
			{
				if (j < i) newEdges[j] = this->_edges[j];
				if (j > i) newEdges[j - 1] = this->_edges[j];
			}

			delete this->_edges[i];
			delete[] this->_edges;

			this->_edges = newEdges;
			this->_edgesSize--;

			break;
		}
	}
}

gne::Node* gne::Graph::findNode(Node* node)
{
	for (int i = 0; i < this->_nodesSize; i++)
	{
		if (*this->_nodes[i] == *node) return this->_nodes[i];
	}
	return nullptr;
}

gne::Edge** gne::Graph::findEdgesByNode(Node* node, unsigned int* count)
{
	auto res = new Edge*[this->_edgesSize];
	int j = 0;

	*count = 0;

	for (int i = 0; i < this->_edgesSize; i++)
	{
		for (;j < this->_edgesSize; j++)
		{
			if (this->_typeEdge == ORIENTED && *this->_edges[j]->getNode1() == *node)
			{
				res[i] = this->_edges[j];
				j++;
				(*count)++;
				break;
			} else if (this->_typeEdge == UNORIENTED && (*this->_edges[j]->getNode1() == *node || *this->_edges[j]->getNode2() == *node))
			{
				res[i] = this->_edges[j];
				j++;
				(*count)++;
				break;
			}
		}
	}

	return res;
}


bool gne::Graph::isReachesNodeToNode(Node* node1, Node* node2, bool* viewedNodes)
{
	if (*node1 == *node2) return true;

	bool isViewedNodesClear = false;

	if (viewedNodes == nullptr)
	{
		viewedNodes = new bool[this->_nodesSize];
		for (int i = 0; i < this->_nodesSize; i++) viewedNodes[i] = false;
		isViewedNodesClear = true;
	}

	for (int i = 0; i < this->_nodesSize; i++)
	{
		if (*this->_nodes[i] == *node1)
		{
			if (!viewedNodes[i]) 
			{
				viewedNodes[i] = true;
				unsigned int count;
				
				auto edges = this->findEdgesByNode(this->_nodes[i], &count);

				for (int k = 0; k < count; k++)
				{
					Node *node;
					if (this->_typeEdge == UNORIENTED)
					{
						node = *edges[k]->getNode1() == *node1 ? edges[k]->getNode2() : edges[k]->getNode1();
					}
					else
					{
						if (!(*edges[k]->getNode1() == *node1)) continue;

						node = edges[k]->getNode2();
					}

					if (this->isReachesNodeToNode(node, node2, viewedNodes))
					{
						delete[] edges;
						if (isViewedNodesClear) delete[] viewedNodes;
						return true;
					}
				}

				delete[] edges;
				return false;

			} 
			else
			{
				if (isViewedNodesClear) delete[] viewedNodes;
				return false;
			}
		}
	}

	if (isViewedNodesClear) delete[] viewedNodes;
	return false;
}

gne::Node** gne::Graph::getMaxNodeEdges(unsigned int* node_count)
{
	unsigned int max_count = 0;
	unsigned int count;
	*node_count = 0;

	for (int i = 0; i < this->_nodesSize; i++)
	{
		auto e = findEdgesByNode(this->_nodes[i], &count);

		if (count == max_count) (*node_count)++;
		else *node_count = 1;

		max_count = my_stl::max(max_count, count);


		delete[] e;
	}

	auto res = new Node*[*node_count];

	int j = 0;

	for (int i = 0; i < *node_count; i++)
	{
		for (; j < this->_nodesSize; j++)
		{
			auto e = findEdgesByNode(this->_nodes[j], &count);

			delete[] e;

			if (count == max_count)
			{
				res[i] = this->_nodes[j];
				j++;
				break;
			}
		}
		
	}

	return res;
}

void gne::Graph::operator delete[](void* graph)
{
		
	for (int i = ((gne::Graph*)graph)->getNodesSize(); i > 0; i--)
	{
		((gne::Graph*)graph)->remove(((gne::Graph*)graph)->getNodes()[0]);
	}
}


std::ostream& gne::operator<<(std::ostream& os, const Graph& graph)
{
	if (graph._typeEdge == ORIENTED) os << "digraph";
	else os << "graph";

	os << " {\n";
	
	for (int i = 0; i < graph._nodesSize; i++)
		os << "\t" << *graph._nodes[i] << "\n";

	os << "\n";

	for (int i = 0; i < graph._edgesSize; i++)
		os << "\t" << *graph._edges[i] << "\n";

	os << "}";

	return os;
}

bool gne::operator==(const Graph& graph1, const Graph& graph2)
{
	if (graph1._nodesSize != graph2._nodesSize) return false;
	if (graph1._edgesSize != graph2._edgesSize) return false;

	for (auto i = 0; i < graph1._nodesSize; i++)
	{
		if (!(*graph1._nodes[i] == *graph2._nodes[i])) return false;
	}

	for (auto i = 0; i < graph1._edgesSize; i++)
	{
		if (!(*graph1._edges[i] == *graph2._edges[i])) return false;
	}

	return true;
}

gne::Graph& gne::operator+=(Graph& graph1, const Graph& graph2)
{
	for (auto i = 0; i < graph2._nodesSize; i++)
	{
		graph1.add(graph2._nodes[i]);
	}

	for (auto i = 0; i < graph2._edgesSize; i++)
	{
		graph1.add(graph2._edges[i]);
	}

	return graph1;
}