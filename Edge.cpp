#include "Edge.hpp"
#include "MySTL.hpp"

gne::Edge::Edge(Node* node1, Node* node2, TypeEdge typeEdge)
{
    this->_node1 = node1;
    this->_node2 = node2;

    this->_typeEdge = typeEdge;

    this->_hashCode = my_stl::two_str_to_hash(node1->getName(), node2->getName());
}

bool gne::Edge::isNodeExist(Node node)
{
    if (node.getHashCode() == this->_node1->getHashCode()) return true;
    if (node.getHashCode() == this->_node2->getHashCode()) return true;

    return false;
}
