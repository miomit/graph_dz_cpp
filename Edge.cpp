#include "Edge.hpp"
#include "MySTL.hpp"

#include <cstringt.h>

gne::Edge::Edge(Node* node1, Node* node2, TypeEdge typeEdge, char label[50])
{
    this->_node1 = node1;
    this->_node2 = node2;

    this->_typeEdge = typeEdge;

    strcpy_s(this->_label, sizeof(this->_label), label);

    this->_hashCode = my_stl::two_str_to_hash(node1->getName(), node2->getName());
}

bool gne::Edge::isNodeExist(Node node)
{
    if (node.getHashCode() == this->_node1->getHashCode()) return true;
    if (node.getHashCode() == this->_node2->getHashCode()) return true;

    return false;
}

void gne::Edge::setTypeEdge(TypeEdge typeEdge)
{
    this->_typeEdge = typeEdge;
}

std::ostream& gne::operator<<(std::ostream& os, const Edge& edge)
{
    os << edge._node1->getName();

    if (edge._typeEdge == UNORIENTED) os << " - ";
    else os << " -> ";

    os << edge._node2->getName();

    os << " [label=\"" << edge._label << "\"]";

    return os;
}
