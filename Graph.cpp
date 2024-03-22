#include "Graph.hpp"

gne::Graph::Graph(char name[50])
{
	strcpy_s(this->_name, sizeof(this->_name), name);

	this->_nodesSize = 0;
	this->_nodes = nullptr;

	this->_edgesSize = 0;
	this->_edges = nullptr;
}

void gne::Graph::add(Node* node)
{
	for (int i = 0; i < this->_nodesSize; i++)
	{
		if (*this->_nodes[i] == *node) return;
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
}

void gne::Graph::add(Edge* edge)
{
	for (int i = 0; i < this->_edgesSize; i++)
	{
		if (*this->_edges[i] == *edge) return;

		if (this->_edges[i]->getTypeEdge() != edge->getTypeEdge()) 
		{
			if (this->_edges[i]->isNodeExist(*edge->getNode1()) && this->_edges[i]->isNodeExist(*edge->getNode2()))
			{
				return;
			}
		}
	}

	auto newEdges = new Edge *[this->_edgesSize + 1];

	for (int i = 0; i < this->_edgesSize; i++)
	{
		newEdges[i] = this->_edges[i];
	}

	newEdges[this->_edgesSize] = edge;

	if (this->_edges != nullptr) delete[] this->_edges;

	this->_edges = newEdges;
	this->_edgesSize++;
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

std::ostream& gne::operator<<(std::ostream& os, const Graph& graph)
{
	os << "digraph " << graph._name << " {\n";
	
	for (int i = 0; i < graph._nodesSize; i++)
		os << "\t" << *graph._nodes[i] << "\n";

	os << "\n";

	for (int i = 0; i < graph._edgesSize; i++)
		os << "\t" << *graph._edges[i] << "\n";

	os << "}";

	return os;
}