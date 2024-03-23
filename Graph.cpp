#include "Graph.hpp"

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
	auto label = edge->getLabel();

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