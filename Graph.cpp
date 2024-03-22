#include "Graph.hpp"

gne::Graph::Graph(char name[50])
{
	strcpy_s(this->_name, sizeof(this->_name), name);
	this->_nodesSize = 0;
	this->_nodes = nullptr;
}

void gne::Graph::add(Node* node)
{
	for (int i = 0; i < this->_nodesSize; i++)
	{
		if (*this->_nodes[i] == *node) return;
	}

	auto newNodes = new Node*[this->_nodesSize + 1];

	for (int i = 0; i < this->_nodesSize; i++) {
		newNodes[i] = this->_nodes[i];
	}

	newNodes[this->_nodesSize] = node;

	if (this->_nodes != nullptr) delete[] this->_nodes;

	this->_nodes = newNodes;
	this->_nodesSize++;
}

void gne::Graph::remove(Node* node)
{
	for (int i = 0; i < this->_nodesSize; i++)
	{
		if (*this->_nodes[i] == *node)
		{
			auto newNodes = new Node*[this->_nodesSize - 1];
			
			for (int j = 0; j < this->_nodesSize; j++) {
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
